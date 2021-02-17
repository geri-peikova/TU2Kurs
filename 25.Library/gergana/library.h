#ifndef LIBRARY_H
#define LIBRARY_H

/**
 * Contains titles of the books iun the library and how many book it has
 */
class Library
{
    int size;
    char** titles;
public:
    Library();
    int getSize() const;
    void incrementSize();
    void setSize(int value);
    char **getTitles();
    void setTitles(char **value);
};

#endif // LIBRARY_H
