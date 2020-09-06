#ifndef SLIDE_H
#define SLIDE_H

#include <memory>

class Renderer;

class Slide
{
public:

    Slide() {}
    ~Slide() {};

    // TODO: This should take an instance of renderer once this needs state.
    virtual void drawSlide() = 0;
};    

#endif
