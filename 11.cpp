#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isWellParenthesized(const string &expression)
{
    stack<char> charStack;
    for (char ch : expression)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            charStack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (charStack.empty())
            {
                return false;
            }
            char top = charStack.top();
            charStack.pop();
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return charStack.empty();
}
int main()
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    if (isWellParenthesized(expression))
    {
        cout << "The expression is well-parenthesized.\n";
    }
    else
    {
        cout << "The expression is not well-parenthesized.\n";
    }
    return 0;
}