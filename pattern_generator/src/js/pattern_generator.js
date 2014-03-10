var PatternGenerator = function(selector, res) {

	var container = $(selector),
		container_width = container.width(),
		container_height = container.height(),
		resolution = res,
		sections = [],
		mouseIsDown = false,
		startPoint = {x:0,y:0},
		endPoint = {x:0,y:0},
		lineDrawMode = false,
		shiftKeyIsDown = false;

	function init() {
		var i,
			section_container,
			section,
			section_width;

		for(i = 0; i < resolution; i++) {
			section_width = container_width / resolution;

			section_container = $('<div>');
			section = $('<div>');

			section_container.addClass('section_container');
			section.addClass('section');

			section_container.width(section_width);
			section_container.css('left', (section_width * i)+ 'px');

			section_container.append(section);
			sections.push(section_container);
			container.append(sections);			
		}
	}

	function getPattern() {
		var patternValues = '',
			pattern;

		for(var i = 0; i < sections.length; i++) {

			patternValues += Math.floor((sections[i].find('.section').height() / container_height) * 100);

			if(i !== sections.length -1)
				 patternValues += ',';
		}

		pattern = "#ifndef Patterns_h\n#define Patterns_h\n#define PATTERN_1_RESOLUTION " + resolution + "\nprog_uint16_t pattern1[PATTERN_1_RESOLUTION] PROGMEM = {" + patternValues + "};\n#endif";
		return pattern;
	}

	function load(data) {
		console.log(parsePattern(data));
	}

	function parsePattern(data) {
		return data;
	}

	function setupMouseListeners(){
		listenForHover();
		container.mousedown(function(e) {
			mouseIsDown = true;
			shiftKeyIsDown = e.shiftKey;
			startPoint.y = container_height - e.clientY;
		});

		$('body').mouseup(function(){
			mouseIsDown = false;
		});

		container.dblclick(function(e){
			moveSection(e.target.children[0], container_height - e.clientY);

			if(lineDrawMode) {
				startPoint.x = e.clientX;
				startPoint.y = e.clientY;
			} else {
				// draw line
			}

			lineDrawMode = !lineDrawMode;
		});
	}

	function listenForHover() {
		container.mousemove(function(e){			
			if(!mouseIsDown || e.target.className !== 'section_container') {
				return;
			}

			var y = shiftKeyIsDown ? startPoint.y : container_height - e.clientY;
			moveSection(e.target.children[0], y);
		});
	}

	function moveSection(sectionElem, yPos) {
		if(sectionElem.className !== 'section') {
			return;
		}

		$(sectionElem).height(((yPos / container_height) * 100) + '%');
	}

	return {
		init: function() {
			init();
			setupMouseListeners();
		},
		getPattern: getPattern,
		load: load
	};
};

var FileLoader = function(pattern) {

	function init() {
		if (window.File && window.FileReader && window.FileList && window.Blob) {
			document.getElementById('files').addEventListener('change', handleFileSelect, false);
		} else {
		  alert('The File APIs are not fully supported in this browser.');
		}
	}

	function handleFileSelect(evt) {
	    var files = evt.target.files; // FileList object

	    // files is a FileList of File objects. List some properties.
	    var output = [];
	    for (var i = 0, f; f = files[i]; i++) {
	      	output.push('<li><strong>', escape(f.name), '</strong> (', f.type || 'n/a', ') - ',
	                  	f.size, ' bytes, last modified: ',
	                  	f.lastModifiedDate ? f.lastModifiedDate.toLocaleDateString() : 'n/a',
	                  	'</li>');
	      	readFile(f);
	    }
	    document.getElementById('list').innerHTML = '<ul>' + output.join('') + '</ul>';
	}

	function readFile(f) {
		var reader = new FileReader();

		// Closure to capture the file information.
		reader.onload = (function(file) {
			return function(e) {
				pattern.load(e.target.result);
			};
		})(f);

		// Read in the image file as a data URL.
		reader.readAsText(f);
	}

	return {
		init: init
	}
}

$(document).ready(function() {
	var pattern1 = PatternGenerator('.pattern', 200);
	pattern1.init();

	var fileLoader = FileLoader(pattern1);
	fileLoader.init();

	$('#save').click(function(){
		console.log(pattern1.getPattern());
	});
});