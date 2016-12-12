#### How to use it
Create a `screen<width, height>` and populate it using `at(x, y) = character()`. A `character` has 8 public members: The character itself: `char ch`, the text color: `color foreground_color`, the background color: `color background_color`, whether or not it's bold: `bool bold`, whether or not it's in italics: `bool italics`, whether or not it's underlined: `bool underlined`, whether or not the text color and the background color are reversed: `bool inverse`, and whether or not it has a strike through it: `bool strikethrough`. The enum, `color` includes `black`, `red`, `green`, `yellow`, `blue`, `magenta`, `cyan`, `white`, `none` (default), and `count` if you want to know how many colors there are. All the classes are in the `ansi` namespace and color is in in `ansi::character` namespace.

[Screenshot of the output of the following code (Random characters with random colors and styles)](https://i.sli.mg/twpNoU.png)
```
// The screen dimensions
constexpr size_t width = 80, height = 24;

// The screen
ansi::screen<width, height> my_screen;

// For every collum of the screen
for(size_t y = 0; y < height; y++){

	// For every row of the collum
	for(size_t x = 0; x < width; x++){

		// RNG for making a random character with random colors and random styles
		typedef std::uniform_int_distribution<int> distribution;
		static std::default_random_engine engine(42);

		// A random character a-to-z
		char my_char = 'a' + distribution(0, 25)(engine);

		// A random foreground color
		ansi::color my_foreground_color = (ansi::color)distribution((int)ansi::color::none, (int)ansi::color::count)(engine);

		// A random background color
		ansi::color my_background_color = (ansi::color)distribution((int)ansi::color::none, (int)ansi::color::count)(engine);

		// 50-50 chance of being bold
		bool is_bold = distribution(false, true)(engine);

		// 50-50 chance of being in italics
		bool is_italics = distribution(false, true)(engine);

		// 50-50 chance of being underlined
		bool is_underlined = distribution(false, true)(engine);

		// 50-50 chance of the foreground color and the background color being reversed
		bool is_inverse = distribution(false, true)(engine);

		// 50-50 chance of having a strikethrough
		bool has_strikethrough = distribution(false, true)(engine);

		// A random character with random colors and styles
		ansi::character my_character(
			my_char,
			my_foreground_color,
			my_background_color,
			is_bold,
			is_italics,
			is_underlined,
			is_inverse,
			has_strikethrough
		);

		// Set the character on the screen at (x, y) to the random character
		my_screen.at(x, y) = my_character;
	}
}

// Print the screen!
std::cout << my_screen;
```

