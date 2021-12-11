#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template<typename T>
class BinaryTree
{
public:
    BinaryTree()
    {
        root = nullptr;
        size = 0;
    }
    BinaryTree(int numLevels);
    void add(T item)
    {
        if (root != nullptr)
            addItem(item, root);
        else
        {
            root = new Node<T>(item);
            root->pLeft = nullptr;
            root->pRight = nullptr;
        }
       size++;
    }
    void remove()
    {
        removeT(root);
    }
    ~BinaryTree()
    {
        removeT(root);
    }
    void display()
    {
        display(root);
    }
private:
    Node<T>* root;
    int size;

    void addItem(T i, Node<T>* node)
    {
        if (i < node->data)
        {
            if (node->pLeft != nullptr)
                addItem(i, node->pLeft);
            else
            {
                node->pLeft = new Node<T>(i);
                node->pLeft->pLeft = nullptr;
                node->pLeft->pRight = nullptr;
            }
        }
        else if (i > node->data)
        {
            if (node->pRight != nullptr)
                addItem(i, node->pRight);
            else
            {
                node->pRight = new Node<T>(i);
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
    void removeT(Node<T>* node)
    {
        if (node != nullptr)
        {
            removeT(node->pLeft);
            removeT(node->pRight);
            delete node;
        }
    }
};
