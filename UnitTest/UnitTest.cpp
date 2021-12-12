#include "pch.h"
#include "CppUnitTest.h"
using namespace std;
#include "../Project4/Q1.h"
#include "../Project4/Q2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestAdd)
		{
			Node<int>* node;
			int i = 1;
			node->pLeft = new Node<int>(i);
			node->pRight = new Node<int>(i);
			Assert::AreEqual(1, node->data);
		}

		TEST_METHOD(TestRemove)
		{
			Node<int>* node;
			int i = 1;
			node->pLeft = new Node<int>(i);
			node->pRight = new Node<int>(i);
			delete node;
			Assert::AreEqual(0, node->data);

		}
		TEST_METHOD(TestbuildBalanceTre)
		{
			int start = 4;
			int end = 4;
			int mid = (start + end) / 2;
			Node<int>* node;
			node->pLeft = new Node<int>(mid);
			node->pRight = new Node<int>(mid);
			Assert::AreEqual(4, node->data);

		}
	};
}
