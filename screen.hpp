#pragma once

#include <array>

#include "character.hpp"

namespace ansi{
// A streamable 2D character array which supports ansi colors and styles
template<std::size_t width, std::size_t height>
class screen{
	// The ansi-character array
	std::array<character, width * height> characters;

public:
	// Returns a character from a position
	const character& at(std::size_t x, std::size_t y) const{
		return characters.at(x + y * width);
	}

	// Returns a character from a position
	character& at(std::size_t x, std::size_t y){
		return characters.at(x + y * width);
	}

	// Downloads the screen from an istream
	friend std::istream& operator>>(std::istream& is, screen<width, height>& rhs){
		// TODO

		return is;
	}

	// Uploads the screen to an ostream
	friend std::ostream& operator<<(std::ostream& os, const screen<width, height>& rhs){
		for(std::size_t y = 0; y < height; y++){
			for(std::size_t x = 0; x < width; x++){
				os << rhs.at(x, y);
			}
			os << "\033[0m\n";
		}
		return os;
	}
};
};
