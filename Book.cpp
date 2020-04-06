#include "Book.h" //ссылаемся на файл класса
#include <iostream> //подключаем библиотеку воода-вывода
#include <string> //подключаем библиотеки для работы со строками
#include <cstring>

Book::Book() //задал тело конструктора с параметрами 
{
    SetCountPage(0); //принял стандартом кол-во страниц = 0
}
Book::Book (int const countPage)
{
    this -> countPage = countPage;
}
Book::Book(const Book &copyBook)// задал тело конструктора копирования
{
    this -> name = copyBook.name; //указал поля для копий объектов
    this -> author = copyBook.author;
    this -> countPage = copyBook.countPage;
}
void Book :: PrintInfo()//создал тело для функции принт, выводящей информацию о книге
{
    cout << "Name of the book:" << name << "\nBook's Author:" << author << "\nCount of pages:" << countPage << endl;
}
void Book :: SetName(string const * const name_d)//создал тела для метода сет
    {   this -> name = *name_d;  }

void Book :: SetAuthor(string const * const author_d)
    {   this -> author =*author_d;  }

void Book :: SetCountPage(int const countPage_d)
    {   this -> countPage = countPage_d;  }

string Book :: GetName()//создал теля для метода гет
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
Book :: ~Book()//деструктор не принимает параметров
{
}
