#include <iostream>

using namespace std;
 
void printArray(int arr[], int size)
{
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int data[5] = {23, 4, 5, 43, 50};

    printArray(data, 4);

    int student[3] = {3, 5, 6};

    printArray(student, 2);
}