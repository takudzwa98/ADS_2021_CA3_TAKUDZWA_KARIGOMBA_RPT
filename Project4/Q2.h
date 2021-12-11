#pragma once
#include <iostream>
#include <vector>
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
    void buildBalanceTree()
    {
        vector<Node<T>*> nodes;
        sortNodeOrder(root, nodes);
        int n = nodes.size();
        root = buildBalanceTree(nodes, 0, n - 1);
    }
    void sortNodeOrder(Node<T>* root, vector<Node<T>*>& nodes)
    {
        if (root == NULL)
            return;
        sortNodeOrder(root->pLeft, nodes);
        nodes.push_back(root);
        sortNodeOrder(root->pRight, nodes);
    }
    Node<T>* buildBalanceTree(vector<Node<T>*>& nodes, int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = (start + end) / 2;
        Node<T>* newRoot = nodes[mid];
        newRoot->pLeft = buildBalanceTreeHelper(nodes, start, mid - 1);
        newRoot->pRight = buildBalanceTreeHelper(nodes, mid + 1, end);
        return newRoot;
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
    void sortNodeOrder(Node<T>* root, vector<Node<T>*>& nodes)
    {
        if (root == NULL)
            return;
        sortNodeOrder(root->pLeft, nodes);
        nodes.push_back(root);
        sortNodeOrder(root->pRight, nodes);
    }

};
