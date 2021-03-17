//stack

#include<iostream>
#include "node.h"
// #include "FULL ADRESS OF FILE WHERE SAVED.h"
using namespace std;

class stack
    {
        node* head;
        int cs;
public:
    stack()
        {
            head=NULL;
            cs=0;
        }

    void push(int data)
        {
            node* n=new node(data);
            n->next=head;
            head=n;
            cs++;
        }

    void pop(int data)
        {
            if(cs==0)
            {
                return;
            }
            node* temp=head;
            head=head->next;
            delete temp;
            cs--;
        }

    int top()
        {
            return head->data;
        }

    bool empty()
        {
            return cs==0;
        }

    };

int main()
{
stack s;
for(int i=0;i<10;i++)
    {
    s.push(i);
    }
while(!s.empty())
    {
    cout<<s.top()<<endl;
    s.pop();
    }
return 0;
}
