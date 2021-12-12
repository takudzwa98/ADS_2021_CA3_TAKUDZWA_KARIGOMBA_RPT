#include "pch.h"
#include "CppUnitTest.h"
using namespace std;
#include "../Project4/Q1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestAdd)
		{
			Node<int>* node;
			node->pLeft = 1;
			Assert::AreEqual(1 , node->data.);
		}

		TEST_METHOD(TestRemove)
		{
			Node<int>* node;
			removeT(node);
			Assert::AreEqual(0, node.);
		}
	};
}
