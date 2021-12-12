#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Maze
{
private:
    int start[1];
    int end[1];
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
        visit(start[0], start[1]);
    }

    void visit(int x, int y)
    {

        if (x == end[0] && y == end[1])
        {
            hasPath = true;
            if (length < shortLength)
                shortLength = length;
            return;
        }
        visited[x][y] = 1;
        length++;
        //code-https://stackoverflow.com/questions/31737216/backtracking-maze :date 12/12/2021
        if (canVisit(x + 1, y))
        {
            visit(x + 1, y);
        }
        if (canVisit(x, y + 1))
        {
            visit(x, y + 1);
        }
        if (canVisit(x - 1, y))
        {
            visit(x - 1, y);
        }
        if (canVisit(x, y - 1))
        {
            visit(x, y - 1);
        }
        visited[x][y] = 0;
        length--;
    }

    ///code-https://www.codespeedy.com/rat-in-a-maze-problem-in-cpp/  :date 12/12/2021
    bool canVisit(int x, int y)
    {

        if (matrix[x][y] == 0 || visited[x][y] == 1)
            return false;
        return true;
    }

    void readMatrixFile(string filename)
    {
        ifstream input(filename);
        if (!input.is_open())
        {
            cout << "Could not open file for reading. Exiting..." << endl;
        }
        input >> M >> N;
        input >> start[0];
        input >> end[1];
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                input >> matrix[i][j];
            }
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
