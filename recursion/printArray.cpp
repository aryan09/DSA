#include<iostream>
using namespace std;

void print (int a[], int n,int i)
    {
    //BASE CASE
    if(i==n)
        {
        return;
        }

        cout<<a[i]<<" ";
        print(a,n,i+1);

    return;
    }


int main()
{
int a[]={1,2,3,4,5};
int n=sizeof(a)/sizeof(int);

print(a,n,0);




return 0;
}
