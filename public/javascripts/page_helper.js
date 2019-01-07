/*
* Based on Simon Willison's blockquotes.js
*   http://simon.incutio.com/archive/2002/12/20/#blockquoteCitations
*/
function extractBlockquoteCitations() {
  var quotes = document.getElementsByTagName('blockquote');
  for (i = 0; i < quotes.length; i++) {
    var cite = quotes[i].getAttribute('cite');
    if (cite && cite != '') {
      var newlink = document.createElement('a');
      newlink.setAttribute('href', cite);
      newlink.setAttribute('title', cite);
      newlink.appendChild(document.createTextNode('#'));
      var newspan = document.createElement('span');
      newspan.setAttribute('class','blockquotesource');
      newspan.appendChild(newlink);
      quotes[i].lastChild.previousSibling.appendChild(newspan);
    }
  }
}

function fixRunIn() {
// work around lack of gecko support for display:run-in
  var re = /^num_|\s+num_|^un_|\s+un_|proof/;
  $$('div > h6').each(function(element) {
    next_p = element.next('p');
    if(re.test($(element.parentNode).className)) {
      var new_span = new Element('span').update(element.textContent);
      new_span.addClassName('theorem_label');
      var period = new Element('span').update('. ');
      if (next_p) {
        var next_el = next_p.firstChild;
        next_p.insertBefore(new_span, next_el);
        next_p.insertBefore(period, next_el);
        element.remove();
      } else {
        var p = new Element('p').update(new_span);
        p.appendChild(period);
        element.replace(p);
      }
    }
  });
// add tombstone to proof, since gecko doesn't support :last-child properly
 $$('div.proof').each(function(element) {
     var el = element.childElements()[element.childElements().length-1];
     var span = new Element('span').update('\u00a0\u00a0\u25ae')
     if (el == null) {
       console.log("Problem with rendering: " + element.toString())
       return
     }
     if (el.match('p')) {
       el.insert(span);
     } else {
       var par = new Element('p').update(span);
       par.addClassName('tombstone');
       element.appendChild(par);
     }
    });
}

