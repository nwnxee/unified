package org.nwnx.nwnx2.jvm;

/**
 * A class representing ingame-useable color tokens.
 * You can simply chain them using String + operands:
 * <p>
 * <tt>Color.RED + "Hi there!"</tt>
 */
public class Color {
	final public int r, g, b;
	final public String stringRep;

	final static public String NONE = "</c>";

	/**
	 * Create a new Color giving the Red, Green, Blue
	 * components.
	 */
	public Color(int r, int g, int b) {
		this.r = r > 255 ? 255 : r < 1 ? 1 : r;
		this.g = g > 255 ? 255 : g < 1 ? 1 : g;
		this.b = b > 255 ? 255 : b < 1 ? 1 : b;
		this.stringRep = String.format("<c%c%c%c>", r, g, b);
	}

	/**
	 * Create a new Color given a 32bit integer representation.
	 * @param hex
	 */
	public Color(int hex) {
		this((hex >> 16 & 0xff), (hex >> 8 & 0xff), (hex >> 0 & 0xff));
	}

	/**
	 * Returns a integer representation of this color:
	 * red * 0xffff + green * 0xff + blue
	 */
	public int toInt() {
		return r * 0xffff + g * 0xff + b;
	}

	@Override
	public String toString() {
		return stringRep;
	}

	/**
	 * Returns the given string colorized with this color.
	 */
	public String color(String wrap) {
		return toString() + wrap + NONE;
	}

	/**
	 * Darkens this color by the given amount and returns
	 * a new Color.
	 */
	public Color darken(int by) {
		return new Color(r - by, g - by, b - by);
	}

	/**
	 * Darkens this color by the given amount and returns
	 * a new Color.
	 */
	public Color lighten(int by) {
		return new Color(r + by, g + by, b + by);
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + b;
		result = prime * result + g;
		result = prime * result + r;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Color other = (Color) obj;
		if (b != other.b)
			return false;
		if (g != other.g)
			return false;
		if (r != other.r)
			return false;
		return true;
	}

	/**
	 * Strips all color tags from the given string.
	 */
	public static String strip(String toStrip) {
		return toStrip.replaceAll("<c...>", "").replaceAll("</c>", "");
	}

	// Colors generated from http://www.novia.net/~tomcat/HowTo/hex_color.html

