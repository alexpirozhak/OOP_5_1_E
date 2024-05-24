#include <iostream>
#include "LongLong.h"
using namespace std;

int main()
{
    LongLong num1, num2;

    cout << "Enter num1 (highPart lowPart): ";
    cin >> num1;
    cout << "Enter num2: ";
    cin >> num2;
    cout << endl;

    if (num1 == num2)
        cout << "num1 == num2" << endl;
    if (num1 != num2)
        cout << "num1 != num2" << endl;
    if (num1 > num2)
        cout << "num1 > num2" << endl;
    if (num1 < num2)
        cout << "num1 < num2" << endl;
    if (num1 >= num2)
        cout << "num1 >= num2" << endl;
    if (num1 <= num2)
        cout << "num1 <= num2" << endl;
    cout << endl;

    cout << "num1 - num2 = " << num1 - num2 << endl;
    cout << "num1 / num2 = " << num1 / num2 << endl;

    num1++;
    cout << "Incremented num1: " << num1 << endl;
    num2--;
    cout << "Decremented num2: " << num2 << endl << endl;


    cout << "counter: " << Object::getCounter() << endl;

    try {
        throw bad_exception();
    }
    catch (const bad_exception& e)
    {
        cerr<<"Error:" << e.what() << '\n';
    }

    try {
        throw bad_exception();
    }
    catch (bad_exception e)
    {
        cerr<<"Error:" << e.what() << '\n';
    }

    try {
        throw new bad_exception();

    }
    catch (bad_exception* e) {
        std::cerr << "Error:: " << e->what() << '\n';
        delete e;
    }


    try{
        throw LongLongException();

    }
    catch (const LongLongException& e) {
        cerr<<"Error:" << e.what() << '\n';
    }

    try {
        throw MyException();
    }
    catch (const MyException& e) {
        std::cerr << "Error:: " << e.what() << '\n';
    }

    try {
        throw MyException();
    }
    catch (const MyException e) {
        std::cerr << "Error:: " << e.what() << '\n';
    }

    try {
        throw MyException();
    }
    catch (MyException e) {
        std::cerr << "Error:: " << e.what() << '\n';
    }
    catch (MyException* e) {
        std::cerr << "Error:: " << e->what() << '\n';
    }
}