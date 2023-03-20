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
    MyString();  //конструктор класса без параметров

    MyString(const char* str); //перегрузка конструктора класса

    MyString(const MyString& other); //конструктор копирования

    MyString& operator = (const MyString& other) //перегрузка оператора = (копирование другой строки в строку в классе)
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

    MyString operator + (const MyString& other) //перегрузка оператора + (создание новой строки, которая объединяет 2 уже существующие)
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

    bool operator == (const MyString& other) //перегрузка оператора ==
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

    bool operator != (const MyString& other) //перегрузка оператора !=
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

    int strLength(const char* str); //метод класса - длина строки
    int strLength(); //перегрузка метода класса - длина строки
    void alphabetLetters(); //метод класса - кол-во определенных букв в слове (внезависимости от регистра)
    void Search(const MyString& other); //метод класса - поиск слова в строке, кол-во найденных совпадений
    void Print(); //метод класса - вывод строки

    ~MyString(); //деструктор

    friend ostream& operator <<(ostream& os, const MyString& str);
    friend istream& operator >>(istream& in, MyString& str);
    friend void SetColor(int text, int bg);
};

void SetColor(int text, int bg);
ostream& operator <<(ostream& os, const MyString& str); //перегрузка оператора вывода
istream& operator >>(istream& in, MyString& str); //перегрузка оператора ввода

#endif

