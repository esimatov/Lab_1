#include <iostream>//повторно подключил все библиотеки
#include "Book.h"
#include <string>
#include <stdlib.h>

using namespace std;

void Interface()//написал клавиши для управления
{
    cout << "������� ����������:" << endl;
    cout << "���� ��������: 1-�������� �����; 2-����� �����; 3-����� ������� � �����" << endl;
    cout << "��������� ��������: 4-�������� �����; 5-����� �����; 6-����� ������� � �����" << endl;
    cout << "�������������� � �������:" << endl;
    cout << "7-�������� ��� ���������� � �����; 8-���������� �����; 9-������� �����; " << endl;
}

void showBooks(short countOfBook, Book *Books)//создал функцию которая создает первую книгу,  используя класс и указатель на каждый новый объект
{
    for (short i = 0; i < countOfBook; i++) //задал цикл,который зависит от переменной кол-ва книг
    {
        cout << i+1 << ")";//вывод номера книги
        Books[i].PrintInfo();//вывод информации о книге при помощи функции принт
    }
}

    int main()
{
    setlocale(LC_ALL, "Rus");
    string tmpName, tmpAuthor;//временные строки, которые служат для присваивания полям объекта вводимых значений
    short var = 0, countOfBook = 1, i = 0, y = 0;//переменные для работы с методами гет/сет
    int tmpCountPage = 0;
    Book *Books = new Book[1], *tmpBooks;//создание объекта книга1 и выделение памяти для храниния её значений
    while (1)//цикл, который позволит пользователю начать работу с программой
    {
        cout << "\n��� ������ ������ ������� 1,  ����� ����� 0\n" << endl;
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
                    cout << "\n������� �������� �����:" << endl;
                    cin >> tmpName;
                    Books[i-1].SetName(tmpName);
                    break;//ввод названия
                case 2:
                    cout << "\n������� ������ �����:" << endl;
                    cin >> tmpAuthor;
                    Books[i-1].SetAuthor(tmpAuthor);
                    break;//ввод автора
                case 3:
                    cout << "\n������� ����� �������:" << endl;
                    cin >> tmpCountPage;
                    if (tmpCountPage >= 0)
                    {
                        Books[i-1].SetCountPage(tmpCountPage);
                    }else{
                        cout << "\n����� ������� �� ����� ���� �������������." << endl;
                        }
                    break;//ввод числа страниц
                case 4:
                    cout << "\n�������� �����:\t" << (tmpName = Books[i-1].GetName()) << endl;
                    break;//вывод названия
                case 5:
                    cout << "\n����� �����:\t" << (tmpAuthor = Books[i-1].GetAuthor()) << endl;
                    break;//вывод автора
                case 6:
                    cout << "\n����� ������� � �����:\t" << (tmpCountPage = Books[i-1].GetCountPage()) << endl;
                    break;//вывод числа страниц
                case 7:
                    Books[i-1].PrintInfo();
                    break;//вывод всей информации о книге
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
