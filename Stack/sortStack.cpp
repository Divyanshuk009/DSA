#include <iostream>
using namespace std;
#include <stack>

void sortedInsert(stack<int> &s, int num)
{
    // base case

    if (s.empty() || (s.top() < num))
    {
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    // recursive call

    sortedInsert(s, num);
    s.push(n);
}

void sortStack(stack<int> &stack)
{
    // base case
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();
    // recursive call
    sortStack(stack);

    sortedInsert(stack, num);
}

int main()
{
    stack<int> st;

    st.push(32);
    st.push(22);
    st.push(42);
    st.push(12);

    stack<int> temp = st;

    cout << "Stack elements (top to bottom): ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(st);

    cout << "Stack elements (top to bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}