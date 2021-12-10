#pragma once
#include <iostream>
using namespace std;
template<typename T>
struct Node
{
public:
    Node<T>* pLeft;
    Node<T>* pRight;
    T val;

    Node<T>(T val, Node<T>* left = nullptr, Node<T>* right = nullptr)
    {
        this->val = val;
        pLeft = left;
        pRight = right;
    }
};