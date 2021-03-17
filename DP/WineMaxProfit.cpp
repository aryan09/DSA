#include<iostream>
using namespace std;

const int N=10000;

int ProfitRec(int *prices , int n , int s , int e)
{
    if(s>e)
        return 0;

    int year = n - (e-s+1) + 1;             //0 based indexing of s , e

    int incs = prices[s]*year + ProfitRec(prices , n , s+1 , e);
    int ince = prices[e]*year + ProfitRec(prices , n , s , e-1);
    return max(incs , ince);
}

int ProfitTD(int *prices , int n , int s , int e , int dp[][N])
{
    if(s>e)
        return 0;

    if(dp[s][e]!=0)
        return dp[s][e];

    int year = n - (e-s+1) + 1;             //0 based indexing of s , e

    int incs = prices[s]*year + ProfitTD(prices , n , s+1 , e , dp);
    int ince = prices[e]*year + ProfitTD(prices , n , s , e-1 , dp);
    return dp[s][e] = max(incs , ince);
}

int ProfitBU(int *prices , int n)
{
    int dp[100][100] = {0};

    for(int i=n-1 ; i>=0 ; i--)             //Outer loop for starting index
    {
        for(int j=0 ; j<n ; j++)            //inner loop for ending index
        {
            if(i>j)                         //s>e
                dp[i][j] = 0;
            else
            {
                int year = n - (j - i);
                dp[i][j] = max(year * prices[i] + dp[i+1][j], year * prices[j] + dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}


int main()
{
int prices[] = {2,3,5,1,4};
int n = sizeof(prices)/sizeof(int);

cout<<ProfitRec(prices , n , 0 , n-1)<<endl;

int dp[n][N];
cout<<ProfitTD(prices , n , 0 , n-1 , dp)<<endl;
cout<<ProfitBU(prices , n)<<endl;

return 0;
}
