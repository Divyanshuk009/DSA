#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &inputStack, int count, int size)
{
    // base case
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // recursive call
    solve(inputStack, count + 1, size);

    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N);
}

int main()
{
    stack<int> st;

    // Push elements into the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5); // Top element

    cout << "Original stack (top to bottom): ";
    {
        stack<int> temp = st;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    deleteMiddle(st, st.size());

    cout << "Stack after deleting middle element: ";
    {
        stack<int> temp = st;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    return 0;
}
