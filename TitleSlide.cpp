#include "include/TitleSlide.h"

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
