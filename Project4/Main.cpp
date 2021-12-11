#include "Node.h"
#include "Q1.h"
#include <iostream>
using namespace std;

int main(int argc)
{
    BinaryTree<int> bst;
    while (true)
    {
        int num;
        cout << "Enter node (-1 to exit): ";
        cin >> num;
        if (num == -1)
            break;
        bst.add(num);
        cout << "BST tree after insert: ";
        bst.display();
        cout << endl;
    }
    cout << "Final tree: " << endl;
    bst.display();
    cout << endl;
    return 0;
}
