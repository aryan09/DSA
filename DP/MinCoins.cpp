#include<iostream>
using namespace std;

//Recursive
int MinCoins(int coins[] , int amt , int n)
{
    if(amt==0)
        return 0;

    int minCoins = INT_MAX;
    for(int i=0 ; i<n ; i++)
    {
        if(amt - coins[i] >= 0)
        {
            int noOfCoins = MinCoins(coins , amt - coins[i] , n) + 1;
            if(noOfCoins!=INT_MAX)
                minCoins = min(minCoins , noOfCoins);
        }
    }
    return minCoins;
}

int MinCoinsTD(int coins[] , int amt , int n , int *dp)     //O(amt*n)
{
    if(amt==0)
        return 0;

    if(dp[amt]!=-1)
        return dp[amt];

    int minCoins = INT_MAX;
    for(int i=0 ; i<n ; i++)
    {
        if(amt - coins[i] >= 0)
        {
            int noOfCoins = MinCoinsTD(coins , amt - coins[i] , n , dp) + 1;
            if(noOfCoins!=INT_MAX)
                minCoins = min(minCoins , noOfCoins);
        }
    }
    return dp[amt] = minCoins;
}

int MinCoinsBU(int coins[] , int amt , int n)               //O(amt*n)
{
    int *dp = new int[amt+1];
    for(int i=0 ; i<=amt ; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;

    for(int sum=1 ; sum<=amt ; sum++)
    {
        //Iterate over the coins
        for(int j=0 ; j<n ; j++)
        {
            int amtleft = sum - coins[j];
            if(amtleft>=0)
            {
                if(dp[amtleft] != INT_MAX)
                dp[sum] = min(dp[sum] , dp[amtleft] + 1);
            }
        }
    }
    return dp[amt];
}

int main()
{
    int uscoins[] = {1,5,7};
    int indcoins[] = {1,2,5,10};
    cout<<MinCoins(uscoins , 10 , 3)<<endl;

    int dp[1000];
    for(int i=0 ; i<1000 ; i++)
        dp[i] = -1;
    cout<<MinCoinsTD(uscoins , 52 , 3 , dp)<<endl;
    cout<<MinCoinsBU(uscoins , 52 , 3)<<endl;
return 0;
}
