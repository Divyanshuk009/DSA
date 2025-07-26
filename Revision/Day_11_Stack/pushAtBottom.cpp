#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int> &s, int x)
{
    // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();

    // recursive call
    pushAtBottom(s, x);
    s.push(num);
}

int main()
{

    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    pushAtBottom(s, 9);
    pushAtBottom(s, 32);

    // Print all elements in the stack
    stack<int> temp = s;
    while (!temp.empty())
    {
        cout << temp.top() << " " << endl;
        temp.pop();
    }
    cout << endl;

    return 0;
}
