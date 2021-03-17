#include<iostream>
using namespace std;

class node
{
public:
int data;
node* next;
node(int d):data(d),next(NULL)
    {
    }
};

node* CreateLL()
    {
    node* head=NULL;
    int data;
    cin>>data;

    while(data!=-1)
        {
        node* n= new node(data);
        n->next=head;
        head=n;

        cin>>data;
        }
    return head;
    }

int length(node* head)
    {
        int count=0;
        while(head)
        {
            count++;
            head=head->next;
        }
    return count;
    }

void print(node* head)
    {
    while(head)
        {
        cout<<head->data<<"-->";
        head=head->next;
        }
    cout<<endl;
    }

void bubblesort(node* &head)
    {
        int len=length(head);
        node* current;
        node* prev;
        node* n;
        for(int i=0;i<len;i++)
        {
            current=head;
            prev=NULL;
            while(current && current->next)
            {
                n=current->next;
                if(current->data > n->data )
                {
                    //if swapping horhi
                    if(prev==NULL)
                    {
                        //if previous is null
                        current->next=n->next;
                        n->next=current;
                        head=n;
                        prev=n;
                    }
                    else
                    {
                        //if prev not null
                        current->next=n->next;
                        prev->next=n;
                        n->next=current;
                        prev=n;
                    }


                }

                else
                {
                    //swapping nhi horhi
                    prev=current;
                    current=n;
                }
            }


        }
    }

void ReverseLL(node* &head)
    {
        node* current=head;
        node* prev=NULL;
        node* n;
        while(current!=NULL)
        {
            n=current->next;
            current->next=prev;
            prev=current;
            current=n;
        }
        head=prev;
    }

node* mid(node* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        node* slow=head;
        node* fast=head->next;

        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }

node* merge(node* a,node* b)
    {
        //base case
        if(a==NULL)
        {
            return b;
        }
        if(b==NULL)
        {
            return a;
        }
        //RECURSIVE
    node* c;
    if(a->data<b->data)
    {
        c=a;
        c->next=merge(a->next,b);
    }
    else
    {
        c=b;
        c->next=merge(a,b->next);
    }

    }

node* mergeSort(node* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        node* m=mid(head);
        node* a=head;
        node* b=m->next;
        m->next=NULL;

        a=mergeSort(a);
        b=mergeSort(b);

        node* newHead = merge(a,b);
        return newHead;
    }

int main()
{
    node* head=CreateLL();
    print(head);
    bubblesort(head);
    cout<<"Bubble sort"<<endl;
    print(head);
    ReverseLL(head);
    cout<<"REVERSE "<<endl;
    print(head);
    head=mergeSort(head);
    cout<<"Merge sort "<<endl;
    print(head);
    return 0;
}
