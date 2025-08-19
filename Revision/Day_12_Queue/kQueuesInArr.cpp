#include <bits/stdc++.h>
using namespace std;

class kQueue
{

public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;

public:
    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {

            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];

        for (int i = 0; i < n; i++)
        {

            next[i] = i + 1;
        }

        next[n - 1] = -1;

        arr = new int[n];
        freeSpot = 0;
    }

    void enqueue(int data, int qn)
    {
        // overflow

        if (freeSpot == -1)
        {
            cout << "not empty space is present" << endl;
            return;
        }
        // find first free space
    }
};