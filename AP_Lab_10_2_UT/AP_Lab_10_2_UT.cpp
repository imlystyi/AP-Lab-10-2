// ����������� ���������, ��Ͳ, в-11, ��, unit-���� �� 10.2, ������ 24
#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab_10_2/AP_Lab_10_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace APLab102UT
{
	TEST_CLASS(APLab102UT)
	{
	public:
		
		TEST_METHOD(TestChangeString)
		{
			string stringToChange = "aaaa(bbbb(ccc)cc)dddd", actualString, expectedString = "aaaadddd";

			actualString = ChangeString(stringToChange);

			Assert::AreEqual(expectedString, actualString);
		}
	};
}
