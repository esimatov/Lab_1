#include <iostream>//повторно подключил все библиотеки
#include "Book.h"
#include <string>
#include <stdlib.h>

using namespace std;

void Interface()//написал клавиши для управления
{
    cout << "Control keys:" << endl;
    cout << "Setting fields: 1-To set the title of the book; 2-To set the author of the book; 3-To set the count page of the book" << endl;
    cout << "Getting fields: 4-To get the title of the book; 5-To get the author of the book; 6-To get the count page of the book" << endl;
    cout << "Actions with the book:" << endl;
    cout << "7-To show all book's fields; 8-To copy book; 9-To delete book; " << endl;
}

void showBooks(short countOfBook, Book *Books)//создал функцию с переменной(номер книги) и объектом класса (использован с указателем) в качестве параметров
{
    for (short i = 0; i < countOfBook; i++) //задал цикл,который зависит от переменной номера книги
    {
        cout << i+1 << ")";//вывод номера книги
        Books[i].PrintInfo();//вывод информации о книге при помощи функции принт
    }
}

    int main()
{
    string tmpName, tmpAuthor;//временные строки, которые служат для присваивания полям объекта вводимых значений
    short var = 0, countOfBook = 1, i = 0, y = 0;//переменные для работы с методами гет/сет, копирования и удаления объектов
    int tmpCountPage = 0;
    Book *Books = new Book[1], *tmpBooks;//создание объекта книга1 и выделение памяти для храниния её значений
    while (1)//цикл, который позволит пользователю начать работу с программой
    {
        cout << "\nPress 1 to start,  press 0 for exit programm\n" << endl;
        cin >> i;
        if (i == 0)// если введено 0, то объект книга1 удаляется и программа заканчивается
        {
            delete Books;
            return 0;
        }
        Interface();//вывод клавиш управления

        while (i != 0)//цикл, который позволит продолжить работу с программой, если введено любое число кроме 0
        {
            cin >> var;//ввод переменной для выбора типа взаимодействия
            switch (var)//цикл взаимодействия
            {
                case 1:
                    cout << "\nEnter the name of book:" << endl;
                    cin >> tmpName;
                    Books[i-1].SetName(tmpName);
                    break;//ввод названия
                case 2:
                    cout << "\nEnter the author of book:" << endl;
                    cin >> tmpAuthor;
                    Books[i-1].SetAuthor(tmpAuthor);
                    break;//ввод автора
                case 3:
                    cout << "\nEnter the count of pages of book:" << endl;
                    cin >> tmpCountPage;
                    if (tmpCountPage >= 0)
                    {
                        Books[i-1].SetCountPage(tmpCountPage);
                    }else{
                        cout << "\nThe count of pages cannot be negative ." << endl;
                        }
                    break;//ввод числа страниц
                case 4:
                    cout << "\nThe name of book:\t" << (tmpName = Books[i-1].GetName()) << endl;
                    break;//вывод названия
                case 5:
                    cout << "\nThe author of book:\t" << (tmpAuthor = Books[i-1].GetAuthor()) << endl;
                    break;//вывод автора
                case 6:
                    cout << "\nThe count of pages of book:\t" << (tmpCountPage = Books[i-1].GetCountPage()) << endl;
                    break;//вывод числа страниц
                case 7:
                    Books[i-1].PrintInfo();
                    break;//вывод всей информации о книге
                case 8:{
                    countOfBook++;//увеличиваем номер книги
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
                    break;}//копирование книги
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
                    break;}//удаление книги
            }
        }
    }
}
