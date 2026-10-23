# Zulip announcer

A simple workflow:

1. When an nLab edit should be announced, a tiny bit of Ruby code creates a new
   row in the table `nlab_zulip_outbox`. This is just an `INSERT` statement and
   works even in case the nForum is down.

2. In the background, the announcement bot wakes up and processes all entries
   in the `nlab_zulip_outbox` table. Entries which are successfully transmitted
   to Zulip are removed from the table.

The Ruby code triggers the run of the announcement bot by creating the file
`tmp/zulip_announcer_wake`, which is monitored by systemd.

Matching nLab author names to Zulip accounts is done using Zulip's "nLab name"
profile field.


## Setup

These steps assume the nForum has already been imported into Zulip with
`converter/post_import.py` from the migration tools, which writes `nforum_ids.json`.

1. **Tables:** `mysql nlab < script/src/zulip_announcer/schema.sql`.

   **Python packages:** as `nlab`, `python3 -m pip install --user zulip` (Zulip's API client).

2. **Bot:** in Zulip, as an administrator, go to *Personal settings → Bots → Add a new bot*.
   Choose type "Generic", name "nLab edit announcer". Then, on the Zulip server:

   ```sh
   manage.py change_user_role <bot email> moderator        # to rename old topics
   manage.py change_user_role <bot email> can_forge_sender # to post as the authors
   ```

3. **Configuration:** create `config/zulip_announcer.env`, owned by `nlab` with mode 600.
   `config/environ` isn't used because its URLs are outdated.

   ```sh
   NLAB_DATABASE_NAME=nlab
   NLAB_DATABASE_USER=nlab
   NLAB_DATABASE_PASSWORD=...           # as in config/environment_variables.rb
   NLAB_LOG_DIRECTORY=log
   NLAB_URL=https://ncatlab.org/
   NFORUM_URL=https://nforum.ncatlab.org/
   ZULIP_EMAIL=...                      # the bot's email, from the Bots page
   ZULIP_API_KEY=...
   # Only if Zulip isn't reachable at NFORUM_URL, e.g. through a tunnel. The host name must be
   # NFORUM_URL's (map it to the tunnel in /etc/hosts), because it selects the organization.
   # ZULIP_SITE=http://nforum.ncatlab.org:8080/
   ```

   In `config/environment_variables_static.rb`, set `NFORUM_TECHNICAL_MATTERS_URL` to the
   "nLab Technical Matters" channel.

4. **Seed** the channels and topics from `nforum_ids.json` and the nForum's tables, which are
   still in the database:

   ```sh
   set -a; . config/zulip_announcer.env; set +a
   python3 script/src/zulip_announcer/seed.py --ids nforum_ids.json
   ```

5. **systemd units**, in `/etc/systemd/system/`, then
   `systemctl enable --now nlab-zulip-announcer.path nlab-zulip-announcer.timer`.

   `nlab-zulip-announcer.service`:

   ```ini
   [Unit]
   Description=nLab edit announcements on the nForum (Zulip)
   After=mariadb.service
   # Started on every edit: no start limit (hitting it would stop the .path unit).
   StartLimitIntervalSec=0

   [Service]
   Type=oneshot
   User=nlab
   Group=nlab
   WorkingDirectory=/home/nlab/www/nlab
   EnvironmentFile=/home/nlab/www/nlab/config/zulip_announcer.env
   ExecStart=/usr/bin/python3 script/src/zulip_announcer/zulip_announcer.py
   ```

   `nlab-zulip-announcer.path`, which starts the service while the wake file exists:

   ```ini
   [Unit]
   Description=Send nLab edit announcements when the nLab has queued one

   [Path]
   PathExists=/home/nlab/www/nlab/tmp/zulip_announcer_wake

   [Install]
   WantedBy=multi-user.target
   ```

   `nlab-zulip-announcer.timer`, which retries failed announcements:

   ```ini
   [Unit]
   Description=Retry nLab edit announcements that failed

   [Timer]
   OnCalendar=*:0/5

   [Install]
   WantedBy=timers.target
   ```


## Operation

```sh
# list pending announcements, with their errors
mysql nlab -e "SELECT id, created_at, page_name, author, last_error FROM nlab_zulip_outbox ORDER BY id"
```

To send the pending announcements right away, `systemctl start nlab-zulip-announcer`. (Don't
run `zulip_announcer.py` by hand while the units are active: two runs at the same time
would post everything twice.) To drop an announcement, delete its row from
`nlab_zulip_outbox`.

The log is `log/zulip_announcer.log`, and also goes to the journal
(`journalctl -u nlab-zulip-announcer`).
