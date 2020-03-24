#include <iostream>
#include "Book.h"
#include <string>
#include <stdlib.h>

using namespace std;

void Interface()
{
    cout << "������� ����������:" << endl;
    cout << "���� ��������: 1-�������� �����; 2-����� �����; 3-����� ������� � �����" << endl;
    cout << "��������� ��������: 4-�������� �����; 5-����� �����; 6-����� ������� � �����" << endl;
    cout << "�������������� � �������:" << endl;
    cout << "7-�������� ��� ���������� � �����; 8-���������� �����; 9-������� �����; " << endl;
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
        cout << "\n��� ������ ������ ������� 1,  ����� ����� 0\n" << endl;
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
                    cout << "\n������� �������� �����:" << endl;
                    cin >> tmpName;
                    Books[i-1].SetName(tmpName);
                    break;
                case 2:
                    cout << "\n������� ������ �����:" << endl;
                    cin >> tmpAuthor;
                    Books[i-1].SetAuthor(tmpAuthor);
                    break;
                case 3:
                    cout << "\n������� ����� �������:" << endl;
                    cin >> tmpCountPage;
                    if (tmpCountPage >= 0)
                    {
                        Books[i-1].SetCountPage(tmpCountPage);
                    }else{
                        cout << "\n����� ������� �� ����� ���� �������������." << endl;
                        }
                    break;
                case 4:
                    cout << "\n�������� �����:\t" << (tmpName = Books[i-1].GetName()) << endl;
                    break;
                case 5:
                    cout << "\n����� �����:\t" << (tmpAuthor = Books[i-1].GetAuthor()) << endl;
                    break;
                case 6:
                    cout << "\n����� ������� � �����:\t" << (tmpCountPage = Books[i-1].GetCountPage()) << endl;
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
