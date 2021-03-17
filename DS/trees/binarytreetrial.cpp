#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
    node* left;
    node* right;
    int data;

    node(int d) : data(d),left(NULL),right(NULL)
    {
    }

};

node* buildTree()
    {
    int data;
    cin>>data;

    if(data==-1)
        {
        return NULL;
        }
    else
        {
        node* root=new node(data);
        root->left=buildTree();
        root->right=buildTree();
        return root;
        }
    }

void PreOrder(node* root)
    {
        if(root==NULL)
        {
            return;
        }
        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

void InOrder(node* root)
    {
        if(root==NULL)
        {
            return;
        }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
    }

void PostOrder(node* root)
    {
        if(root==NULL)
        {
            return;
        }

        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" ";
    }

int countNodes(node* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }

int height(node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);

    return max(leftHeight,rightHeight)+1;

    }

int Diameter(node* root)
    {
        if(root==NULL)
        {
        return 0;
        }

        int op1=height(root->left)+height(root->right);
        int op2=Diameter(root->left);
        int op3=Diameter(root->right);
        return max(op1,max(op2,op3));
    }
/*
class Pair
    {
        public:
        int Height;
        int diameter;
    };
   //FOR O(n) time complexity
Pair fastDiameter(node* root)
    {
        Pair p;

        if(root==NULL)
        {
            p.Height=p.diameter=0;
        }

        Pair left = fastDiameter(root->left);
        Pair right = fastDiameter(root->right);

        //DIAMeter
        int op1=left.Height + right.Height;
        int op2=left.diameter;
        int op3=right.diameter;
        p.diameter=max(op1,max(op2,op3));

        //height
        p.Height=max(left.Height,right.Height)+1;

        return p;
    } */

//LEVEL WISE PRINT
void LevelOrderPrint(node* root)
    {
        queue<node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
            {
                node* temp=q.front();
                q.pop();
                if(temp==NULL)
                {
                    cout<<endl;
                    if(!q.empty())
                    {
                    q.push(NULL);
                    }
                }
                else
                {
                    cout<<temp->data<<" ";
                    if(temp->left)
                    {
                        q.push(temp->left);
                    }
                    if(temp->right)
                    {
                        q.push(temp->right);
                    }
                }
            }
    }

node* LevelOrderInput()
    {
        int data;
        cout<<"Enter root node : ";
        cin>>data;
        node* root=new node(data);
        q.push(root);
        while(!q.empty())
            {
            node* temp=q.front();
            q.pop();
            cout<<"Enter children of "<<temp->data<<" : ";
            int c1,c2;

            if(c1!=-1)
                {
                temp->left=new node(c1);
                q.push(temp->left);
                }
            if(c2!=-1)
                {
                temp->right=new node(c2);
                q.push(temp->right);
                }
            }
        return root;
    }

void Mirror(node* root)
    {
        if(root==NULL)
        {
            return;
        }

        swap(root->left,root->right);
        Mirror(root->left);
        Mirror(root->right);

    }

int main()
{

node* root=buildTree();
PreOrder(root);
cout<<endl;
InOrder(root);
cout<<endl;
PostOrder(root);
cout<<endl;
cout<<"No of nodes = "<<countNodes(root);
cout<<endl;
cout<<"Height = "<<height(root);
cout<<endl;
cout<<"Diameter = "<<Diameter(root);
cout<<endl;
/*Pair p=fastDiameter(root);
cout<<"FAST HEIGHT : "<<p.Height<<endl;
cout<<"FAST DIAMTER : "<<p.diameter;*/

LevelOrderPrint(root);
return 0;
}
