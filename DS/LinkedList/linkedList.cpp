#include<iostream>
using namespace std;

class node
    {
    public:

    int data;
    node* next;

    //CONSTRUCTOR
    node(int d):data(d),next(NULL)
    {
    }

    //DESTRUCTOR
    ~node()
    {
        if(next!=NULL)
        {
            cout<<"DELETING "<<data<<endl;
            delete next;
            next=NULL;
        }
    }

    };

class linkedlist
    {
private:
        node* recursiveSearchHelper(node* head,int d)
        {
        //BAse case
        if(head==NULL)
        {
            return NULL;
        }
        //recursive
        if(head->data==d)
        {
            return head;
        }
        return recursiveSearchHelper(head->next,d);
        }

public:
    node* head;
    node* tail;

    linkedlist():head(NULL),tail(NULL)
    {
    }

    void InsertAtFront(int d)
    {
        if(head==NULL)
        {
            head=tail=new node(d);
        }
        else
        {
        node* n=new node(d);
        n->next=head;
        head=n;
        }
    }

    void InsertAtEnd(int d)
    {
        if(head==NULL)
        {
            head=tail=new node(d);
        }
        else
        {
        node* n=new node(d);
        tail->next=n;
        tail=n;
        }
    }

    void InsertAtMid(int d,int pos)
    {
        if(pos==0)
        {
            InsertAtFront(d);
        }
        else if(pos>=length())
        {
            InsertAtEnd(d);
        }
        else
        {
            int p=1;
            node*temp = head;
            while(p<=pos-1)
            {
                temp=temp->next;
                p++;
            }
            node* n= new node(d);
            n->next=temp->next;
            temp->next=n;
        }
    }

    node* search(int d)
    {
        node* temp= head;

        while(temp!=NULL)
        {
            if(temp->data==d)
            {
                return temp;
            }
            temp=temp->next;
        }
    }

    void DeleteAtFront()
    {
        if(head==NULL)
        {
            return;
        }
        else if(head->next==NULL)
        {
            delete head;
            head=tail=NULL;
        }
        else
        {
        node* temp=head;
        head=head->next;
        delete temp;
        }
    }

    void DeleteAtEnd()
    {
        if(head==NULL)
        {
            return;
        }
        else if(head->next==NULL)
        {
            delete head;
            head=tail=NULL;
        }
        else
        {
            node* temp=head;
            while(temp->next!=tail)
            {
                temp=temp->next;
            }
            delete tail;
            temp->next=NULL;
            tail=temp;
        }
    }

    void DeleteAtMid(int pos)
    {
        if(pos==0)
        {
            DeleteAtFront();
        }
        else if(pos>length())
        {
            DeleteAtEnd();
        }
        else
        {
        node* temp=head;
        int ctr=0;
        while(ctr<=pos-1)
            {
            temp=temp->next;
            ctr++;
            }
        node* n=temp->next;
        temp->next=n->next;
        n->next=NULL;
        delete n;
        }

    }

    void print()
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<"NULL";
        cout<<endl;
    }

    node* mid()
    {
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

    int length()
    {
        int ctr=0;
        node* temp=head;
        while(temp!=NULL)
        {
            ctr++;
            temp=temp->next;
        }
        return ctr;
    }

    //SEARCH BY RECURSION

    node* recursiveSearch(int d)
    {
        return recursiveSearchHelper(head,d);
    }


    ~linkedlist()
    {
        if(head!=NULL)
        {
            delete head;
            head=tail=NULL;
        }
    }

    };

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



int main()
{
/*    node n(2);
    node n1(3);
    n.next=&n1;
    cout<<n.data<<<endl;
    cout<<((*n.next).data)<<endl;
    cout<<((n.next)->data)<<endl;   */

    linkedlist l;
    l.InsertAtFront(1);
    l.InsertAtFront(2);
    l.InsertAtFront(3);
    l.InsertAtFront(4);
    l.InsertAtEnd(5);
    l.InsertAtEnd(6);
    l.InsertAtMid(7,3);

        l.print();

    node* answer=l.recursiveSearch(5);
    cout<<"FOUND :"<<answer->data<<endl;
    l.print();
    cout<<"LENGTH IS :"<<l.length()<<endl;


    node* ans=l.search(4);
    cout<<"Found "<<(ans->data)<<endl;

  //  l.DeleteAtFront();
  //  l.DeleteAtEnd();
    l.DeleteAtMid(2);
    l.print();

return 0;
}
