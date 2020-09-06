#include "include/TitleSlide.h"
#include "include/Renderer.h"

#include <ncurses.h>

void TitleSlide::drawSlide()
{
    int x, y, titleLen, subTitleLen;

    getmaxyx(stdscr, y, x);
    titleLen = this->getTitle().length();
    subTitleLen = this->getSubTitle().length();

    Renderer::drawTitleTextAt(this->getTitle(), (x-titleLen)/2, y/2);
    Renderer::drawSubTitleTextAt(this->getSubTitle(), (x-subTitleLen)/2, (y/2) + 2);

    refresh();
}

std::string TitleSlide::getTitle()
{
    return m_title;
}

void TitleSlide::setTitle(std::string title)
{
    m_title = title;
}

std::string TitleSlide::getSubTitle()
{
    return m_subTitle;
}

void TitleSlide::setSubTitle(std::string subTitle)
{
    m_subTitle = subTitle;
}
