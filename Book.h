#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <cstring>
using namespace std;

class Book
{
private:
    string name;
    string author;
    int countPage;
public:
    Book ();
    Book (const Book &book);
    void PrintInfo ();
    void SetName (string name_d);
    void SetAuthor (string author_d);
    void SetCountPage (int countPage_d);
    string GetName ();
    string GetAuthor ();
    int GetCountPage ();
    ~Book ();
};
#endif
