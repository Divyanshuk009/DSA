#include <iostream>
using namespace std;
#include <stack>
#include <vector>

vector<int> nextSmallerElement(vector<int> arr, int n)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }

        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}
int main()
{
    vector<int> arr = {2, 4, 1, 5, 3};

    nextSmallerElement(arr, 5);

    return 0;
}