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

    static void drawTextAt(std::string text, int x, int y); 
    static void typewriterTextAt(std::string text, int x, int y);
    static void lazerTextAt(std::string text, int x, int y);

    // TODO: This should probably go somewhere else, but for now
    //       I want to keep a single renderer for simplicity.
    //
    //       The text items themselves should keep the style attributes,
    //       and the slides should know the layout/position.
    static void drawTitleTextAt(std::string text, int x, int y);
    static void drawSubTitleTextAt(std::string text, int x, int y);
};

#endif
