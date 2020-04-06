#ifndef BOOK_H //в этом файле прописан класс, конструктор, деструктор, методы, тела методов,конструктора находятся в book.cpp
#define BOOK_H
#include <string>
#include <cstring>
using namespace std;

class Book
{
private:
    string name; // требуемые поля
    string author;
    int countPage;
public:
    Book ();
    Book (const Book &book); //конструктор копирования
    void PrintInfo (); //функция принт
    void SetName (string const * const name_d); //метод сет для названия книги
    void SetAuthor (string const * const author_d);//для автора
    void SetCountPage (int const countPage_d);//для количества страниц
    string GetName ();//метод гет для тех же полей
    string GetAuthor ();
    int GetCountPage ();
    ~Book ();//деструктор
};
#endif
