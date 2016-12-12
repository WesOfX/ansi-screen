#### How to use it
Create a `screen<width, height>` and populate it using `at(x, y) = character()`. A `character` has 8 public members: The character itself: `char ch`, the text color: `color foreground_color`, the background color: `color background_color`, whether or not it's bold: `bool bold`, whether or not it's in italics: `bool italics`, whether or not it's underlined: `bool underlined`, whether or not the text color and the background color are reversed: `bool inverse`, and whether or not it has a strike through it: `bool strikethrough`. The `color` enum includes `black`, `red`, `green`, `yellow`, `blue`, `magenta`, `cyan`, `white`, `none` (default), and `count` if you want to know how many colors there are. All the classes are in the `ansi` namespace and color is in in `ansi::character` namespace.

[Screenshot of the output of the following code (Random characters with random colors and styles)](https://i.sli.mg/twpNoU.png)
```
#include <iostream>
#include "color.hpp"
#include "character.hpp"
#include "screen.hpp"

int main(){
	using namespace ansi;

	// The screen dimensions
	constexpr size_t width = 8, height = 3;

	// The screen
	screen<width, height> my_screen(
		{
			{
				{'a'}, {'b'}, {'c'}, {'d'}, {'e'}, {'f'}, {'g'}, {'h'},
				{'1'}, {'2'}, {'3'}, {'4'}, {'5'}, {'6'}, {'7'}, {'8'},
				{'g'}, {'r'}, {'a'}, {'p'}, {'h'}, {'i'}, {'c'}, {'s'}
			}
		}
	);

	// Set the character at (0, 2) to bold with a red background
	my_screen.at(0, 2).bold = true;
	my_screen.at(0, 2).background_color = color::red;

	// Replace the character at (1, 1) with a blue, italics, capital Z
	my_screen.at(1, 1) = character(
		'Z', // The character
		color::blue, // The text color
		color::none, // The background color
		false, // Bold?
		true, // Italics?
		false, // Underlined?
		false, // Inverted colors?
		false // Strikethrough?
	);

	// Underline the top row
	for(size_t i = 0; i < width; i++){
		my_screen.at(i, 0).underline = true;
	}

	// Give the far-right collum a blue background
	for(size_t i = 0; i < height; i++){
		my_screen.at(width - 1, i).background_color = color::blue;
	}

	// Print the screen!
	std::cout << my_screen;
}
```

