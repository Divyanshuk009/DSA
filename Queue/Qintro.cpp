#include <iostream>
using namespace std;
#include <queue>
int main()
{
    // create a queue

    queue<int> q;

    q.push(12);
    q.push(34);
    q.push(42);

    cout << q.size() << endl;
    cout << q.front() << endl;

    q.pop();
    cout << q.size() << endl;
    // cout << q.size() << endl;

    return 0;
}