#include "LongLong.h"

LongLong::LongLong() : LongLong(0, 0)
{}

LongLong::LongLong(long highPartValue, long lowPartValue)
        : highPart(highPartValue), lowPart(lowPartValue)
{
    if (lowPart < 0)
        lowPart = 0;
}

LongLong::LongLong(const LongLong &other)
        : highPart(other.highPart), lowPart(other.lowPart)
{}

long LongLong::getHighPart() const
{
    return highPart;
}

void LongLong::setHighPart(long value)
{
    highPart = value;
}

long LongLong::getLowPart() const
{
    return lowPart;
}

void LongLong::setLowPart(long value)
{
    if (value >= 0)
        lowPart = value;
}

LongLong operator-(const LongLong &num1, const LongLong &num2) {
    LongLong result;
    result.setHighPart(num1.getHighPart() - num2.getHighPart());
    result.setLowPart(num1.getLowPart() - num2.getLowPart());

    if (result.getLowPart() < 0) {
        result.setHighPart(result.getHighPart() - 1);
        result.setLowPart(result.getLowPart() + LONG_MAX + 1);
    }
    return result;
}

double operator/(const LongLong &num1, const LongLong &num2) {
    double numerator = num1.getHighPart() * (LONG_MAX + 1.0) + num1.getLowPart();
    double denominator = num2.getHighPart() * (LONG_MAX + 1.0) + num2.getLowPart();
    return numerator / denominator;
}

bool operator==(const LongLong &num1, const LongLong &num2)
{
    return num1.getHighPart() == num2.getHighPart() && num1.getLowPart() == num2.getLowPart();
}

bool operator!=(const LongLong &num1, const LongLong &num2)
{
    return !(num1 == num2);
}

bool operator>(const LongLong &num1, const LongLong &num2)
{
    if (num1.getHighPart() > num2.getHighPart())
        return true;

    if (num1.getHighPart() < num2.getHighPart())
        return false;

    return num1.getLowPart() > num2.getLowPart();
}

bool operator<(const LongLong &num1, const LongLong &num2)
{
    if (num1.getHighPart() < num2.getHighPart())
        return true;

    if (num1.getHighPart() > num2.getHighPart())
        return false;

    return num1.getLowPart() < num2.getLowPart();
}

bool operator>=(const LongLong &num1, const LongLong &num2)
{
    return !(num1 < num2);
}

bool operator<=(const LongLong &num1, const LongLong &num2)
{
    return !(num1 > num2);
}

LongLong &LongLong::operator++() {
    ++lowPart;
    return *this;
}

LongLong &LongLong::operator--() {
    --lowPart;
    return *this;
}

LongLong LongLong::operator++(int) {
    LongLong copy = *this;
    lowPart++;
    return copy;
}

LongLong LongLong::operator--(int) {
    LongLong copy = *this;
    lowPart--;
    return copy;
}

LongLong &LongLong::operator=(const LongLong &longLong)
{
    if (&longLong == this)
        return *this;

    highPart = longLong.highPart;
    lowPart = longLong.lowPart;
    return *this;
}

ostream &operator<<(ostream &out, const LongLong &longLong)
{
    out << "(h=" << longLong.highPart << ";l=" << longLong.lowPart << ")";
    return out;
}

istream &operator>>(istream &in, LongLong &longLong)
{
    in >> longLong.highPart;

    long lowPart;
    in >> lowPart;
    if (lowPart >= 0)
        longLong.lowPart = lowPart;

    return in;
}

LongLong::operator string() const {
    stringstream sout;
    sout << "(h=" << getHighPart() << ";l=" << getLowPart() << ")";
    return sout.str();
}

const char *LongLongException::what() const noexcept {
    return "LongLong exeption!";
}

const char *MyException::what() const noexcept {
    return "My exeption!";
}
