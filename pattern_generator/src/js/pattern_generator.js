var PatternGenerator = function(selector) {

	var container = $(selector),
		container_width = container.width(),
		container_height = container.height(),
		resolution = 300,
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

	function moveSection(sectionElem, mouseY) {
		$(sectionElem).height(((mouseY / container_height) * 100) + '%');
	}

	return {
		init: function() {
			init();
			render();
			setupMouseListeners();
		}
	};
};

$(document).ready(function() {
	var pattern1 = PatternGenerator('.pattern');
	pattern1.init();
});