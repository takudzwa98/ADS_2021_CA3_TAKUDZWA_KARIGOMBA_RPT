#pragma once
#include <iostream>
using namespace std;
template<typename T>
struct Node
{
public:
    Node<T>* pLeft;
    Node<T>* pRight;
    T data;

    Node<T>(T data, Node<T>* left = nullptr, Node<T>* right = nullptr)
    {
        this->data = data;
        pLeft = left;
        pRight = right;
    }
};