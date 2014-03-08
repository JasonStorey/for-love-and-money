var PatternGenerator = function(selector, res) {

	var container = $(selector),
		container_width = container.width(),
		container_height = container.height(),
		resolution = res,
		sections = [],
		mouseIsDown = false;

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

	function render() {
		container.append(sections);
	}

	function setupMouseListeners(){
		listenForHover();
		container.mousedown(function() {
			mouseIsDown = true;
		});

		$('body').mouseup(function(){
			mouseIsDown = false;
		});

	}

	function listenForHover() {
		container.mousemove(function(e){			
			if(!mouseIsDown || e.target.className !== 'section_container') {
				return;
			}
			moveSection(e.target.children[0], container_height - e.clientY);
		});
	}

	function moveSection(sectionElem, yPos) {
		$(sectionElem).height(((yPos / container_height) * 100) + '%');
	}

	return {
		init: function() {
			init();
			render();
			setupMouseListeners();
		},
		getPattern: getPattern
	};
};

$(document).ready(function() {
	var pattern1 = PatternGenerator('.pattern', 300);
	pattern1.init();

	$('#save').click(function(){
		console.log(pattern1.getPattern());
	});
});