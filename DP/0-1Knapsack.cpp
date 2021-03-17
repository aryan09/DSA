#include<iostream>
using namespace std;

int knapsackRec(int wt[], int val[] , int n , int lwt)
{
    if(n==0 || lwt<=0)
        return 0;

    int inc = 0 , exc = 0;
    if(wt[n-1] <= lwt)                          //0 based indexing , i.e wt of nth item
        inc = val[n-1] + knapsackRec(wt , val , n-1 , lwt-wt[n-1]);

    exc = knapsackRec(wt , val , n-1 , lwt);

    return max(inc , exc);
}

int knapsackTD(int wt[] , int val[] , int n , int lwt , int dp[100][1000])
{
    if(n<=0 || lwt<=0)
        return 0;

    if(dp[n-1][lwt-1] != -1)
        return dp[n-1][lwt-1];

    int inc = 0 , exc = 0;
    if(wt[n-1] <= lwt)                      //weight of nth item
        inc = val[n-1] + knapsackTD(wt , val , n-1 , (lwt-wt[n-1]) , dp);

    exc = knapsackTD(wt , val , n-1 , lwt , dp);

    return dp[n-1][lwt-1] = max(inc , exc);
}

int knapsackBU(int wt[] , int val[] , int n , int mwt)
{
    int dp[n+1][mwt+1] = {0};

    for(int i=0 ; i<=n ; i++)                    //Items
    {
        for(int j=0 ; j<=mwt ; j++)              //Weights
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else
                {
                    int inc = 0 , exc = 0;

                    if(wt[i-1]<=j)              //wt of nth item ,  i.e. it can be filled or not in knapsack
                        inc = val[i-1] + dp[i-1][j-wt[i-1]];

                    exc = dp[i-1][j];
                    dp[i][j] = max(inc , exc);
                }
            }
    }
    return dp[n][mwt];
}

int main()
{
    int weight[] = {3 , 4 , 7};
    int value[] = {8 , 8 , 15};
    int maxwt = 9;
    int n = 3;
    cout<<knapsackRec(weight , value , n , maxwt)<<endl;

    int dp[100][1000];
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<maxwt ; j++)
            dp[i][j] = -1;

    cout<<knapsackTD(weight , value , n , maxwt , dp)<<endl;
    cout<<knapsackBU(weight , value , n , maxwt)<<endl;
return 0;
}
