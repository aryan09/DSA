#include<bits/stdc++.h>
using namespace std;

int Mixtures(int *col , int n)
{
    int sum[n] = {0};                   //Cumulative sum array to find sum over range
    sum[0] = col[0];

    for(int i=1 ; i<n ; i++)
        sum[i] = sum[i-1] + col[i];

    int dp[n][n];

    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(i==j)                    //A single mixture was there so smoke generated is zero
            {
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = INT_MAX;
            for(int k=i ; k<j ; k++)        //k is the partition which divides the i...j into two parts to be combined
            {
                int left_color;
                if(i==0)
                    left_color = sum[k]%100;
                else
                    left_color = (sum[k] - sum[i-1])%100;
                int right_color = (sum[j] - sum[k])%100;

                dp[i][j] = min(dp[i][j] , (dp[i][k] + dp[k+1][j] + (left_color*right_color)));
            }
        }
    }
    return dp[0][n-1];
}

int main()
{
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    int col[n];

    for(int i=0 ; i<n ; i++)
        cin>>col[i];

    cout<<Mixtures(col , n)<<endl;
}

return 0;
}
