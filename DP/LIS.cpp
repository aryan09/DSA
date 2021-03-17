#include<bits/stdc++.h>
using namespace std;

vector<int> lis;

//RECUSRSIVE        //O(2^n)
int LIS(int *seq , int n , int i , int larg)
{
    if(i==n)
        return 0;

    int ans1 = 0 , ans2 = 0;
    if(seq[i]>=larg)
    {
        ans1 = LIS(seq , n , i+1 , seq[i]) + 1;
        ans2 = LIS(seq , n , i+1 , larg);
    }
    return max(ans1 , ans2);
}

int LISTD(int *seq , int n , int i , int larg , int dp[100][100])
{
    if(i==n)
        return 0;
    if(dp[i][larg]!=-1)
        return dp[i][larg];

    int ans1 = 0 , ans2 = 0;
    if(seq[i]>=larg)
    {
        ans1 = LISTD(seq , n , i+1 , seq[i] , dp) + 1;
        ans2 = LISTD(seq , n , i+1 , larg , dp);
    }
    return dp[i][larg] = max(ans1 , ans2);
}

//Bottom UP DP                  //O(n^2)
int LISBU(int *seq , int n)
{
    int dp[n];

    for(int i=0 ; i<n ; i++)                //Set all to 1 initiailly
        dp[i] = 1;

    for(int i=0 ; i<n ; i++)                //Fill up the dp array in bottom up manner
    {
        for(int j=0 ; j<i ; j++)            //CHeck for every value for j<i
        {
            if(seq[j]<seq[i])
                dp[i] = max(dp[i] , dp[j]+1);
        }
    }

    int res = 0;
    for(int i=0 ; i<n ; i++)                //Return the maximum subsequence length
    {
        if(res<dp[i])
            res = dp[i];
    }
    return res;
}

int main()
{
int seq[] = {2,4,3,6,9,7,1};
int n = sizeof(seq)/sizeof(int);

cout<<LIS(seq , n , 0 , 0 )<<endl;

int dp[100][100];
for(int i=0 ; i<100 ; i++)
    for(int j=0;j<100;j++)
        dp[i][j] = -1;
cout<<LISTD(seq , n , 0 , 0 , dp)<<endl;
cout<<LISBU(seq , n);

return 0;
}
