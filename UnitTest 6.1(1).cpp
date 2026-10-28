#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 6.1(1)./Project 6.1(1).cpp" // Підключаємо файл з вашим основним кодом або опустіть цей рядок і винесіть функції вище


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest611
{
    TEST_CLASS(UnitTest611)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int size = 5;
            int c[size] = { 15, 17, 20, 21, 30 };

            // 1. Перевірка кількості
            int actualCount = Count(c, size, 0);
            Assert::AreEqual(2, actualCount);

            // 2. Перевірка суми
            int actualSum = Sum(c, size, 0);
            Assert::AreEqual(38, actualSum);

            // 3. Перевірка заміни нулями
            Zero(c, size, 0);
            int expectedArray[size] = { 15, 0, 20, 0, 30 };
            for (int i = 0; i < size; i++) {
                Assert::AreEqual(expectedArray[i], c[i]);
            }
        }
    };
}