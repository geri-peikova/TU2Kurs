#include "book.h"
/**
 * @brief Book::getAvailable
 * gets the list of
 * @return
 */
std::vector<bool> Book::getAvailable() const
{
    return available;
}

void Book::setAvailable(const std::vector<bool> &value)
{
    available = value;
}

std::vector<time_t> Book::getRentedOn() const
{
    return rentedOn;
}

void Book::setRentedOn(const std::vector<time_t> &value)
{
    rentedOn = value;
}

std::vector<std::vector<std::string> > Book::getAuthors() const
{
    return authors;
}

void Book::setAuthors(const std::vector<std::vector<std::string> > &value)
{
    authors = value;
}

/**
 * @brief compares the first author name to the firest author name of another
 * list
 * @param author name 1
 * @param author name 2
 * @return
 */
bool Book::nameCompare(const std::vector<std::string> &a,
                       const std::vector<std::string> &b)
{
    if (a.empty())
        return false;
    if (b.empty())
        return true;
    return a.front() > b.front();
}

/**
 * @brief prints in a file all book titles of books that were rented on the
 * chosen day
 * @param the date to save all books rented on
 */
void Book::onDate(struct tm* chosenDate)
{
    const struct tm chdate = *chosenDate;
    std::ofstream file("books.txt");
    for (int i = 0; i < getSize(); ++i) {
        auto bookdateraw = getRentedOn().at(i);
        auto bookDate = std::localtime(&bookdateraw);
        if (bookDate->tm_mon == chdate.tm_mon
            && bookDate->tm_year == chdate.tm_year
            && bookDate->tm_mday == chdate.tm_mday)
        {
            file << getTitles()[i] << std::endl;
        }
    }
}
/**
 * @brief prints in a file all information about books with more than one author
 */
void Book::moreThanOneAuthor()
{
    std::ofstream file("authors.txt");
    for (int i = 0; i < getSize(); ++i) {
        if (getAuthors().at(i).size() > 1) {
            file << "{ ";
            for (auto &a : authors.at(i)) {
                file << a << " ";
            }
            file << ", "
                << ctime(&getRentedOn().at(i)) << ", "
                << ((getAvailable().at(i)) ? "available }" : "unavailable }");
        }
    }
}

/**
 * @brief constructor for book
 */
Book::Book()
{
    Library();
}

/**
 * @brief adds book to the book class
 * @param title of the book
 * @param authors of the book
 * @param available if the book is available
 * @param date the day it was rented on
 */
void Book::addBook(const char* title,
                   const std::vector<std::string> authors,
                   bool available,
                   time_t date)
{

    // allocate memory for the title name
    getTitles()[getSize()] = new char[255];
    strcpy(getTitles()[getSize()], title);
    this->authors.push_back(authors);
    this->available.push_back(available);
    this->rentedOn.push_back(date);
    this->incrementSize();
}

/**
 * @brief Overloads the operator << to print books from Book class
 * @param os outputstream to pass file stream
 * @param b book class
 * @return
 */
std::ostream& operator<<(std::ostream& os, const Book& b)
{
    // print all book information
    auto authors = b.getAuthors();
    for (int i = 0; i < b.getSize(); ++i) {
        os << "{ ";
        for (auto &a : authors.at(i)) {
            os << a << " ";
        }
        os << ", "
            << ctime(&b.getRentedOn().at(i)) << ", "
            << ((b.getAvailable().at(i)) ? "available }" : "unavailable }");
    }
    return os;
}
