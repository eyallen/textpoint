#include <ncurses.h>

#include "include/Presenter.h"
#include "include/Renderer.h"

void Presenter::addSlide(std::shared_ptr<Slide> slide)
{
   m_slides.push_back(slide); 
}

void Presenter::startPresentation()
{
    // TODO: This is not ideal. There should be a better way to do this.

    Renderer::initialize();

    for (int i = 0; i < m_slides.size(); ++i)
    {
        Renderer::drawSlideNumber(i+1, m_slides.size());

        m_slides[i]->drawSlide();

        getch();
        clear();
    }

    endwin();
}
