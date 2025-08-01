#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        // if opening bracket, stack push
        // if close bracket, stack top check and pop

        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            // for closing bracket
            if (!s.empty())
            {
                char top = s.top();
                if (
                    (ch == '}' && top == '{') ||
                    (ch == ')' && top == '(') ||
                    (ch == ']' && top == '['))
                {
                    s.pop(); // remove the top element from the stack
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return s.empty();
}

int main()
{
    string test1 = "(){}[]";
    string test2 = "({[]})";
    string test3 = "({[})";
    string test4 = "((())";

    cout << test1 << " : " << (isValidParenthesis(test1) ? "Valid" : "Invalid") << endl;
    cout << test2 << " : " << (isValidParenthesis(test2) ? "Valid" : "Invalid") << endl;
    cout << test3 << " : " << (isValidParenthesis(test3) ? "Valid" : "Invalid") << endl;
    cout << test4 << " : " << (isValidParenthesis(test4) ? "Valid" : "Invalid") << endl;

    return 0;
}
