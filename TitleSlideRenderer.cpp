#include "include/TitleSlideRenderer.h"

#include <ncurses.h>

void TitleSlideRenderer::drawSlide(std::shared_ptr<Slide> slide)
{
    std::shared_ptr<TitleSlide> titleSlide = std::static_pointer_cast<TitleSlide>(slide);
    int x, y, titleLen, subTitleLen;

    getmaxyx(stdscr, y, x);
    titleLen = titleSlide->getTitle().length();
    subTitleLen = titleSlide->getSubTitle().length();

    this->drawTitleTextAt(titleSlide->getTitle(), (x-titleLen)/2, y/2);
    this->drawSubTitleTextAt(titleSlide->getSubTitle(), (x-subTitleLen)/2, (y/2) + 2);

    refresh();
}

void TitleSlideRenderer::drawTitleTextAt(std::string text, int x, int y)
{
    attron(A_UNDERLINE);
    Renderer::typewriterTextAt(text, x, y);
    attroff(A_UNDERLINE);
}

void TitleSlideRenderer::drawSubTitleTextAt(std::string text, int x, int y)
{
    attron(A_DIM);
    Renderer::lazerTextAt(text, x, y);
    attroff(A_DIM);
}

