#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow& win) = 0;
    
    virtual ~Emoji() {}; //destruktør
};

class Face : public Emoji
{
protected:
    Point centre{0,0};
    int radius{0};
public:
    Face(Point c, int r) : centre{c}, radius{r} {};
    virtual void draw(AnimationWindow& win) override = 0;

    virtual ~Face() {};
};

class EmptyFace : public Face
{
protected:
    Point leftEye{centre.x-15, centre.y-10};
    Point rightEye{centre.x+15, centre.y-10};
    int eyeRadius = radius/8;
public:
    EmptyFace(Point c, int r) : Face{c, r} {};
    void draw(AnimationWindow& win) override;

    ~EmptyFace() {};
};

class SmilingFace : public EmptyFace
{
public:
    SmilingFace(Point c, int r) : EmptyFace(c, r) {};
    void draw(AnimationWindow& win) override;

    ~SmilingFace() {};
};

class SadFace : public EmptyFace
{
public:
    SadFace(Point c, int r) : EmptyFace(c, r) {};
    void draw(AnimationWindow& win) override;

    ~SadFace() {};
};

class AngryFace : public SadFace
{
public:
    AngryFace(Point c, int r) : SadFace(c, r) {};
    void draw(AnimationWindow& win) override;

    ~AngryFace() {};
};

class WinkingFace : public Face
{
public:
    WinkingFace(Point c, int r) : Face(c, r) {};
    void draw(AnimationWindow& win) override;

    ~WinkingFace() {};
};

class SurprisedFace : public EmptyFace
{
public:
    SurprisedFace(Point c, int r) : EmptyFace(c, r) {};
    void draw(AnimationWindow& win) override;

    ~SurprisedFace() {};
};

void drawAllEmojis(AnimationWindow& win, Point windowSize, int emojiRadius);
