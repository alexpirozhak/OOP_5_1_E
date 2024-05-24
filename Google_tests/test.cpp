#include "gtest/gtest.h"
#include "../Object.h"

TEST(ObjectTest, CounterTest) {
    // Перевірка, чи початковий рахунок дорівнює 0
    EXPECT_EQ(Object::getCounter(), 0);

    // Створення об'єкта
    Object obj1;
    // Перевірка, чи рахунок збільшився на 1
    EXPECT_EQ(Object::getCounter(), 1);

    // Створення ще одного об'єкта
    Object obj2;
    // Перевірка, чи рахунок збільшився на 1
    EXPECT_EQ(Object::getCounter(), 2);

    // Видалення об'єкта
    obj1.~Object();
    // Перевірка, чи рахунок зменшився на 1
    EXPECT_EQ(Object::getCounter(), 1);
}
