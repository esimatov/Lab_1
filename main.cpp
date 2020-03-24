#include <iostream>
#include "Book.h"
#include <string>
#include <stdlib.h>

using namespace std;

void Interface()
{
    cout << "Клавиши управления:" << endl;
    cout << "Ввод значений: 1-Название книги; 2-Автор книги; 3-Число страниц в книге" << endl;
    cout << "Получение значений: 4-Название книги; 5-Автор книги; 6-Число страниц в книге" << endl;
    cout << "Взаимодействие с книгами:" << endl;
    cout << "7-Показать всю информацию о книге; 8-Копировать книгу; 9-Удалить книгу; " << endl;
}

void showBooks(short countOfBook, Book *Books)
{
    for (short i = 0; i < countOfBook; i++)
    {
        cout << i+1 << ")";
        Books[i].PrintInfo();
    }
}

    int main()
{
    setlocale(LC_ALL, "Rus");
    string tmpName, tmpAuthor;
    short var = 0, countOfBook = 1, i = 0, y = 0;
    int tmpCountPage = 0;
    Book *Books = new Book[1], *tmpBooks;
    while (1)
    {
        cout << "\nДля начала работы нажмите 1,  чтобы выйти 0\n" << endl;
        cin >> i;
        if (i == 0)
        {
            delete Books;
            return 0;
        }
        Interface();

        while (i != 0)
        {
            cin >> var;
            switch (var)
            {
                case 1:
                    cout << "\nВведите название книги:" << endl;
                    cin >> tmpName;
                    Books[i-1].SetName(tmpName);
                    break;
                case 2:
                    cout << "\nВведите автора книги:" << endl;
                    cin >> tmpAuthor;
                    Books[i-1].SetAuthor(tmpAuthor);
                    break;
                case 3:
                    cout << "\nВведите число страниц:" << endl;
                    cin >> tmpCountPage;
                    if (tmpCountPage >= 0)
                    {
                        Books[i-1].SetCountPage(tmpCountPage);
                    }else{
                        cout << "\nЧисло страниц не может быть отрицательным." << endl;
                        }
                    break;
                case 4:
                    cout << "\nНазвание книги:\t" << (tmpName = Books[i-1].GetName()) << endl;
                    break;
                case 5:
                    cout << "\nАвтор книги:\t" << (tmpAuthor = Books[i-1].GetAuthor()) << endl;
                    break;
                case 6:
                    cout << "\nЧисло страниц в книге:\t" << (tmpCountPage = Books[i-1].GetCountPage()) << endl;
                    break;
                case 7:
                    Books[i-1].PrintInfo();
                    break;
                case 8:{
                    countOfBook++;
                    tmpBooks = new Book[countOfBook];
                    for (y = 0; y < countOfBook-1; y++)
                    {
                        tmpBooks[y] = Books[y];
                        delete &(Books[y]);
                    }
                    delete Books;
                    Books = tmpBooks;
                    Book newBook(Books[i-1]);
                    Books[countOfBook-1] = newBook;
                    break;}
                case 9:{
                    Books[i-1] = Books[countOfBook-1];
                    delete &(Books[countOfBook-1]);
                    countOfBook --;
                    tmpBooks = new Book[countOfBook];
                    for (y = 0; y < countOfBook; y++)
                    {
                        tmpBooks[y] = Books[y];
                        delete &(Books[y]);
                    }
                    delete Books;
                    Books = tmpBooks;
                    i = 0;
                    break;}
            }
        }
    }
}
