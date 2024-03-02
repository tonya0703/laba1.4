#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1.4/Matrix.h"
#include "../Project1.4/Matrix.cpp"
#include "../Project1.4/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest14
{
	TEST_CLASS(UnitTest14)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix matrix;
			matrix.setRows(2);
			matrix.setCols(3);
			int t1, t2;
			t1 = matrix.getCols();
			t2 = matrix.getRows();
			Assert::AreEqual(2, t2);
			Assert::AreEqual(3, t1);
		}
	};
}
