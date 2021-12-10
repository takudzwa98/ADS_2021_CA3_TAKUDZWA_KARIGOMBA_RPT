#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template<typename T>
class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(int numLevels);
    void add(T item);
    ~BinaryTree();

        BinaryTree()
        {
            root = nullptr;
            size = 0;
        }

private:
    Node<T>* root;
    int size;

    void insertT(T i, Node<T>* node)
    {
        if (i < node->val)
        {
            if (node->pLeft != nullptr)
                insertT(i, node->pLeft);
            else
            {
                node->pLeft = new Node<T>[i];
                node->pLeft->pLeft = nullptr;
                node->pLeft->pRight = nullptr;
            }
        }
        else if (i > node->val)
        {
            if (node->pRight != nullptr)
                insertT(i, node->pRight);
            else
            {
                node->pRight = new Node<T>[i];
                node->pRight->pLeft = nullptr;
                node->pRight->pRight = nullptr;
            }
        }
    }
 

};