#include "character.hpp"

ansi::character::character(
	char ch,
	color foreground_color,
	color background_color,
	bool bold,
	bool italics,
	bool underline,
	bool inverse,
	bool strikethrough
):
	ch(ch),
	foreground_color(foreground_color),
	background_color(background_color),
	bold(bold),
	italics(italics),
	underline(underline),
	inverse(inverse),
	strikethrough(strikethrough)
{}

int ansi::character::foreground_color_code(color foreground_color){
	switch(foreground_color){
	case color::black:
		return 30;
	case color::red:
		return 31;
	case color::green:
		return 32;
	case color::yellow:
		return 33;
	case color::blue:
		return 34;
	case color::magenta:
		return 35;
	case color::cyan:
		return 36;
	case color::white:
		return 37;
	default:
		return 39;
	}
}

int ansi::character::background_color_code(color background_color){
	switch(background_color){
	case color::black:
		return 40;
	case color::red:
		return 41;
	case color::green:
		return 42;
	case color::yellow:
		return 43;
	case color::blue:
		return 44;
	case color::magenta:
		return 45;
	case color::cyan:
		return 46;
	case color::white:
		return 47;
	default:
		return 49;
	}
}