	public final static Color ALICEBLUE = new Color(0xf0f8ff);
	public final static Color ANTIQUEWHITE = new Color(0xfaebd7);
	public final static Color ANTIQUEWHITE1 = new Color(0xffefdb);
	public final static Color ANTIQUEWHITE2 = new Color(0xeedfcc);
	public final static Color ANTIQUEWHITE3 = new Color(0xcdc0b0);
	public final static Color ANTIQUEWHITE4 = new Color(0x8b8378);
	public final static Color BLANCHEDALMOND = new Color(0xffebcd);
	public final static Color BLUEVIOLET = new Color(0x8a2be2);
	public final static Color CADETBLUE = new Color(0x5f9ea0);
	public final static Color CADETBLUE1 = new Color(0x98f5ff);
	public final static Color CADETBLUE2 = new Color(0x8ee5ee);
	public final static Color CADETBLUE3 = new Color(0x7ac5cd);
	public final static Color CADETBLUE4 = new Color(0x53868b);
	public final static Color CORNFLOWERBLUE = new Color(0x6495ed);
	public final static Color DARKGOLDENROD = new Color(0xb8860b);
	public final static Color DARKGREEN = new Color(0x006400);
	public final static Color DARKKHAKI = new Color(0xbdb76b);
	public final static Color DARKOLIVEGREEN = new Color(0x556b2f);
	public final static Color DARKORANGE = new Color(0xff8c00);
	public final static Color DARKORCHID = new Color(0x9932cc);
	public final static Color DARKSALMON = new Color(0xe9967a);
	public final static Color DARKSEAGREEN = new Color(0x8fbc8f);
	public final static Color DARKSEAGREEN1 = new Color(0xc1ffc1);
	public final static Color DARKSEAGREEN2 = new Color(0xb4eeb4);
	public final static Color DARKSEAGREEN3 = new Color(0x9bcd9b);
	public final static Color DARKSEAGREEN4 = new Color(0x698b69);
	public final static Color DARKSLATEBLUE = new Color(0x483d8b);
	public final static Color DARKSLATEGRAY1 = new Color(0x97ffff);
	public final static Color DARKSLATEGRAY2 = new Color(0x8deeee);
	public final static Color DARKSLATEGRAY3 = new Color(0x79cdcd);
	public final static Color DARKSLATEGRAY4 = new Color(0x528b8b);
	public final static Color DARKSLATEGREY = new Color(0x2f4f4f);
	public final static Color DARKTURQUOISE = new Color(0x00ced1);
	public final static Color DARKVIOLET = new Color(0x9400d3);
	public final static Color DEEPPINK = new Color(0xff1493);
	public final static Color DEEPSKYBLUE = new Color(0x00bfff);
	public final static Color DEEPSKYBLUE1 = new Color(0x00bfff);
	public final static Color DEEPSKYBLUE2 = new Color(0x00b2ee);
	public final static Color DEEPSKYBLUE3 = new Color(0x009acd);
	public final static Color DEEPSKYBLUE4 = new Color(0x00688b);
	public final static Color DIMGREY = new Color(0x696969);
	public final static Color DODGERBLUE = new Color(0x1e90ff);
	public final static Color DODGERBLUE1 = new Color(0x1e90ff);
	public final static Color DODGERBLUE2 = new Color(0x1c86ee);
	public final static Color DODGERBLUE3 = new Color(0x1874cd);
	public final static Color DODGERBLUE4 = new Color(0x104e8b);
	public final static Color FLORALWHITE = new Color(0xfffaf0);
	public final static Color FORESTGREEN = new Color(0x228b22);
	public final static Color GHOSTWHITE = new Color(0xf8f8ff);
	public final static Color GREENYELLOW = new Color(0xadff2f);
	public final static Color HOTPINK = new Color(0xff69b4);
	public final static Color INDIANRED = new Color(0xcd5c5c);
	public final static Color LAVENDERBLUSH = new Color(0xfff0f5);
	public final static Color LAVENDERBLUSH1 = new Color(0xfff0f5);
	public final static Color LAVENDERBLUSH2 = new Color(0xeee0e5);
	public final static Color LAVENDERBLUSH3 = new Color(0xcdc1c5);
	public final static Color LAVENDERBLUSH4 = new Color(0x8b8386);
	public final static Color LAWNGREEN = new Color(0x7cfc00);
	public final static Color LEMONCHIFFON = new Color(0xfffacd);
	public final static Color LEMONCHIFFON1 = new Color(0xfffacd);
	public final static Color LEMONCHIFFON2 = new Color(0xeee9bf);
	public final static Color LEMONCHIFFON3 = new Color(0xcdc9a5);
	public final static Color LEMONCHIFFON4 = new Color(0x8b8970);
	public final static Color LIGHTBLUE = new Color(0xadd8e6);
	public final static Color LIGHTBLUE1 = new Color(0xbfefff);
	public final static Color LIGHTBLUE2 = new Color(0xb2dfee);
	public final static Color LIGHTBLUE3 = new Color(0x9ac0cd);
	public final static Color LIGHTBLUE4 = new Color(0x68838b);
	public final static Color LIGHTCORAL = new Color(0xf08080);
	public final static Color LIGHTCYAN = new Color(0xe0ffff);
	public final static Color LIGHTCYAN1 = new Color(0xe0ffff);
	public final static Color LIGHTCYAN2 = new Color(0xd1eeee);
	public final static Color LIGHTCYAN3 = new Color(0xb4cdcd);
	public final static Color LIGHTCYAN4 = new Color(0x7a8b8b);
	public final static Color LIGHTGOLDENROD = new Color(0xeedd82);
	public final static Color LIGHTGOLDENRODYELLOW = new Color(0xfafad2);
	public final static Color LIGHTGRAY = new Color(0xd3d3d3);
	public final static Color LIGHTPINK = new Color(0xffb6c1);
	public final static Color LIGHTSALMON = new Color(0xffa07a);
	public final static Color LIGHTSEAGREEN = new Color(0x20b2aa);
	public final static Color LIGHTSKYBLUE = new Color(0x87cefa);
	public final static Color LIGHTSKYBLUE1 = new Color(0xb0e2ff);
	public final static Color LIGHTSKYBLUE2 = new Color(0xa4d3ee);
	public final static Color LIGHTSKYBLUE3 = new Color(0x8db6cd);
	public final static Color LIGHTSKYBLUE4 = new Color(0x607b8b);
	public final static Color LIGHTSLATEBLUE = new Color(0x8470ff);
	public final static Color LIGHTSLATEGREY = new Color(0x778899);
	public final static Color LIGHTSTEELBLUE = new Color(0xb0c4de);
	public final static Color LIGHTSTEELBLUE1 = new Color(0xcae1ff);
	public final static Color LIGHTSTEELBLUE2 = new Color(0xbcd2ee);
	public final static Color LIGHTSTEELBLUE3 = new Color(0xa2b5cd);
	public final static Color LIGHTSTEELBLUE4 = new Color(0x6e7b8b);
	public final static Color LIGHTYELLOW = new Color(0xffffe0);
	public final static Color LIMEGREEN = new Color(0x32cd32);
	public final static Color MEDIUMAQUAMARINE = new Color(0x66cdaa);
	public final static Color MEDIUMBLUE = new Color(0x0000cd);
	public final static Color MEDIUMORCHID = new Color(0xba55d3);
	public final static Color MEDIUMPURPLE = new Color(0x9370db);
	public final static Color MEDIUMSEAGREEN = new Color(0x3cb371);
	public final static Color MEDIUMSLATEBLUE = new Color(0x7b68ee);
	public final static Color MEDIUMSPRINGGREEN = new Color(0x00fa9a);
	public final static Color MEDIUMTURQUOISE = new Color(0x48d1cc);
	public final static Color MEDIUMVIOLETRED = new Color(0xc71585);
	public final static Color MIDNIGHTBLUE = new Color(0x191970);
	public final static Color MINTCREAM = new Color(0xf5fffa);
	public final static Color MISTYROSE = new Color(0xffe4e1);
	public final static Color MISTYROSE1 = new Color(0xffe4e1);
	public final static Color MISTYROSE2 = new Color(0xeed5d2);
	public final static Color MISTYROSE3 = new Color(0xcdb7b5);
	public final static Color MISTYROSE4 = new Color(0x8b7d7b);
	public final static Color NAVAJOWHITE = new Color(0xffdead);
	public final static Color NAVAJOWHITE1 = new Color(0xffdead);
	public final static Color NAVAJOWHITE2 = new Color(0xeecfa1);
	public final static Color NAVAJOWHITE3 = new Color(0xcdb38b);
	public final static Color NAVAJOWHITE4 = new Color(0x8b795e);
	public final static Color NAVYBLUE = new Color(0x000080);
	public final static Color OLDLACE = new Color(0xfdf5e6);
	public final static Color OLIVEDRAB = new Color(0x6b8e23);
	public final static Color OLIVEDRAB1 = new Color(0xc0ff3e);
	public final static Color OLIVEDRAB2 = new Color(0xb3ee3a);
	public final static Color OLIVEDRAB3 = new Color(0x9acd32);
	public final static Color OLIVEDRAB4 = new Color(0x698b22);
	public final static Color ORANGERED = new Color(0xff4500);
	public final static Color PALEGOLDENROD = new Color(0xeee8aa);
	public final static Color PALEGREEN = new Color(0x98fb98);
	public final static Color PALEGREEN1 = new Color(0x9aff9a);
	public final static Color PALEGREEN2 = new Color(0x90ee90);
	public final static Color PALEGREEN3 = new Color(0x7ccd7c);
	public final static Color PALEGREEN4 = new Color(0x548b54);
	public final static Color PALETURQUOISE = new Color(0xafeeee);
	public final static Color PALETURQUOISE1 = new Color(0xbbffff);
	public final static Color PALETURQUOISE2 = new Color(0xaeeeee);
	public final static Color PALETURQUOISE3 = new Color(0x96cdcd);
	public final static Color PALETURQUOISE4 = new Color(0x668b8b);
	public final static Color PALEVIOLETRED = new Color(0xdb7093);
	public final static Color PAPAYAWHIP = new Color(0xffefd5);
	public final static Color PEACHPUFF = new Color(0xffdab9);
	public final static Color PEACHPUFF1 = new Color(0xffdab9);
	public final static Color PEACHPUFF2 = new Color(0xeecbad);
	public final static Color PEACHPUFF3 = new Color(0xcdaf95);
	public final static Color PEACHPUFF4 = new Color(0x8b7765);
	public final static Color POWDERBLUE = new Color(0xb0e0e6);
	public final static Color ROSYBROWN = new Color(0xbc8f8f);
	public final static Color ROYALBLUE = new Color(0x4169e1);
	public final static Color ROYALBLUE1 = new Color(0x4876ff);
	public final static Color ROYALBLUE2 = new Color(0x436eee);
	public final static Color ROYALBLUE3 = new Color(0x3a5fcd);
	public final static Color ROYALBLUE4 = new Color(0x27408b);
	public final static Color SADDLEBROWN = new Color(0x8b4513);
	public final static Color SANDYBROWN = new Color(0xf4a460);
	public final static Color SEAGREEN = new Color(0x2e8b57);
	public final static Color SEAGREEN1 = new Color(0x54ff9f);
	public final static Color SEAGREEN2 = new Color(0x4eee94);
	public final static Color SEAGREEN3 = new Color(0x43cd80);
	public final static Color SEAGREEN4 = new Color(0x2e8b57);
	public final static Color SKYBLUE = new Color(0x87ceeb);
	public final static Color SKYBLUE1 = new Color(0x87ceff);
	public final static Color SKYBLUE2 = new Color(0x7ec0ee);
	public final static Color SKYBLUE3 = new Color(0x6ca6cd);
	public final static Color SKYBLUE4 = new Color(0x4a708b);
	public final static Color SLATEBLUE = new Color(0x6a5acd);
	public final static Color SLATEBLUE1 = new Color(0x836fff);
	public final static Color SLATEBLUE2 = new Color(0x7a67ee);
	public final static Color SLATEBLUE3 = new Color(0x6959cd);
	public final static Color SLATEBLUE4 = new Color(0x473c8b);
	public final static Color SLATEGRAY1 = new Color(0xc6e2ff);
	public final static Color SLATEGRAY2 = new Color(0xb9d3ee);
	public final static Color SLATEGRAY3 = new Color(0x9fb6cd);
	public final static Color SLATEGRAY4 = new Color(0x6c7b8b);
	public final static Color SLATEGREY = new Color(0x708090);
	public final static Color SPRINGGREEN = new Color(0x00ff7f);
	public final static Color SPRINGGREEN1 = new Color(0x00ff7f);
	public final static Color SPRINGGREEN2 = new Color(0x00ee76);
	public final static Color SPRINGGREEN3 = new Color(0x00cd66);
	public final static Color SPRINGGREEN4 = new Color(0x008b45);
	public final static Color STEELBLUE = new Color(0x4682b4);
	public final static Color STEELBLUE1 = new Color(0x63b8ff);
	public final static Color STEELBLUE2 = new Color(0x5cacee);
	public final static Color STEELBLUE3 = new Color(0x4f94cd);
	public final static Color STEELBLUE4 = new Color(0x36648b);
	public final static Color VIOLETRED = new Color(0xd02090);
	public final static Color WHITESMOKE = new Color(0xf5f5f5);
	public final static Color YELLOWGREEN = new Color(0x9acd32);
	public final static Color AQUAMARINE = new Color(0x7fffd4);
	public final static Color AQUAMARINE1 = new Color(0x7fffd4);
	public final static Color AQUAMARINE2 = new Color(0x76eec6);
	public final static Color AQUAMARINE3 = new Color(0x66cdaa);
	public final static Color AQUAMARINE4 = new Color(0x458b74);
	public final static Color AZURE = new Color(0xf0ffff);
	public final static Color AZURE1 = new Color(0xf0ffff);
	public final static Color AZURE2 = new Color(0xe0eeee);
	public final static Color AZURE3 = new Color(0xc1cdcd);
	public final static Color AZURE4 = new Color(0x838b8b);
	public final static Color BEIGE = new Color(0xf5f5dc);
	public final static Color BISQUE = new Color(0xffe4c4);
	public final static Color BISQUE1 = new Color(0xffe4c4);
	public final static Color BISQUE2 = new Color(0xeed5b7);
	public final static Color BISQUE3 = new Color(0xcdb79e);
	public final static Color BISQUE4 = new Color(0x8b7d6b);
	public final static Color BLACK = new Color(0x000000);
	public final static Color BLUE = new Color(0x0000ff);
	public final static Color BLUE1 = new Color(0x0000ff);
	public final static Color BLUE2 = new Color(0x0000ee);
	public final static Color BLUE3 = new Color(0x0000cd);
	public final static Color BLUE4 = new Color(0x00008b);
	public final static Color BROWN = new Color(0xa52a2a);
	public final static Color BURLYWOOD = new Color(0xdeb887);
	public final static Color CHARTREUSE = new Color(0x7fff00);
	public final static Color CHARTREUSE1 = new Color(0x7fff00);
	public final static Color CHARTREUSE2 = new Color(0x76ee00);
	public final static Color CHARTREUSE3 = new Color(0x66cd00);
	public final static Color CHARTREUSE4 = new Color(0x458b00);
	public final static Color CHOCOLATE = new Color(0xd2691e);
	public final static Color CORAL = new Color(0xff7f50);
	public final static Color CORNSILK = new Color(0xfff8dc);
	public final static Color CORNSILK1 = new Color(0xfff8dc);
	public final static Color CORNSILK2 = new Color(0xeee8cd);
	public final static Color CORNSILK3 = new Color(0xcdc8b1);
	public final static Color CORNSILK4 = new Color(0x8b8878);
	public final static Color CYAN = new Color(0x00ffff);
	public final static Color CYAN1 = new Color(0x00ffff);
	public final static Color CYAN2 = new Color(0x00eeee);
	public final static Color CYAN3 = new Color(0x00cdcd);
	public final static Color CYAN4 = new Color(0x008b8b);
	public final static Color FIREBRICK = new Color(0xb22222);
	public final static Color GAINSBORO = new Color(0xdcdcdc);
	public final static Color GOLD = new Color(0xffd700);
	public final static Color GOLDENROD = new Color(0xdaa520);
	public final static Color GREEN = new Color(0x00ff00);
	public final static Color GREEN1 = new Color(0x00ff00);
	public final static Color GREEN2 = new Color(0x00ee00);
	public final static Color GREEN3 = new Color(0x00cd00);
	public final static Color GREEN4 = new Color(0x008b00);
	public final static Color GREY = new Color(0xbebebe);
	public final static Color HONEYDEW = new Color(0xf0fff0);
	public final static Color HONEYDEW1 = new Color(0xf0fff0);
	public final static Color HONEYDEW2 = new Color(0xe0eee0);
	public final static Color HONEYDEW3 = new Color(0xc1cdc1);
	public final static Color HONEYDEW4 = new Color(0x838b83);
	public final static Color IVORY = new Color(0xfffff0);
	public final static Color IVORY1 = new Color(0xfffff0);
	public final static Color IVORY2 = new Color(0xeeeee0);
	public final static Color IVORY3 = new Color(0xcdcdc1);
	public final static Color IVORY4 = new Color(0x8b8b83);
	public final static Color KHAKI = new Color(0xf0e68c);
	public final static Color LAVENDER = new Color(0xe6e6fa);
	public final static Color LINEN = new Color(0xfaf0e6);
	public final static Color MAGENTA = new Color(0xff00ff);
	public final static Color MAROON = new Color(0xb03060);
	public final static Color MOCCASIN = new Color(0xffe4b5);
	public final static Color ORANGE = new Color(0xffa500);
	public final static Color ORCHID = new Color(0xda70d6);
	public final static Color PERU = new Color(0xcd853f);
	public final static Color PINK = new Color(0xffc0cb);
	public final static Color PLUM = new Color(0xdda0dd);
	public final static Color PURPLE = new Color(0xa020f0);
	public final static Color RED = new Color(0xff0000);
	public final static Color SALMON = new Color(0xfa8072);
	public final static Color SEASHELL = new Color(0xfff5ee);
	public final static Color SEASHELL1 = new Color(0xfff5ee);
	public final static Color SEASHELL2 = new Color(0xeee5de);
	public final static Color SEASHELL3 = new Color(0xcdc5bf);
	public final static Color SEASHELL4 = new Color(0x8b8682);
	public final static Color SIENNA = new Color(0xa0522d);
	public final static Color SNOW = new Color(0xfffafa);
	public final static Color SNOW1 = new Color(0xfffafa);
	public final static Color SNOW2 = new Color(0xeee9e9);
	public final static Color SNOW3 = new Color(0xcdc9c9);
	public final static Color SNOW4 = new Color(0x8b8989);
	public final static Color TAN = new Color(0xd2b48c);
	public final static Color THISTLE = new Color(0xd8bfd8);
	public final static Color TOMATO = new Color(0xff6347);
	public final static Color TURQUOISE = new Color(0x40e0d0);
	public final static Color TURQUOISE1 = new Color(0x00f5ff);
	public final static Color TURQUOISE2 = new Color(0x00e5ee);
	public final static Color TURQUOISE3 = new Color(0x00c5cd);
	public final static Color TURQUOISE4 = new Color(0x00868b);
	public final static Color VIOLET = new Color(0xee82ee);
	public final static Color WHEAT = new Color(0xf5deb3);
	public final static Color WHITE = new Color(0xffffff);
	public final static Color YELLOW = new Color(0xffff00);
}