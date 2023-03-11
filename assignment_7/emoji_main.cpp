#include "AnimationWindow.h"
#include "Emoji.h"


// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;
constexpr Point windowCentre{xmax/2, ymax/2};
constexpr Point windowSize{xmax, ymax};

int main()
{

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	// Problem 4c
	// EmptyFace emptyFace(windowCentre, emojiRadius);
	// emptyFace.draw(win);

	// Problem 5a
	// SmilingFace smilingFace(windowCentre, emojiRadius);
	// smilingFace.draw(win);

	// Problem 5b
	// SadFace sadFace(windowCentre, emojiRadius);
	// sadFace.draw(win);

	// Problem 5c
	// AngryFace angryFace(windowCentre, emojiRadius);
	// angryFace.draw(win);

	// Problem 5d
	// WinkingFace winkingFace(windowCentre, emojiRadius);
	// winkingFace.draw(win);

	// Problem 5e
	// SurprisedFace surprisedFace(windowCentre, emojiRadius);
	// surprisedFace.draw(win);

	drawAllEmojis(win, windowSize, emojiRadius);

	win.wait_for_close();

	return 0;
}
