#include<iostream>
using namespace std;

int sum(int *a,int n)
    {
    if(n==0)
        {
        return 0;
        }

    int ans=a[0]+sum(a+1,n-1);

    return ans;
    }

int main()
{
int a[]={1,2,3,4,5};
int n=sizeof(a)/sizeof(int);
cout<<sum(a,n);

return 0;
}
