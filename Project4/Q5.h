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
        if (visited)
        {
            for (int i = 0; i < M; i++)
                delete visited[i];
            delete visited;
        }
        if (matrix)
        {
            for (int i = 0; i < M; i++)
                delete matrix[i];
            delete matrix;
        }
    }
    void findPath()
    {
    
    }

   ///code-https://www.codespeedy.com/rat-in-a-maze-problem-in-cpp/ 
    bool canVisit(int x, int y)
    {
        if (x < 0 || y < 0 || x >= M || y >= N)
            return false;
        if (matrix[x][y] == 0 || visited[x][y] == 1)
            return false;
        return true;
    }

    void readMatrixFile(string filename)
    {
        ifstream input(filename);
        if (!input.is_open())
        {
            cout << "Could not open file" << endl;
        
        }
      
    }
    bool isHasPath()
    {
        return hasPath;
    }
    int getShortLength()
    {
        return shortLength;
    }
};
