
#include <bits/stdc++.h>

using namespace std;

stack<char> S;

int priority(char s)
{
    if (s == '^')
        return 100;
    else if (s == '*' || s == '/')
        return 50;
    else if (s == '+' || s == '-')
        return 20;
    else
        return 0;
}

int apply(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    return 0;
}

//(12 + 3)

int main()
{
    string infix, postfix = " ";
    getline(cin, infix);

    for (int i = 0; i < infix.size(); i++)
    {

        char symbol = infix[i];

        if (isdigit(symbol))
        {
            while (i < infix.size() && isdigit(infix[i]))
            {
                postfix += infix[i];
                i++;
            }
            postfix += ' ';
            i--;
        }

        else if (symbol == '(')
        {
            S.push(symbol);
        }

        else if (symbol == ')')
        {
            while (!S.empty() && S.top() != '(')
            {
                postfix += S.top();
                postfix += ' ';
                S.pop();
            }
            S.pop();
        }

        else if (symbol == ' ')
        {
            continue;
        }

        else
        {
            while (!S.empty() && priority(S.top()) >= priority(symbol))
            {
                postfix += S.top();
                postfix += ' ';
                S.pop();
            }
            S.push(symbol);
        }
    }

    while (!S.empty())
    {
        postfix += S.top();
        postfix += ' ';
        S.pop();
    }

    cout << "Postfix: " << postfix << endl;

    stack<int> val;
    stringstream ss(postfix);
    string token;

    while (ss >> token)
    {
        if (isdigit(token[0]))
        {
            val.push(stoi(token));
        }
        else
        {
            int b = val.top();
            val.pop();
            int a = val.top();
            val.pop();
            val.push(apply(a, b, token[0]));
        }
    }

    cout << "Result: " << val.top() << endl;

    return 0;
}
