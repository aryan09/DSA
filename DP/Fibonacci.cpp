#include<iostream>
using namespace std;

//Using recursion
int fib(int n)
{
    if(n==0 || n==1)
        return n;

    return fib(n-1) + fib(n-2);
}

//TOP-DOWN Approach
int fiboTD(int n , int *dp)
{
    if(n==0 || n==1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = fiboTD(n-1 , dp) + fiboTD(n-2 , dp);
}

int fiboBU(int n)
{
    int *dp = new int[n];           //dp[i] denotes ith fibonacci number

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2 ; i<=n ; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    cout<<fib(6)<<endl;

    int dp[1000];
    for(int i=0;i<1000;i++)
        dp[i] = -1;

    cout<<fiboTD(6 , dp)<<endl;
    cout<<fiboBU(6);

return 0;
}