function mactionWorkarounds() {
  $$('maction[actiontype="tooltip"]').each( function(mtool){
     Element.writeAttribute(mtool, 'title',
       Element.firstDescendant(mtool).nextSibling.firstChild.data);
     });
  $$('maction[actiontype="statusline"]').each( function(mstatus){
     var v = Element.firstDescendant(mstatus).nextSibling.firstChild.data;
     Event.observe(mstatus, 'mouseover', function(){window.status =  v;});
     Event.observe(mstatus, 'mouseout',  function(){window.status = '';});
     });
  $$('maction[actiontype="highlight"]').each( function(mhighlight){
     var elt = Element.firstDescendant(mhighlight);
     var a = mhighlight.getAttribute('other').split(/\s*=\s*/);
     var pp = /^.(#?\w+).$/.exec(a[1]);
     if (pp) var colspec = pp[1];
     switch (a[0]) {
       case 'color' :
         var oldColspec = window.getComputedStyle(elt, null).color;
         break;
       case 'background' :
         var oldColspec = window.getComputedStyle(elt, null).backgroundColor;
     }
     if (colspec && oldColspec) {
       Event.observe(mhighlight, 'mouseover', function(){elt.setAttribute('style', a[0]+':'+colspec);});
       Event.observe(mhighlight, 'mouseout',  function(){elt.setAttribute('style', a[0]+':'+oldColspec);});
     }
   });
}

function embedCDFs () {
  if ( hasCDFPlugin() ) {
    $$('div.cdf_object').each( function(element) {
      var o = new Element('object');
      var width = element.getAttribute('width');
      var height = element.getAttribute('height');
      o.setAttribute('classid', 'clsid:612AB921-E294-41AA-8E98-87E7E057EF33');
      o.setAttribute('type', 'application/vnd.wolfram.cdf.text');
      o.setAttribute('width', width);
      o.setAttribute('height', height);
      var p = new Element('param');
      p.setAttribute('type', 'src');
      p.setAttribute('value', element.getAttribute('src'));
      o.appendChild(p);
      var e = new Element('embed');
      e.setAttribute('type', 'application/vnd.wolfram.cdf.text');
      e.setAttribute('src', element.getAttribute('src'));
      e.setAttribute('width', width);
      e.setAttribute('height', height);
      o.appendChild(e);
      element.replace(o);
    });
  }
}

function hasCDFPlugin () {
  if (typeof ActiveXObject != 'undefined') {
    // IE
    try {
      if (new ActiveXObject("Mathematica.Control") ) return true;
    } catch (e) { }
  } else if(navigator.plugins && navigator.plugins.length > 0) {
    // Gecko and WebKit browsers
    for (var i = 0; i < navigator.plugins.length; i++) {
      if (navigator.plugins[i].name.indexOf("Wolfram Mathematica") !== -1) return true;
    }
  }
  return false;
}

function selectRange(elt, start, end) {
 if (elt.setSelectionRange) {
  elt.focus();
  elt.setSelectionRange(start, end);
 } else if (elt.createTextRange) {
  var range = elt.createTextRange();
  range.collapse(true);
  range.moveEnd('character', end);
  range.moveStart('character', start);
  range.select();
 }
}

function updateSize(elt, w, h) {
   // adjust to the size of the user's browser area.
   // w and h are the original, unadjusted, width and height per row/column
    var parentheight = document.viewport.getHeight() - $('pageName').getHeight()
                  - $('editFormButtons').getHeight() - $('hidebutton').getHeight();
    var parentwidth = $('Content').getWidth();
    var f = $('MarkupHelp');
    if (f.visible()) { parentwidth = parentwidth - f.getWidth() - 20 }
    var changename = $('alter_title');
    if (changename) {
      parentheight = parentheight - changename.parentNode.getHeight()-2*h;
    }
    elt.writeAttribute({'cols': Math.floor(parentwidth/w)  - 1,
                        'rows': Math.floor(parentheight/h) - 4 });
    elt.setStyle({Width: parentwidth, Height: parentheight});
}

function resizeableTextarea() {
//make the textarea resize to fit available space
  var f = $('MarkupHelp');
  if (f) {
    var hidebutton = new Element('input', {id:'hidebutton', type:'button', value: 'Hide markup help'});
    f.insert({before: hidebutton});
  }
  $$('textarea#content').each( function(textarea)  {
    var w = textarea.getWidth()/textarea.getAttribute('cols');
    var h = textarea.getStyle('lineHeight').replace(/(\d*)px/, "$1");
    var changename = $('alter_title');
    if (changename) {
      Event.observe(changename.parentNode, 'change', function() {
        updateSize(textarea, w, h);
      });
    }
    Event.observe(hidebutton, 'click', function(){
      if (f.visible()) {
        f.hide();
        hidebutton.writeAttribute({value: 'Show markup help'});
        updateSize(textarea, w, h)
      } else {
        f.show();
        hidebutton.writeAttribute({value: 'Hide markup help'});
        updateSize(textarea, w, h)
      }
    });
    Event.observe(window, 'resize', function(){ updateSize(textarea, w, h) });
    updateSize(textarea, w, h);
   });
}

function retrieveTexSource() {
	$$('math').each( function(math){Event.observe(math, 'dblclick', grabTex);} );
	function grabTex(event){
		var tex = this.firstElementChild.lastElementChild.textContent;
		var win= window.open('','TeX','scrollbars,resizable,width=500,location=no,toolbar=no,titlebar=no,menubar=no,personalbar=no');
		win.document.documentElement.lastElementChild.textContent = tex;
		win.focus();
	}
}

function initializeYoutubePlayer() {
  var video_elts = $$('div.ytplayer');
  if (video_elts.length > 0) {
    // Load the IFrame Player API code asynchronously.
    var youtube_script = document.createElement('script');
    youtube_script.src = "https://www.youtube.com/iframe_api";
    var firstScriptTag = document.getElementsByTagName('script')[0];
    firstScriptTag.parentNode.insertBefore(youtube_script, firstScriptTag);

    window.onYouTubeIframeAPIReady = function () {
      video_elts.each(function(elt){
        var video_id = (elt.dataset.videoId && elt.dataset.videoId.match(/\w+/)) ? elt.dataset.videoId : '';
        var video_width  = (elt.dataset.videoWidth  && elt.dataset.videoWidth.match(/\d+/) ) ? elt.dataset.videoWidth  : '640';
        var video_height = (elt.dataset.videoHeight && elt.dataset.videoHeight.match(/\d+/)) ? elt.dataset.videoHeight : '390';
        var player;
        player = new YT.Player(elt, {
           height: video_height,
           width: video_width,
           videoId: video_id,
           playerVars: {}
        });
      })
    }
  }
}

function columnAlignShim() {
// https://bugs.webkit.org/show_bug.cgi?id=160075
  var mtables = document.querySelectorAll('mtable[columnalign]');
  if (mtables[0] && mtables[0].style) {
    for (var i = 0; i < mtables.length; i++) {
      var mtable = mtables[i];
      var colAligns = mtable.getAttribute('columnalign').split(/\s+/);
      if (colAligns.length > 1) {
        var mtds = mtable.querySelectorAll(':scope > mtr > mtd');
        for (var j = 0; j < mtds.length; j++) {
          mtds[j].style.textAlign = colAligns[j];
        }
      }
    }
  }
}

function minMathWidth() {
// https://bugs.webkit.org/show_bug.cgi?id=160547
  var maths = document.querySelectorAll('math[display=block]');
  if (maths[0] && maths[0].style) {
    for (var i = 0; i < maths.length; i++) {
      var m = maths[i];
      m.style.minWidth = m.firstElementChild.clientWidth;
    }
  }
}

document.observe("dom:loaded", function (){
        extractBlockquoteCitations();
        fixRunIn();
        mactionWorkarounds();
        resizeableTextarea();
        embedCDFs();
        retrieveTexSource();
        initializeYoutubePlayer();
        columnAlignShim();
        minMathWidth();
});
