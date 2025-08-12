#include <iostream>
using namespace std;
#include <stack>

void pushAtBottom(stack<int> &s, int n)
{
    if (s.empty())
    {
        s.push(n);
        return;
    }

    int num = s.top();
    s.pop();
    pushAtBottom(s, n);
    s.push(num);
}

int main()
{

    stack<int> s;
    s.push(4);
    s.push(5);
    s.push(2);

    pushAtBottom(s, 9);
    pushAtBottom(s, 12);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    cout << endl;

    return 0;
}