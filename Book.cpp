#include "Book.h"
#include <iostream>
#include <string>
#include <cstring>

Book::Book()
{
    SetCountPage(0);
}
Book::Book(const Book &copyBook)
{
    this -> name = copyBook.name;
    this -> author = copyBook.author;
    this -> countPage = copyBook.countPage;
}
void Book :: PrintInfo()
{
    cout << "Книга:" << name << "\nАвтор:" << author << "\nСтраниц в книге:" << countPage << endl;
}
void Book :: SetName(string name_d)
    {   this -> name = name_d;  }

void Book :: SetAuthor(string author_d)
    {   this -> author = author_d;  }

void Book :: SetCountPage(int countPage_d)
    {   this -> countPage = countPage_d;  }

string Book :: GetName()
    {
        return name;
    }

string Book :: GetAuthor()
    {
        return author;
    }

int Book :: GetCountPage()
    {
        return countPage;
    }
Book :: ~Book()
{
}
