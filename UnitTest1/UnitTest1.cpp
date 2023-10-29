#include "pch.h"
#include "CppUnitTest.h"
#include"cmath"
#include"..\main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double arr[] = { 1.123, 0.123, 0., 2.412, 7.523 };
			Assert::IsTrue(Sum_after_zero(arr, 5) -  9.935 < 10e-10);
		}
	};
}
