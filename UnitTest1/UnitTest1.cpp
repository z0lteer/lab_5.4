#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_5.4/5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 5;

			double result0 = P0(N);
			double result1 = P1(N, N);
			double result2 = P2(N, 10);
			double result3 = P3(N, N, 1);
			double result4 = P4(N, 10, 1);

			Assert::AreEqual(result0, result1, 0.0001, L"Error: P0 != P1");
			Assert::AreEqual(result0, result2, 0.0001, L"Error: P0 != P2");
			Assert::AreEqual(result0, result3, 0.0001, L"Error: P0 != P3");
			Assert::AreEqual(result0, result4, 0.0001, L"Error: P0 != P4");
		}
	};
}
