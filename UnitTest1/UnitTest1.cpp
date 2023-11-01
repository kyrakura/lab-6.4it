#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 6.4/lab 6.4.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
    public:
        TEST_METHOD(TestMethod1)
        {
            int n = 10; 
            int* a = new int[n];
            int Low = -11;
            int High = 13;
            Create(a, n, Low, High);
            Assert::AreEqual(13, MaxElement(a, n), 0.0001);
        }

        TEST_METHOD(TestMethod2)
        {
            int n = 10; 
            int* a = new int[n];
            int Low = -11;
            int High = 13;
            Create(a, n, Low, High);
            Assert::AreEqual(-6, Sum(a, n), 0.0001);
        }

        TEST_METHOD(TestMethod3)
        {
            int n = 10; 
            int* a = new int[n];
            int newSize = n;
            int Low = -11;
            int High = 13;
            int aVal = 1, bVal = 10;
            Create(a, n, Low, High); 
            ModArray(a, newSize, aVal, bVal);
            Assert::AreEqual(0, Sum(a, newSize), 0.0001);
        }
    };
}