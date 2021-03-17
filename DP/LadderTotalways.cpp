#include<iostream>
using namespace std;

int LadderRec(int n , int k)                //O(n^k)
{
    if(n==0)
        return 1;

    if(n<0)
        return 0;

    int ans = 0;
    for(int i=1 ; i<=k ; i++)
        ans += LadderRec(n-i , k);

    return ans;
}

int LadderTD(int n , int *dp , int k)       //O(n*k)
{
    if(n==0)
        return dp[n] = 1;

    if(n<0)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = 0;
    for(int i=1 ; i<=k ; i++)
        dp[n] += LadderTD(n-i , dp , k);
    return dp[n];
}

int LadderBU(int n , int k)         //O(n*k)
{
    int *dp = new int[n+1];
    dp[0] = 1;

    for(int steps=1 ; steps<=n ; steps++)
    {
        dp[steps] = 0;
        for(int j=1 ; j<=k ; j++)
        {
            if(steps - j >=0)
                dp[steps] += dp[steps-j];
        }
    }
    return dp[n];
}

int LadderMoreOptimised(int n , int k)  //O(n)
{
    int *dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i=1 ; i<n ; i++)            //Different recurrence relation : f(n+1) = f(n) + {f(n) - f(n-k)}
    {
        if(i-k >= 0)
            dp[i+1] = 2*dp[i] - dp[i-k];
        else
            dp[i+1] = 2*dp[i];
    }
    return dp[n];
}

int main()
{
    int dp[1000];
    for(int i=0 ; i<1000 ; i++)
        dp[i] = -1;

    cout<<LadderRec(5 , 3)<<endl;
    cout<<LadderTD(5 , dp , 3)<<endl;
    cout<<LadderBU(5,3)<<endl;
    cout<<LadderMoreOptimised(5,3)<<endl;

return 0;
}
