#pragma once

#include <array>

#include "character.hpp"

namespace ansi{
// A streamable 2D character array which supports ansi colors and styles
template<std::size_t width, std::size_t height>
class screen{
	// The type of the internal character array
	typedef std::array<character, width * height> character_array;

	// The character array
	character_array characters;

public:
	// Create a screen with an initializer list optionally
	screen(character_array characters = {}): characters(characters){}

	// Returns a character from a position
	const character& at(std::size_t x, std::size_t y) const{
		return characters.at(x + y * width);
	}

	// Returns a character from a position
	character& at(std::size_t x, std::size_t y){
		return characters.at(x + y * width);
	}

	// Returns the internal array
	const character_array& get() const{
		return characters;
	}

	// Returns the internal array
	character_array& get(){
		return characters;
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
			if(y < height - 1) os << "\033[0m\n";
		}
		os << "\033[0m";
		return os;
	}
};
};
