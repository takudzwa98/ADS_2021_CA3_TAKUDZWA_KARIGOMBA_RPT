#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template<typename T>
class BinaryTree
{

private:
    Node<T>* root;
    int size;

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

        void add(T item)
        {
            if (root != nullptr)
                insertT(item, root);
            else
            {
                root = new Node<T>(item);
                root->pLeft = nullptr;
                root->pRight = nullptr;
            }
            size++;
        }


    void insertT(T i, Node<T>* node)
    {
        if (i < node->data)
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
        else if (i > node->data)
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

    void display(Node<T>* p)
    {
        if (p != nullptr)
        {
            display(p->pLeft);
            cout << p->data << ;
            display(p->pRight);
        }
    }

    void destroy(Node<T>* node)
    {
        if (node != nullptr)
        {
            destroy(node->pLeft);
            destroy(node->pRight);
            delete node;
        }
    }
 

};