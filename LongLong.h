#pragma once
#include <string>
#include <sstream>
#include <limits>
#include "Object.h"

using namespace std;

class LongLongException : public exception {
public:
    const char* what() const noexcept override;
};

class MyException{
public:
    const char* what() const noexcept;
};


class LongLong : public Object{
private:
    long highPart;
    long lowPart;

public:
    LongLong();
    LongLong(long highPartValue, long lowPartValue);
    LongLong(const LongLong &other);
    long getHighPart() const;
    void setHighPart(long value);
    long getLowPart() const;
    void setLowPart(long value);
    friend LongLong operator-(const LongLong &num1, const LongLong &num2);
    friend double operator/(const LongLong &num1, const LongLong &num2);
    friend bool operator==(const LongLong &num1, const LongLong &num2);
    friend bool operator!=(const LongLong &num1, const LongLong &num2);
    friend bool operator>(const LongLong &num1, const LongLong &num2);
    friend bool operator<(const LongLong &num1, const LongLong &num2);
    friend bool operator>=(const LongLong &num1, const LongLong &num2);
    friend bool operator<=(const LongLong &num1, const LongLong &num2);
    LongLong &operator++();
    LongLong &operator--();
    LongLong operator++(int);
    LongLong operator--(int);
    LongLong &operator=(const LongLong &longLong);
    friend ostream &operator<<(ostream &out, const LongLong &longLong);
    friend istream &operator>>(istream &in, LongLong &longLong);
    operator string() const;

};


