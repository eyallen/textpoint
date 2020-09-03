#include <ncurses.h>
#include <unistd.h>

#include "include/Renderer.h"

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

        usleep(200000);
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

            usleep(15000);
        }
    }
}
