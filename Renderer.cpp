#include <ncurses.h>
#include <unistd.h>

#include "include/Renderer.h"

static const int c_typewriterAnimationSpeed = 200000;
static const int c_lazerAnimationSpeed = 15000;

void Renderer::initialize()
{
    // Do some static initialization here
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}


void Renderer::drawSlideNumber(int current, int max)
{
    int x, y;

    getmaxyx(stdscr, y, x);

    mvprintw(y-1, 2, "[slide %d/%d]", current, max);
}

void Renderer::drawTextAt(std::string text, int x, int y)
{
    mvprintw(y, x, "%s", text.c_str());
}

void Renderer::typewriterTextAt(std::string text, int x, int y)
{
    for (int i = 0; i < text.length(); ++i)
    {
        mvprintw(y, x+i, "%c", text.at(i));
        refresh();

        usleep(c_typewriterAnimationSpeed);
    }
}

void Renderer::lazerTextAt(std::string text, int x, int y)
{
    for (int i = 0; i < text.length(); ++i)
    {
        for (int j = text.length(); j > i; --j)
        {
            mvprintw(y, x+j, "%c", text.at(i)); 
            mvdelch(y, x+j+1);

            refresh();

            usleep(c_lazerAnimationSpeed);
        }
    }
}

void Renderer::drawTitleTextAt(std::string text, int x, int y)
{
    attron(A_UNDERLINE);
    Renderer::typewriterTextAt(text, x, y);
    attroff(A_UNDERLINE);
}

void Renderer::drawSubTitleTextAt(std::string text, int x, int y)
{
    attron(A_DIM);
    Renderer::lazerTextAt(text, x, y);
    attroff(A_DIM);
}

void Renderer::drawSectionHeaderAt(std::string text, int x, int y)
{
    attron(A_BOLD);
    Renderer::drawTextAt(text, x, y);
    attroff(A_BOLD);
}
