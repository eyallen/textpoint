#ifndef TITLESLIDERENDERER_H
#define TITLESLIDERENDERER_H

#include <memory>
#include <string>

#include "Renderer.h"
#include "TitleSlide.h"

class TitleSlideRenderer : public Renderer
{
public:

    TitleSlideRenderer() {};

    virtual void drawSlide(std::shared_ptr<Slide> slide);

private:

    void drawTitleTextAt(std::string text, int x, int y);
    void drawSubTitleTextAt(std::string text, int x, int y);
};

#endif
