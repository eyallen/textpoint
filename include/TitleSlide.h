#ifndef TITLESLIDE_H
#define TITLESLIDE_H

#include <string>
#include <memory>

#include "Slide.h"

class TitleSlide : public Slide
{
public:
    TitleSlide() :
        Slide()
    {}

    std::string getTitle();
    void setTitle(std::string title);

    std::string getSubTitle();
    void setSubTitle(std::string subTitle);

private:

    std::string m_title;
    std::string m_subTitle;
};

#endif
