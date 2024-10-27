#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_8_1_it/lab_8_1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCount)
        {
            char testStr1[] = "This is a while test while and another while.";
            char cs[] = "while";
            Assert::AreEqual(3, Count(testStr1, cs));

            char testStr2[] = "No matches here.";
            Assert::AreEqual(0, Count(testStr2, cs));


            char testStr4[] = "whilewhilewhile";
            Assert::AreEqual(3, Count(testStr4, cs));
        }

        // Тестуємо функцію Change
        TEST_METHOD(TestChange)
        {

            char testStr2[] = "No while here.";
            char expectedOutput2[] = "No *** here.";
            Change(testStr2); // Використовуємо самозмінювальний рядок
            Assert::AreEqual(expectedOutput2, testStr2);

            char testStr3[] = "while while while";
            char expectedOutput3[] = "*** *** ***";
            Change(testStr3); // Використовуємо самозмінювальний рядок
            Assert::AreEqual(expectedOutput3, testStr3);
        }

	};
}
