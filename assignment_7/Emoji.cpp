#include "Emoji.h"

// Problem 3c
/**
 * @brief Member function of Face that draws a yellow circle with specified centre and radius to window
 * @param AnimationWindow &win 
 */
void Face::draw(AnimationWindow& win)
{
    win.draw_circle(centre, radius, Color::yellow, Color::black);
}

// Problem 4a
/**
 * @brief Member function of EmptyFace that draws a yellow Emoji face with two black eyes to window
 * @param AnimationWindow &win 
 */
void EmptyFace::draw(AnimationWindow& win)
{
    Face::draw(win);
    win.draw_circle(leftEye, eyeRadius, Color::black);
    win.draw_circle(rightEye, eyeRadius, Color::black);
}

// Problem 5a
/**
 * @brief Member function of SmilingFace that draws a yellow Emoji face with two black eyes and a mouth to window
 * @param AnimationWindow &win 
 */
void SmilingFace::draw(AnimationWindow& win)
{
    Point mouthCentre{centre.x, centre.y+5};
    int arcWidth{radius-(radius/3)};
    int arcHeight{radius-(radius/2)};
    int startDegree{180};
    int endDegree{360};

    EmptyFace::draw(win);
    win.draw_arc(mouthCentre, arcWidth, arcHeight, startDegree, endDegree, Color::black);
}

// Problem 5b
/**
 * @brief Member function of SadFace that draws a yellow Emoji face with two black eyes and a mouth to window
 * @param AnimationWindow &win 
 */
void SadFace::draw(AnimationWindow& win)
{
    int arcWidth{radius-(radius/2)};
    int arcHeight{radius-(radius/2)};
    Point mouthCentre{centre.x, centre.y+arcHeight+(arcHeight/4)};
    int startDegree{15};
    int endDegree{165};

    EmptyFace::draw(win);
    win.draw_arc(mouthCentre, arcWidth, arcHeight, startDegree, endDegree, Color::black);
}

// Problem 5c
/**
 * @brief Member function of AngryFace that draws a yellow Emoji face with two black eyes and a mouth to window
 * @param AnimationWindow &win 
 */
void AngryFace::draw(AnimationWindow& win)
{
    Point leftEyebrowStart{leftEye.x-eyeRadius, leftEye.y-3*eyeRadius};
    Point leftEyebrowEnd{leftEye.x+eyeRadius, leftEye.y-2*eyeRadius};
    Point rightEyebrowStart{rightEye.x+eyeRadius, rightEye.y-3*eyeRadius};
    Point rightEyebrowEnd{rightEye.x-eyeRadius, rightEye.y-2*eyeRadius};

    SadFace::draw(win);
    win.draw_line(leftEyebrowStart, leftEyebrowEnd, Color::black);
    win.draw_line(rightEyebrowStart, rightEyebrowEnd, Color::black);
}

// Problem 5d
/**
 * @brief Member function of WinkingFace that draws a yellow Emoji face with one blinking eye and a mouth to window
 * @param AnimationWindow &win 
 */
void WinkingFace::draw(AnimationWindow& win)
{
    Point leftEye{centre.x-15, centre.y-10};
    Point rightEyeCenter{centre.x+15, centre.y-10};
    int eyeRadius = radius/8;

    int rightEyeArcWidth{eyeRadius};
    int rightEyeArcHeight{eyeRadius};
    int rightEyeStartDegree{0};
    int rightEyeEndDegree{180};

    Point mouthCentre{centre.x, centre.y+5};
    int mouthArcWidth{radius-(radius/3)};
    int mouthArcHeight{radius-(radius/2)};
    int mouthStartDegree{180};
    int mouthEndDegree{360};

    Face::draw(win);
    win.draw_circle(leftEye, eyeRadius, Color::black);
    win.draw_arc(rightEyeCenter, rightEyeArcWidth, rightEyeArcHeight, rightEyeStartDegree, rightEyeEndDegree, Color::black);
    win.draw_arc(mouthCentre, mouthArcWidth, mouthArcHeight, mouthStartDegree, mouthEndDegree, Color::black);
}

// Problem 5e
/**
 * @brief Member function of SurprisedFace that draws a yellow Emoji face with two black eyes and an open mouth to window
 * @param AnimationWindow &win 
 */
void SurprisedFace::draw(AnimationWindow& win)
{
    Point mouthCentre{centre.x, centre.y+radius/3};
    int arcWidth{radius-(radius/2)-(radius/4)};
    int arcHeight{radius-(radius/2)-(radius/4)};
    int startDegree{0};
    int endDegree{360};

    EmptyFace::draw(win);
    win.draw_arc(mouthCentre, arcWidth, arcHeight, startDegree, endDegree, Color::black);
}

/**
 * @brief Function that instantiates all Emoji classes and draws them to the same window
 * 
 * @param AnimationWindow& win 
 * @param Point windowSize 
 * @param int emojiRadius 
 */
void drawAllEmojis(AnimationWindow& win, Point windowSize, int emojiRadius)
{
    Point windowCentre{windowSize.x/2, windowSize.y/2};
    std::vector<std::unique_ptr<Emoji>> emojis;
    Point emoji1Center{windowCentre.x-6*emojiRadius, windowCentre.y};
    Point emoji2Center{windowCentre.x-3*emojiRadius, windowCentre.y};
    Point emoji3Center{windowCentre.x, windowCentre.y};
    Point emoji4Center{windowCentre.x+3*emojiRadius, windowCentre.y};
    Point emoji5Center{windowCentre.x+6*emojiRadius, windowCentre.y};

    emojis.emplace_back(new SmilingFace(emoji1Center, emojiRadius));
    emojis.emplace_back(new SadFace(emoji2Center, emojiRadius));
    emojis.emplace_back(new AngryFace(emoji3Center, emojiRadius));
    emojis.emplace_back(new WinkingFace(emoji4Center, emojiRadius));
    emojis.emplace_back(new SurprisedFace(emoji5Center, emojiRadius));

    for (unsigned int i = 0; i < emojis.size(); i++) {
        emojis.at(i)->draw(win);
    }
}
