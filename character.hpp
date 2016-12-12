#pragma once

#include <iostream>

#include "color.hpp"

namespace ansi{
// A streamable character which supports ansi color and style
struct character{
	character(
		char ch = ' ',
		color foreground_color = color::none,
		color background_color = color::none,
		bool bold = false,
		bool italics = false,
		bool underline = false,
		bool inverse = false,
		bool strikethrough = false
	);

	// The internal char
	char ch;

	// The colors
	color foreground_color, background_color;

	// The styles
	bool bold, italics, underline, inverse, strikethrough;

	// Upload the ansi character to a stream
	friend std::istream& operator>>(std::istream& is, character& rhs){
		// TODO
		return is;
	}

	// Upload the character to an ostream
	friend std::ostream& operator<<(std::ostream& os, const character& rhs){
		os << "\033["
		   << std::to_string(character::foreground_color_code(rhs.foreground_color)) + ';'
		   << std::to_string(character::background_color_code(rhs.background_color)) + ';'
		   << (rhs.bold ? "1;" : "22;")
		   << (rhs.italics ? "3;" : "23;")
		   << (rhs.underline ? "4;" : "24;")
		   << (rhs.inverse ? "7;" : "27;")
		   << (rhs.strikethrough ? "9m" : "29m")
		   << (rhs.ch);

		return os;
	}

	// Return the ansi-code for a forground color
	static int foreground_color_code(color foreground_color);

	// Return the ansi-code for a background color
	static int background_color_code(color background_color);
};
};
