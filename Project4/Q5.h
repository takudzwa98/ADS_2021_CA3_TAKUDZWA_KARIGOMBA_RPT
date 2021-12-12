#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Maze
{
private:
    int start;
    int end;
    int** visited;
    int shortLength = INT_MAX;
    int length = 0;
    bool hasPath = false;
    int** matrix;
    int N, M;

public:

    Maze()
    {

    }
    ~Maze()
    {
  
    }
    void findPath()
    {
    
    }
    bool canVisit(int x, int y)
    {
   
    }

    void readMatrixFile(string filename)
    {

    }
    bool isHasPath()
    {
 
    }
    int getShortLength()
    {

    }
};
