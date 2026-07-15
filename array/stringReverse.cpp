#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[] = "hello there";

    int len = strlen(str);

    int start = 0;
    int end = len - 1;

    while (start < end)
    {
        char temp = str[start];

        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
    cout << "Reversed string: " << str << endl;
}