#include <ncurses.h>

#include <memory>

#include "include/Presenter.h"
#include "include/Slide.h"
#include "include/TitleSlide.h"
#include "include/SectionHeaderSlide.h"
#include "include/Renderer.h"

int main()
{
    std::shared_ptr<TitleSlide> titleSlide = std::make_shared<TitleSlide>();

    titleSlide->setTitle("Test Title");
    titleSlide->setSubTitle("This is my sub title");

    std::shared_ptr<TitleSlide> titleSlide2 = std::make_shared<TitleSlide>();

    titleSlide2->setTitle("One More Title");
    titleSlide2->setSubTitle("This is another slide for testing.");

    std::shared_ptr<SectionHeaderSlide> sectionHeader = std::make_shared<SectionHeaderSlide>();
    sectionHeader->setHeader("This is a section header.");

    Presenter presenter;
    presenter.addSlide(titleSlide);
    presenter.addSlide(titleSlide2);
    presenter.addSlide(sectionHeader);

    presenter.startPresentation();

    return 0;
}
