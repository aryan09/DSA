#include<iostream>
using namespace std;

bool checkseven(int *a,int n)
    {
    //base case
    if(n==1)
        {
        if(a[0]!=7)
            {
            return false;
            }
        else
            {
            return true;
            }
        }
    //RECURSIVE

    if(a[0]==7 || checkseven(a+1,n-1)==1)
        {
        return true;
        }
    else
        {
        return false;
        }
    }

int firstindex(int *a,int n,int i)
    {
    //base case
    if(i==n)
        {
        return -1;
        }
        //RECURSION
        if(a[i]==7)
        {
            return i;
        }

        int index=firstindex(a,n,i+1);
        return index;

    }

int lastseven(int *a,int n,int i)
    {
        //base case
    if(i==n)
        {
        return -1;
        }
        //RECURSION
        if(a[i]==7)
        {
            int index=i;
            int aagewalaindex=lastseven(a,n,i+1);
            if(aagewalaindex>index)
                {
                    return aagewalaindex;
                }
            else
            {
            return index;
            }
        }
        return lastseven(a,n,i+1);

    }




int main()
{
int a[]={1,2,3,4,7,8,7,7,9};
int n=sizeof(a)/sizeof(int);

if(checkseven(a,n)==0)
    {
        cout<<"Not present "<<endl;
    }
else
    {
    cout<<"Present "<<endl;
    }

int index=firstindex(a,n,0);
if(index==-1)
{
    cout<<"Does not exist";
}
else
{
    cout<<"Present at "<<index;
}

int index2=lastseven(a,n,0);
if(index==-1)
{
    cout<<"Does not exist";
}
else
{
    cout<<"Present at "<<index2;
}

return 0;
}
