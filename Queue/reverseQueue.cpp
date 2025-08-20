#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<int> rev(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        int elem = q.front();

        s.push(elem);
        q.pop();
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

    queue<int> num;
    num.push(3);
    num.push(4);
    num.push(5);
    num.push(6);

    cout << endl;

    cout << "Original queue:\n";
    queue<int> temp = num; // copy for printing without emptying
    while (!temp.empty())
    {
        cout << temp.front() << endl;
        temp.pop();
    }

    cout << endl;

    cout << "\nReversed queue:\n";
    num = rev(num); // store the returned reversed queue
    while (!num.empty())
    {
        cout << num.front() << endl;
        num.pop();
    }
}