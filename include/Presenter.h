#ifndef PRESENTER_H
#define PRESENTER_H

#include <vector>
#include <memory>

#include "Slide.h"

class Presenter
{
public:

    Presenter() :
        m_currentSlide(0)
    {}

    void addSlide(std::shared_ptr<Slide> slide);

    void startPresentation();

private:
    int m_currentSlide;

    std::vector<std::shared_ptr<Slide> > m_slides;
};

#endif
