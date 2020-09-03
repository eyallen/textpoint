#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <memory>
#include <string>

#include "Slide.h"

class Renderer
{
public:

    Renderer() {};

    static void initialize();
    static void drawSlideNumber(int current, int max);

    virtual void drawSlide(std::shared_ptr<Slide> slide) = 0;

protected:

    static void drawTextAt(std::string text, int x, int y); 
    static void typewriterTextAt(std::string text, int x, int y);
    static void lazerTextAt(std::string text, int x, int y);
};

#endif
