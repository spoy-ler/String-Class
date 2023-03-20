#include "MyString.h"

#include <iostream>
#include <clocale>
#include <windows.h>
#include <cctype>
#include <conio.h>
using namespace std;

void CompleteTask()
{
    cout << "\nНатисніть будь-яку клавішу для продовження. ";
    _getch();
    system("cls");
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Реалізація класу для роботи з рядками та регулярними виразами.\n\n";
    int operation;
    int clear = 0;
    MyString str("");
    MyString newstr("");
    MyString commonstr("");
again:
    if (clear != 0)
    CompleteTask();
    clear++;
    cout << "Оберіть дію: \n\n1) Введення рядку \n2) Виведення рядку \n3) Порівняння рядків \n4) Додавання рядків \n5) Кількість літер у рядку \n6) Кількість певних літер в рядку \n7) Пошук слова у рядку \n\nДля завершення роботи натисніть '8'. " << endl;
    cout << "Введіть номер: ";
    cin >> operation;
    while (operation > 8 || operation < 1)
    {
        cout << "Оберіть дію з запропонованих. Введіть номер: ";
        cin >> operation;
    }
    switch (operation)
    {
    case 1:
    {
        SetColor(2, 0);
        cout << "\nВведення рядку\n" << endl;
        SetColor(7, 0);
        cout << "Введіть вміст нового рядка: ";
        cin >> str;
        goto again;
    }
    case 2:
    {
        SetColor(2, 0);
        cout << "\nВиведення рядку\n" << endl;
        SetColor(7, 0);
        int length = (int)str.strLength();
        if (length < 1)
        {
            cout << "Спочатку введіть рядок. Введіть вміст нового рядка: ";
            cin >> str;
        }
        cout << "Виведення рядка: ";
        cout << str;
        cout << endl;
        goto again;
    }
    case 3:
    {
        SetColor(2, 0);
        cout << "\nПорівняння рядків\n" << endl;
        SetColor(7, 0);
        int length = (int)str.strLength();
        if (length < 1)
        {
            cout << "Спочатку введіть рядок. Введіть вміст нового рядка: ";
            cin >> str;
        }
        cout << "Введіть другий рядок: ";
        cin >> newstr;
        cout << "Рядки '" << str << "' і '" << newstr << "'";
        if (str == newstr)
        {
            cout << " однакові." << endl;
        }
        if (str != newstr)
        {
            cout << " не однакові." << endl;
        }
        goto again;
    }
    case 4:
    {
        SetColor(2, 0);
        cout << "\nДодавання рядків\n" << endl;
        SetColor(7, 0);
        int length_1 = (int)str.strLength();
        if (length_1 < 1)
        {
            cout << "Спочатку введіть рядок. Введіть вміст нового рядка: ";
            cin >> str;
        }
        int length_2 = (int)newstr.strLength();
        if (length_2 < 1)
        {
            cout << "Спочатку введіть рядок. Введіть вміст другого рядка: ";
            cin >> newstr;
        }
        commonstr = str + newstr;
        cout << "Утворений рядок: " << commonstr << endl;
        goto again;
    }
    case 5:
    {
        SetColor(2, 0);
        cout << "\nКількість літер у рядку \n" << endl;
        SetColor(7, 0);
        if (str.strLength() > 0)
        {
            cout << "Кількість літер у рядку '" << str << "': " << str.strLength() << endl;
        }
        else if (newstr.strLength() > 0)
        {
            cout << "Кількість літер у рядку '" << newstr << "': " << newstr.strLength() << endl;
        }
        else
        {
            MyString otherstr("");
            cout << "Спочатку введіть рядок. Введіть вміст нового рядка: ";
            cin >> otherstr;
            cout << "Кількість літер у рядку '" << otherstr << "': " << otherstr.strLength() << endl;
        }
        goto again;
    }
    case 6:
    {
        SetColor(2, 0);
        cout << "\nКількість певних літер в рядку\n" << endl;
        SetColor(7, 0);
        int length_1 = (int)str.strLength();
        if (length_1 < 1)
        {
            cout << "Спочатку введіть рядок. Введіть вміст нового рядка: ";
            cin >> str;
        }
        cout << "У рядку '" << str << "': " << endl;
        str.alphabetLetters();
        goto again;
    }
    case 7:
    {
        SetColor(2, 0);
        cout << "\nПошук слова у рядку\n" << endl;
        SetColor(7, 0);
        MyString phrase("Сьогодні ХНТУ – це сучасний потужний навчальний та науковий комплекс. У хнту створено всі умови для успішного навчання. Вступайте до ХнТу");
        MyString word("");
        cout << phrase << endl;
        //cout << commonstr << endl;
        cout << "Яке слово необхідно знайти? ";
        cin >> word;
        phrase.Search(word);
        //commonstr.Search(word);
        goto again;
    }
    case 8:
    {
        cout << "\nРоботу завершено" << endl;
        break;
    }
    default:
    {
        cout << "Виникла помилка. " << endl;
    }
    }
    return 0;
}