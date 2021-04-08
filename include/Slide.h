#ifndef SLIDE_H
#define SLIDE_H

class Slide
{
public:

    Slide() {}
    ~Slide() {};

    // TODO: Return a generic element for the presenter to pass to the renderer
    //       Then move drawing out of the slide class entirely.
    virtual void drawSlide() = 0;

    // Returns true if there are additional elements to draw,
    // false otherwise.
    // virtual bool drawNextElement() = 0;
};    

#endif
