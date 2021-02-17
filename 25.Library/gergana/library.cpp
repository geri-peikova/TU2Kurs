#include "library.h"

int Library::getSize() const
{
    return size;
}

void Library::incrementSize()
{
    size++;
}

void Library::setSize(int value)
{
    size = value;
}

char ** Library::getTitles()
{
    return titles;
}

void Library::setTitles(char **value)
{
    titles = value;
}

Library::Library()
{
    size = 0;
    titles = new char*[256];
}
