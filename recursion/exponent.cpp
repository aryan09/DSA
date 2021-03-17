#include<iostream>
using namespace std;

int solve(int a,int n)
    {
    if(n==1)
        {
        return a;
        }

        int ans=a*solve(a,n-1);

        return ans;

    }

int main()
{
int a,n;
cin>>a>>n;

cout<<solve(a,n);



return 0;
}
