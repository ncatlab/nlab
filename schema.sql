/*M!999999\- enable the sandbox mode */ 
-- MariaDB dump 10.19  Distrib 10.5.27-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: nlab
-- ------------------------------------------------------
-- Server version	10.5.27-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `author_revisions`
--

DROP TABLE IF EXISTS `author_revisions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `author_revisions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `author` varchar(60) DEFAULT NULL,
  `revision_id` int(11) NOT NULL DEFAULT 0,
  `page_id` int(11) NOT NULL DEFAULT 0,
  `web_id` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `index_author_revisions_on_author` (`author`)
) ENGINE=InnoDB AUTO_INCREMENT=131 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_Category`
--

DROP TABLE IF EXISTS `mathforge_nforum_Category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_Category` (
  `CategoryID` int(2) NOT NULL AUTO_INCREMENT,
  `Name` varchar(100) NOT NULL,
  `Description` text DEFAULT NULL,
  `Priority` int(11) NOT NULL DEFAULT 0,
  `Cat_filter` text DEFAULT NULL,
  `Subscribeable` int(1) NOT NULL DEFAULT 1,
  PRIMARY KEY (`CategoryID`)
) ENGINE=InnoDB AUTO_INCREMENT=30 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_CategoryBlock`
--

DROP TABLE IF EXISTS `mathforge_nforum_CategoryBlock`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_CategoryBlock` (
  `CategoryID` int(11) NOT NULL DEFAULT 0,
  `UserID` int(11) NOT NULL DEFAULT 0,
  `Blocked` enum('1','0') NOT NULL DEFAULT '1',
  PRIMARY KEY (`CategoryID`,`UserID`),
  KEY `cat_block_user` (`UserID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_CategoryRoleBlock`
--

DROP TABLE IF EXISTS `mathforge_nforum_CategoryRoleBlock`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_CategoryRoleBlock` (
  `CategoryID` int(11) NOT NULL DEFAULT 0,
  `RoleID` int(11) NOT NULL DEFAULT 0,
  `Blocked` enum('1','0') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '0',
  KEY `cat_roleblock_cat` (`CategoryID`),
  KEY `cat_roleblock_role` (`RoleID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_Comment`
--

DROP TABLE IF EXISTS `mathforge_nforum_Comment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_Comment` (
  `CommentID` int(8) NOT NULL AUTO_INCREMENT,
  `DiscussionID` int(8) NOT NULL DEFAULT 0,
  `AuthUserID` int(10) NOT NULL DEFAULT 0,
  `DateCreated` datetime DEFAULT NULL,
  `EditUserID` int(10) DEFAULT NULL,
  `DateEdited` datetime DEFAULT NULL,
  `WhisperUserID` int(11) DEFAULT NULL,
  `Body` text DEFAULT NULL,
  `FormatType` varchar(20) DEFAULT NULL,
  `Deleted` enum('1','0') NOT NULL DEFAULT '0',
  `DateDeleted` datetime DEFAULT NULL,
  `DeleteUserID` int(10) NOT NULL DEFAULT 0,
  `RemoteIp` varchar(100) DEFAULT NULL,
  `BlogThis` tinyint(1) NOT NULL DEFAULT 0,
  PRIMARY KEY (`CommentID`,`DiscussionID`),
  KEY `comment_user` (`AuthUserID`),
  KEY `comment_whisper` (`WhisperUserID`),
  KEY `comment_discussion` (`DiscussionID`)
) ENGINE=InnoDB AUTO_INCREMENT=121187 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_CommentHistory`
--

DROP TABLE IF EXISTS `mathforge_nforum_CommentHistory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_CommentHistory` (
  `RevisionID` int(8) NOT NULL AUTO_INCREMENT,
  `CommentID` int(8) NOT NULL DEFAULT 0,
  `DiscussionID` int(8) NOT NULL DEFAULT 0,
  `AuthUserID` int(10) NOT NULL DEFAULT 0,
  `DateCreated` datetime DEFAULT NULL,
  `EditUserID` int(10) DEFAULT NULL,
  `DateEdited` datetime DEFAULT NULL,
  `WhisperUserID` int(11) DEFAULT NULL,
  `Body` text CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  `FormatType` varchar(20) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  `Deleted` enum('1','0') CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL DEFAULT '0',
  `DateDeleted` datetime DEFAULT NULL,
  `DeleteUserID` int(10) NOT NULL DEFAULT 0,
  `RemoteIp` varchar(100) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`RevisionID`,`CommentID`,`DiscussionID`)
) ENGINE=InnoDB AUTO_INCREMENT=126061 DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_Discussion`
--

DROP TABLE IF EXISTS `mathforge_nforum_Discussion`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_Discussion` (
  `DiscussionID` int(8) NOT NULL AUTO_INCREMENT,
  `AuthUserID` int(10) NOT NULL DEFAULT 0,
  `WhisperUserID` int(11) NOT NULL DEFAULT 0,
  `FirstCommentID` int(11) NOT NULL DEFAULT 0,
  `LastUserID` int(11) NOT NULL DEFAULT 0,
  `Active` enum('1','0') NOT NULL DEFAULT '1',
  `Closed` enum('1','0') NOT NULL DEFAULT '0',
  `Sticky` enum('9','8','7','6','5','4','3','2','1','0') NOT NULL DEFAULT '0',
  `Sink` enum('1','0') NOT NULL DEFAULT '0',
  `Name` varchar(100) NOT NULL,
  `DateCreated` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `DateLastActive` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `CountComments` int(4) NOT NULL DEFAULT 1,
  `CategoryID` int(11) DEFAULT NULL,
  `WhisperToLastUserID` int(11) DEFAULT NULL,
  `WhisperFromLastUserID` int(11) DEFAULT NULL,
  `DateLastWhisper` datetime DEFAULT NULL,
  `TotalWhisperCount` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`DiscussionID`),
  KEY `discussion_user` (`AuthUserID`),
  KEY `discussion_whisperuser` (`WhisperUserID`),
  KEY `discussion_first` (`FirstCommentID`),
  KEY `discussion_last` (`LastUserID`),
  KEY `discussion_category` (`CategoryID`),
  KEY `discussion_dateactive` (`DateLastActive`)
) ENGINE=InnoDB AUTO_INCREMENT=18992 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_IpHistory`
--

DROP TABLE IF EXISTS `mathforge_nforum_IpHistory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_IpHistory` (
  `IpHistoryID` int(11) NOT NULL AUTO_INCREMENT,
  `RemoteIp` varchar(30) NOT NULL DEFAULT '',
  `UserID` int(11) NOT NULL DEFAULT 0,
  `DateLogged` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`IpHistoryID`)
) ENGINE=InnoDB AUTO_INCREMENT=350749 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_Notify`
--

DROP TABLE IF EXISTS `mathforge_nforum_Notify`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_Notify` (
  `NotifyID` int(11) NOT NULL AUTO_INCREMENT,
  `UserID` int(11) NOT NULL,
  `Method` varchar(10) NOT NULL,
  `SelectID` int(11) NOT NULL,
  PRIMARY KEY (`NotifyID`)
) ENGINE=InnoDB AUTO_INCREMENT=457 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_Role`
--

DROP TABLE IF EXISTS `mathforge_nforum_Role`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_Role` (
  `RoleID` int(2) NOT NULL AUTO_INCREMENT,
  `Name` varchar(100) NOT NULL,
  `Icon` varchar(155) NOT NULL,
  `Description` varchar(200) NOT NULL,
  `Active` enum('1','0') NOT NULL DEFAULT '1',
  `PERMISSION_SIGN_IN` enum('1','0') NOT NULL DEFAULT '0',
  `PERMISSION_HTML_ALLOWED` enum('0','1') NOT NULL DEFAULT '0',
  `PERMISSION_RECEIVE_APPLICATION_NOTIFICATION` enum('1','0') NOT NULL DEFAULT '0',
  `Permissions` text DEFAULT NULL,
  `Priority` int(11) NOT NULL DEFAULT 0,
  `UnAuthenticated` enum('1','0') NOT NULL DEFAULT '0',
  PRIMARY KEY (`RoleID`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_Style`
--

DROP TABLE IF EXISTS `mathforge_nforum_Style`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_Style` (
  `StyleID` int(3) NOT NULL AUTO_INCREMENT,
  `AuthUserID` int(11) NOT NULL DEFAULT 0,
  `Name` varchar(50) NOT NULL,
  `Url` varchar(255) NOT NULL,
  `PreviewImage` varchar(20) NOT NULL,
  PRIMARY KEY (`StyleID`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_Tags`
--

DROP TABLE IF EXISTS `mathforge_nforum_Tags`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_Tags` (
  `TagName` varchar(255) NOT NULL,
  `DiscussionID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_User`
--

DROP TABLE IF EXISTS `mathforge_nforum_User`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_User` (
  `LocalID` int(10) NOT NULL AUTO_INCREMENT,
  `UserID` int(10) NOT NULL,
  `RoleID` int(2) NOT NULL DEFAULT 0,
  `StyleID` int(3) NOT NULL DEFAULT 1,
  `CustomStyle` varchar(255) DEFAULT NULL,
  `UtilizeEmail` enum('1','0') NOT NULL DEFAULT '0',
  `ShowName` enum('1','0') NOT NULL DEFAULT '1',
  `Icon` varchar(255) DEFAULT NULL,
  `Picture` varchar(255) DEFAULT NULL,
  `Attributes` text DEFAULT NULL,
  `CountVisit` int(8) NOT NULL DEFAULT 0,
  `CountDiscussions` int(8) NOT NULL DEFAULT 0,
  `CountComments` int(8) NOT NULL DEFAULT 0,
  `DateFirstVisit` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `DateLastActive` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `RemoteIp` varchar(100) NOT NULL DEFAULT '',
  `LastDiscussionPost` datetime DEFAULT NULL,
  `DiscussionSpamCheck` int(11) NOT NULL DEFAULT 0,
  `LastCommentPost` datetime DEFAULT NULL,
  `CommentSpamCheck` int(11) NOT NULL DEFAULT 0,
  `UserBlocksCategories` enum('1','0') NOT NULL DEFAULT '0',
  `DefaultFormatType` varchar(20) DEFAULT NULL,
  `Discovery` text DEFAULT NULL,
  `Preferences` text DEFAULT NULL,
  `SendNewApplicantNotifications` enum('1','0') NOT NULL DEFAULT '0',
  `SubscribeOwn` tinyint(1) NOT NULL DEFAULT 0,
  `Notified` tinyint(1) NOT NULL DEFAULT 0,
  `MarkAllRead` timestamp NULL DEFAULT NULL,
  `ProfileText` text CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`UserID`),
  KEY `user_local` (`LocalID`),
  KEY `user_role` (`RoleID`),
  KEY `user_style` (`StyleID`)
) ENGINE=InnoDB AUTO_INCREMENT=1660 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_UserBookmark`
--

DROP TABLE IF EXISTS `mathforge_nforum_UserBookmark`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_UserBookmark` (
  `UserID` int(10) NOT NULL DEFAULT 0,
  `DiscussionID` int(8) NOT NULL DEFAULT 0,
  PRIMARY KEY (`UserID`,`DiscussionID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_UserDiscussionWatch`
--

DROP TABLE IF EXISTS `mathforge_nforum_UserDiscussionWatch`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_UserDiscussionWatch` (
  `UserID` int(10) NOT NULL DEFAULT 0,
  `DiscussionID` int(8) NOT NULL DEFAULT 0,
  `CountComments` int(11) NOT NULL DEFAULT 0,
  `LastViewed` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`UserID`,`DiscussionID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_nforum_UserRoleHistory`
--

DROP TABLE IF EXISTS `mathforge_nforum_UserRoleHistory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_nforum_UserRoleHistory` (
  `UserID` int(10) NOT NULL DEFAULT 0,
  `RoleID` int(2) NOT NULL DEFAULT 0,
  `Date` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `AdminUserID` int(10) NOT NULL DEFAULT 0,
  `Notes` varchar(200) DEFAULT NULL,
  `RemoteIp` varchar(100) DEFAULT NULL,
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`ID`),
  KEY `UserID` (`UserID`)
) ENGINE=InnoDB AUTO_INCREMENT=5718 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_openid`
--

DROP TABLE IF EXISTS `mathforge_openid`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_openid` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `userid` int(11) NOT NULL,
  `openid` char(255) NOT NULL,
  `server` char(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`,`userid`),
  KEY `openid` (`openid`)
) ENGINE=InnoDB AUTO_INCREMENT=118 DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_role`
--

DROP TABLE IF EXISTS `mathforge_role`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_role` (
  `RoleID` int(2) NOT NULL AUTO_INCREMENT,
  `Name` varchar(100) NOT NULL DEFAULT '',
  `Icon` varchar(155) NOT NULL DEFAULT '',
  `Description` varchar(200) NOT NULL DEFAULT '',
  `Active` enum('1','0') NOT NULL DEFAULT '1',
  `PERMISSION_SIGN_IN` enum('1','0') NOT NULL DEFAULT '0',
  `PERMISSION_HTML_ALLOWED` enum('0','1') NOT NULL DEFAULT '0',
  `PERMISSION_RECEIVE_APPLICATION_NOTIFICATION` enum('1','0') NOT NULL DEFAULT '0',
  `Permissions` text DEFAULT NULL,
  `Priority` int(11) NOT NULL DEFAULT 0,
  `UnAuthenticated` enum('1','0') NOT NULL DEFAULT '0',
  PRIMARY KEY (`RoleID`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_user`
--

DROP TABLE IF EXISTS `mathforge_user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_user` (
  `UserID` int(10) NOT NULL AUTO_INCREMENT,
  `RoleID` int(2) NOT NULL DEFAULT 0,
  `StyleID` int(3) NOT NULL DEFAULT 1,
  `CustomStyle` varchar(255) DEFAULT NULL,
  `FirstName` varchar(50) NOT NULL DEFAULT '',
  `LastName` varchar(50) NOT NULL DEFAULT '',
  `Name` varchar(20) NOT NULL DEFAULT '',
  `Password` varbinary(34) DEFAULT NULL,
  `VerificationKey` varchar(50) NOT NULL DEFAULT '',
  `EmailVerificationKey` varchar(50) DEFAULT NULL,
  `Email` varchar(200) NOT NULL DEFAULT '',
  `UtilizeEmail` enum('1','0') NOT NULL DEFAULT '0',
  `ShowName` enum('1','0') NOT NULL DEFAULT '1',
  `Icon` varchar(255) DEFAULT NULL,
  `Picture` varchar(255) DEFAULT NULL,
  `Attributes` text DEFAULT NULL,
  `CountVisit` int(8) NOT NULL DEFAULT 0,
  `CountDiscussions` int(8) NOT NULL DEFAULT 0,
  `CountComments` int(8) NOT NULL DEFAULT 0,
  `DateFirstVisit` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `DateLastActive` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `RemoteIp` varchar(100) NOT NULL DEFAULT '',
  `LastDiscussionPost` datetime DEFAULT NULL,
  `DiscussionSpamCheck` int(11) NOT NULL DEFAULT 0,
  `LastCommentPost` datetime DEFAULT NULL,
  `CommentSpamCheck` int(11) NOT NULL DEFAULT 0,
  `UserBlocksCategories` enum('1','0') NOT NULL DEFAULT '0',
  `DefaultFormatType` varchar(20) DEFAULT NULL,
  `Discovery` text DEFAULT NULL,
  `Preferences` text DEFAULT NULL,
  `SendNewApplicantNotifications` enum('1','0') NOT NULL DEFAULT '0',
  `ProfileText` text DEFAULT NULL,
  `SubscribeOwn` tinyint(1) NOT NULL DEFAULT 0,
  `Notified` tinyint(1) NOT NULL DEFAULT 0,
  PRIMARY KEY (`UserID`),
  KEY `user_role` (`RoleID`),
  KEY `user_style` (`StyleID`),
  KEY `user_name` (`Name`)
) ENGINE=InnoDB AUTO_INCREMENT=3714 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mathforge_userrolehistory`
--

DROP TABLE IF EXISTS `mathforge_userrolehistory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mathforge_userrolehistory` (
  `UserID` int(10) NOT NULL DEFAULT 0,
  `RoleID` int(2) NOT NULL DEFAULT 0,
  `Date` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `AdminUserID` int(10) NOT NULL DEFAULT 0,
  `Notes` varchar(200) DEFAULT NULL,
  `RemoteIp` varchar(100) DEFAULT NULL,
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`ID`),
  KEY `UserID` (`UserID`)
) ENGINE=InnoDB AUTO_INCREMENT=2282 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `pages`
--

DROP TABLE IF EXISTS `pages`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pages` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  `web_id` int(11) NOT NULL DEFAULT 0,
  `locked_by` varchar(60) DEFAULT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `locked_at` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `index_pages_on_web_id_and_name` (`web_id`,`name`)
) ENGINE=InnoDB AUTO_INCREMENT=27531 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `revisions`
--

DROP TABLE IF EXISTS `revisions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `revisions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  `revised_at` datetime NOT NULL,
  `page_id` int(11) NOT NULL DEFAULT 0,
  `content` mediumtext DEFAULT NULL,
  `author` varchar(60) DEFAULT NULL,
  `ip` varchar(60) DEFAULT NULL,
  `web_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `index_revisions_on_page_id` (`page_id`),
  KEY `index_revisions_on_created_at` (`created_at`),
  KEY `index_revisions_on_author` (`author`),
  KEY `index_revisions_on_web_id` (`web_id`),
  KEY `index_revisions_on_web_id_and_updated_at_and_id_and_page_id` (`web_id`,`updated_at`,`id`,`page_id`)
) ENGINE=InnoDB AUTO_INCREMENT=218770 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `schema_migrations`
--

DROP TABLE IF EXISTS `schema_migrations`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `schema_migrations` (
  `version` varchar(255) NOT NULL,
  UNIQUE KEY `unique_schema_migrations` (`version`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `sessions`
--

DROP TABLE IF EXISTS `sessions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sessions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `session_id` varchar(255) DEFAULT NULL,
  `data` mediumtext DEFAULT NULL,
  `updated_at` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `index_sessions_on_session_id` (`session_id`)
) ENGINE=InnoDB AUTO_INCREMENT=22264733 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `system`
--

DROP TABLE IF EXISTS `system`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `system` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `password` varchar(60) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `webs`
--

DROP TABLE IF EXISTS `webs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `webs` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  `name` varchar(60) NOT NULL DEFAULT '',
  `address` varchar(60) NOT NULL DEFAULT '',
  `password` varchar(60) DEFAULT NULL,
  `additional_style` mediumtext DEFAULT NULL,
  `allow_uploads` int(11) DEFAULT 1,
  `published` int(11) DEFAULT 0,
  `count_pages` int(11) DEFAULT 0,
  `markup` varchar(50) DEFAULT 'markdownMML',
  `color` varchar(6) DEFAULT '008B26',
  `max_upload_size` int(11) DEFAULT 100,
  `safe_mode` int(11) DEFAULT 0,
  `brackets_only` int(11) DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=49 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `wiki_files`
--

DROP TABLE IF EXISTS `wiki_files`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `wiki_files` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  `web_id` int(11) NOT NULL,
  `file_name` varchar(255) DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6090 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `wiki_references`
--

DROP TABLE IF EXISTS `wiki_references`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `wiki_references` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  `page_id` int(11) NOT NULL DEFAULT 0,
  `referenced_name` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `link_type` varchar(1) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `index_wiki_references_on_page_id` (`page_id`),
  KEY `index_wiki_references_on_referenced_name` (`referenced_name`),
  KEY `index_wiki_references_on_link_type` (`link_type`)
) ENGINE=InnoDB AUTO_INCREMENT=45241132 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-03-11 19:31:39
