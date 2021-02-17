#include <iostream>
#include "book.h"

int main()
{
    // Create book class and add some books ot it
    Book a;
    std::vector<std::string> authors1 = {"Bobby Fischer"};
    std::vector<std::string> authors2 = {"Magnus Carlsen", "Hikaru Nakamura"};
    std::vector<std::string> authors3 = {"J.F. Kennedy"};

    // get current date
    time_t now = time(0);
    // get yesterday
    time_t yesterday = now - 2*24*60*60;

    a.addBook("History of instagram", authors1, true, now);
    a.addBook("Java Advanced second edition", authors2, true, now);
    a.addBook("C++ for dummies", authors3, true, yesterday);

    //create file output stream
    std::ofstream file("file.txt");

    auto authors = a.getAuthors();

    //sort the authors
    std::sort(authors.begin(), authors.end(), Book::nameCompare);

    // print all information in the file.txt
    file << a << std::endl;
    // get all titles rented yesterday
    a.onDate(std::localtime(&yesterday));
    // get all books with more than one author
    a.moreThanOneAuthor();
    return 0;
}
