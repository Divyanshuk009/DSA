#include <iostream>
using namespace std;

int main()
{

    int arr[10];

    cout << arr << " (address)" << endl;
    cout << &arr[0] << " (address)" << endl;
    cout << *arr << " (garbage value)" << endl;
    cout << arr[0] << " (garbage value)" << endl;
    cout << sizeof(arr) << " (total size of arr 4*10= 40B)" << endl;
    cout << endl;

    int num[5] = {6, 2, 6};

    cout << *num << " (first element value)" << endl;
    cout << *(num + 1) << " (2nd element value)" << endl;
    cout << (num + 1) << " (2nd element address)" << endl;
    cout << *(num) + 1 << " (first element increment)" << endl;

    cout << *num + 1 << " (first element increment)" << endl;

    cout << sizeof(num) << " (total size of arr 2*10= 20B)" << endl;
    cout << sizeof(*num) << " (size of 1st element= 4B)" << endl;
    cout << sizeof(&num) << " (	Size of pointer to array)" << endl;
}