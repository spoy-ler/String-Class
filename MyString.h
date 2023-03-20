#pragma once

#ifndef MyString_H
#define MyString_H

#include <iostream>
#include <clocale>
#include <windows.h>
#include <cctype>
using namespace std;

class MyString {
private:
    char* str;
public:
    MyString();  //����������� ������ ��� ����������

    MyString(const char* str); //���������� ������������ ������

    MyString(const MyString& other); //����������� �����������

    MyString& operator = (const MyString& other) //���������� ��������� = (����������� ������ ������ � ������ � ������)
    {
        if (this->str != nullptr)
        {
            delete[] str;
        }
        int length = strLength(other.str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];

        }
        this->str[length] = '\0';
        return *this;
    }

    MyString operator + (const MyString& other) //���������� ��������� + (�������� ����� ������, ������� ���������� 2 ��� ������������)
    {
        MyString newStr;
        int thisLength = strLength(this->str);
        int otherLength = strLength(other.str);
        newStr.str = new char[thisLength + otherLength + 2];
        int i = 0;
        for (; i < thisLength; i++)
        {
            newStr.str[i] = this->str[i];
        }
        newStr.str[thisLength] = ' ';
        i++;
        for (int j = 0; j < otherLength; j++, i++)
        {
            newStr.str[i] = other.str[j];
        }
        newStr.str[thisLength + otherLength + 1] = '\0';
        return newStr;
    }

    bool operator == (const MyString& other) //���������� ��������� ==
    {
        bool equality = false;
        if (strLength(this->str) == strLength(other.str))
        {
            for (int i = 0; i < strLength(this->str); i++)
            {
                equality = false;
                if (this->str[i] == other.str[i])
                {
                    equality = true;
                }
            }
        }
        return equality;
    }

    bool operator != (const MyString& other) //���������� ��������� !=
    {
        bool equality = false;
        if (strLength(this->str) == strLength(other.str))
        {
            for (int i = 0; i < strLength(this->str); i++)
            {
                equality = false;
                if (this->str[i] == other.str[i])
                {
                    equality = true;
                }
            }
        }
        return !(equality);
    }

    int strLength(const char* str); //����� ������ - ����� ������
    int strLength(); //���������� ������ ������ - ����� ������
    void alphabetLetters(); //����� ������ - ���-�� ������������ ���� � ����� (�������������� �� ��������)
    void Search(const MyString& other); //����� ������ - ����� ����� � ������, ���-�� ��������� ����������
    void Print(); //����� ������ - ����� ������

    ~MyString(); //����������

    friend ostream& operator <<(ostream& os, const MyString& str);
    friend istream& operator >>(istream& in, MyString& str);
    friend void SetColor(int text, int bg);
};

void SetColor(int text, int bg);
ostream& operator <<(ostream& os, const MyString& str); //���������� ��������� ������
istream& operator >>(istream& in, MyString& str); //���������� ��������� �����

#endif

