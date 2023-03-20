# String-Class
The project is written in the C++ programming language. The goal of the project is to create a class that will allow working with strings. The program involves the following actions:
- String input
- String output
- Addition (concatenation) of strings
- Assigning the value of one string to another
- Character-by-character comparison of two strings
- Lexicographic comparison, i.e. comparison of string lengths
- Calculation of the length of lines
- Determination of the number of certain letters in a string
- Search for a substring in a string
A class field is a dynamic array of characters.

<table>
     <caption>Class methods</caption>
      <tr>
        <td>Class method</td>
        <td>Return type</td>
        <td>Access specifier</td>
        <td>Purpose</td>
      </tr>
      <tr>
        <td>strLength</td>
        <td>int</td>
        <td>public</td>
        <td>Counting the number of characters in a string</td>
       </tr>
       <tr>
        <td>alphabetLetters</td>
        <td>void</td>
        <td>public</td>
        <td>Counting the number of certain letters in a string</td>
       </tr>
       <tr>
        <td>Search</td>
        <td>void</td>
        <td>public</td>
        <td>Finding a substring in a string</td>
       </tr>
       <tr>
        <td>Print</td>
        <td>void</td>
        <td>public</td>
        <td>String output in console</td>
       </tr>
    </table>
    
The following operators were overloaded:
- assignment operator: str = otherstr
- addition operator: newstr = str + otherstr
- operators equal to, not equal to: str == newstr, str != newstr
- input and output operators: cin >> str, cout << str;

Other member functions in the class include constructor, constructor overloading, destructor, copy constructor.

<table>
     <caption>Class diagram</caption>
      <tr>
        <td>My String</td>
      </tr>
      <tr>
        <td>#	str: char*</td>
       </tr>
       <tr>
        <td>+ MyString() <br>
+ MyString(const char* str) <br>
+ MyString(const MyString& other) <br>
+ strLength(const char* str): int <br>
+ strLength(): int <br>
+ alphabetLetters() <br>
+ Search() <br>
+ Print() <br>
+ ~MyString() <br>
</td>
       </tr>
    </table>
