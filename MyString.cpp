#include "MyString.h"

using namespace std;

MyString::MyString() { //����������� ������ ��� ����������
    str = nullptr;
}

MyString::MyString(const char* str) //���������� ������������ ������
{
    int length = strLength(str);
    this->str = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        this->str[i] = str[i];

    }
    this->str[length] = '\0';
}

MyString::MyString(const MyString& other) //����������� �����������
{
    int length = strLength(other.str);
    this->str = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        this->str[i] = other.str[i];

    }
    this->str[length] = '\0';
}

int MyString::strLength(const char* str) //����� ������ - ����� ������
{
    int number = 0;
    for (int i = 0; i < number + 1; i++)
    {
        if (str[i] != '\0')
        {
            number++;
        }
    }
    return number;
}

int MyString::strLength() //���������� ������ ������ - ����� ������
{
    int number = 0;
    int space = 0;
    for (int i = 0; i < number + 1; i++)
    {
        if (this->str[i] != '\0')
        {
            number++;
        }
        if (this->str[i] == ' ')
        {
            space++;
        }
        if (this->str[i] == ',')
        {
            space++;
        }
        if (this->str[i] == '.')
        {
            space++;
        }
        if (this->str[i] == '!')
        {
            space++;
        }
    }
    return (number - space);
}

void MyString::alphabetLetters() //����� ������ - ���-�� ������������ ���� � ����� (�������������� �� ��������)
{
    char alphabet[192];
    int j = 65;
    int m = 192;
    int i;
    for (i = 0; i < 26; i++)
    {
        alphabet[i] = (char)j;
        j++;
    }
    for (; i < 58; i++)
    {
        alphabet[i] = (char)m;
        m++;
    }
    int number[192] = { 0 };
    bool high = false;
    for (int x = 0; x < 58; x++)
    {
        for (int k = 0; k < (int)strlen(this->str); k++)
        {
            if (this->str[k] == '�')
            {
                this->str[k] = '�';
                high = true;
            }
            if (tolower(alphabet[x]) == tolower(this->str[k]))
            {
                number[x]++;
                if (high == true && this->str[k] == '�')
                {
                    this->str[k] = '�';
                    high = false;
                }
            }
        }
    }
    for (int x = 0; x < 192; x++)
    {
        if (number[x] > 0)
        {
            cout << "˳���� '" << alphabet[x] << "' ����������� " << number[x] << " ���(��)." << endl;
        }
    }
}

void MyString::Search(const MyString& other) //����� ������ - ����� ����� � ������, ���-�� ��������� ����������
{
    cout << "\n����� ����� '" << other.str << "' � ��������������� �����:\n" << endl;
    bool presense = false;
    int i = 0;
    int j;
    int count = 0;
    int size = strLength(other.str) - 1;
    for (; i < strLength(this->str); )
    {
        cout << this->str[i];
        j = 0;
        if (tolower(this->str[i]) == tolower(other.str[j]))
        {
            if ((i > 0 && (this->str[i - 1] == ' ')) || i == 0)
            {
                for (; j < (int)strLength(other.str); )
                {
                    if (j != (int)strLength(other.str))
                    {
                        if (tolower(this->str[i + size]) == tolower(other.str[size]))
                        {
                            cout << "\b";
                            while (tolower(this->str[i]) == tolower(other.str[j]))
                            {
                                SetColor(2, 0);
                                cout << this->str[i];
                                presense = true;
                                i++;
                                j++;
                                if (j == (int)strLength(other.str))
                                {
                                    count++;
                                    SetColor(7, 0);
                                    break;
                                }
                            }
                            cout << " ";
                            presense = false;
                        }

                    }
                    if (presense == false)
                    {
                        i++;
                        break;
                    }
                }
            }
            else
            {
                i++;
            }
        }
        else i++;
    }
    if (count > 0)
    {
        cout << "\nʳ������ ����: " << count << endl;
    }
    else
    {
        cout << "\n���� �� ��������.";
    }
}

void MyString::Print() //����� ������ - ����� ������
{
    cout << str;
}

MyString::~MyString() //����������
{
    delete[] this->str;
};

ostream& operator <<(ostream& os, const MyString& str) //���������� ��������� ������
{
    for (int i = 0; i < (int)strlen(str.str); i++)
        os << str.str[i];
    os;
    return os;
}

istream& operator >>(istream& in, MyString& str) //���������� ��������� �����
{
    cin.ignore(cin.rdbuf()->in_avail());
    char* input_data = nullptr;
    int counter = 0;
    char symbol;
    while (true) {
        if ((symbol = in.get()) != '\n') {
            input_data = (char*)realloc(input_data, ++counter);
            input_data[counter - 1] = symbol;
        }
        else {
            input_data = (char*)realloc(input_data, ++counter);
            input_data[counter - 1] = '\0';
            break;
        }
    }
    str = input_data;
    delete input_data;
    return in;
}

void SetColor(int text, int bg) 
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

template<int txt = 7, int bg = 0>
ostream& color(ostream& text) 
{
    SetColor(txt, bg);
    return text;
}