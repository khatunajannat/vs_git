#include <bits/stdc++.h>

using namespace std;

class Stack
{
    list<int> ll;

public:
    void push(int val)
    {

        ll.push_front(val);
    }

    void pop()
    {

        ll.pop_front();
    }

    int top()
    {

        return ll.front();
    }

    bool empty()
    {

        return ll.size() == 0;
    }
};

int main()
{

    Stack s;

    s.push(20);
    s.push(40);
    s.push(50);

    while (!s.empty())
    {

        cout << s.top() << endl;

        s.pop();
    }

    return 0;
}
