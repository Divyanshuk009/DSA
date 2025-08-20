#include <bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        int elem = q.front();
        q.pop();
        s.push(elem);
    }

    while (!s.empty())
    {
        int elem = s.top();
        q.push(elem);
        s.pop();
    }
    return q;
}

int main()
{

    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    queue<int> m = q;

    cout << "original queue: " << endl;
    while (!m.empty())
    {
        cout << m.front() << endl;
        m.pop();
    }

    queue<int> n = rev(q);
    cout << "reversed queue: " << endl;
    while (!n.empty())
    {
        cout << n.front() << endl;
        n.pop();
    }
}