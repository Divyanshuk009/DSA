#include <iostream>

using namespace std;

int binSearch(int num[], int size, int key)
{

    int start = 0;
    int end = size - 1;

    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (num[mid] == key)
        {
            return mid;
        }
        if (key > num[mid])
        {

            start = mid + 1;
            /* code */
        }
        else
        {
            end = mid - 1;
        }

        mid = (start + end) / 2;
    }
    return -1;
}

int main()
{

    int gun[6] = {4, 5, 6, 11, 12, 59}; // should be sorted

    int index = binSearch(gun, 6, 11);

    cout << "index of 11 is: " << index << endl;
}