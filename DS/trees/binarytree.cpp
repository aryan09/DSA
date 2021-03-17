#include<iostream>
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
cout<<"HEight = "<<height(root);
cout<<endl;
cout<<"Diameter = "<<Diameter(root);
return 0;
}
