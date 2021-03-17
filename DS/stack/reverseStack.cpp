//Without storing
#include<iostream>
#include<stack>
using namespace std;

void pushBottom(stack<int> &s,int top)
    {
        if(s.empty())
        {
            s.push(top);
            return;
        }

        int topelement=s.top();
        s.pop();
        pushBottom(s,top);
        s.push(topelement);
    }

void ReverseStack(stack<int> &s)
    {

        int top=s.top();
        s.pop();
        ReverseStack(s);
        pushBottom(s,top);

    }

void print

int main()
{




    return 0;
}
