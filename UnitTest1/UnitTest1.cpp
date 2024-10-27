#include "pch.h"
#include "CppUnitTest.h"
#include "../6,1(2)/6,1(2).cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61
{
    TEST_CLASS(UnitTest61)
    {
    public:

        TEST_METHOD(TestCountAndSum)
        {
            const int size = 5;
            int testArray[size] = { 1, 2, -3, 5, -7 };
            int count = 0;
            int sum = 0;

            countAndSumRecursive(testArray, size, 0, count, sum);

            if (count == 2 && sum == 6) {
                std::cout << "TestCountAndSum passed." << std::endl;
            }
            else {
                std::cout << "TestCountAndSum failed: count = " << count << ", sum = " << sum << std::endl;
            }
        }

        TEST_METHOD(TestReplaceWithZero)
        {
            const int size = 5;
            int testArray[size] = { 1, 2, -3, 5, -7 };
            int expectedArray[size] = { 0, 2, -3, 0, -7 };

            replaceWithZeroRecursive(testArray, size, 0);

            bool passed = true;
            for (int i = 0; i < size; i++) {
                if (testArray[i] != expectedArray[i]) {
                    passed = false;
                    break;
                }
            }

            if (passed) {
                std::cout << "TestReplaceWithZero passed." << std::endl;
            }
            else {
                std::cout << "TestReplaceWithZero failed." << std::endl;
            }
        }

        TEST_METHOD(TestGenerateArray)
        {
            const int size = 10;
            int testArray[size];
            generateArray(testArray, size, -25, 80);

            bool valid = true;
            for (int i = 0; i < size; i++) {
                if (testArray[i] < -25 || testArray[i] > 80) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                std::cout << "TestGenerateArray passed." << std::endl;
            }
            else {
                std::cout << "TestGenerateArray failed." << std::endl;
            }
        }
    };
}
