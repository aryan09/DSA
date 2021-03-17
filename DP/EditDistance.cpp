#include<bits/stdc++.h>
using namespace std;

//Recursive
//O(3^m)
int EditDistance(string s1 , string s2 , int m , int n)
{
    if(m==0)
        return n;
    else if(n==0)
        return m;

    else if(s1[m-1] == s2[n-1])
        return EditDistance(s1 , s2 , m-1 , n-1);

    else
        return 1+min(EditDistance(s1 , s2 , m-1 , n-1) , min( EditDistance(s1 , s2 , m , n-1) , EditDistance(s1 , s2 , m-1 , n) ) );    //Replace or INsert or Remove
}

//BottomUp Dp
//Time O(M*N)
//Space O(m*N)
int EditDistanceBU(string s1 , string s2 , int m , int n)
{
    int dp[m+1][n+1] = {0};
    for(int i=0 ; i<=m ; i++)
    {
        for(int j=0 ; j<=n ; j++)
        {
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1] , min(dp[i][j-1] , dp[i-1][j]));    //Replace _ Insert _ Remove
        }
    }
    return dp[m][n];
}

//We can have a more space optimised solution as curr state depends on the just previous state only
//Time O(M*N)
//Spcae O(N)
int EditDistanceSpaceOpt(string s1 , string s2 , int m , int n)
{
    int dp[2][n+1] = {0};
    for(int i=0 ; i<=m ; i++)
    {
        for(int j=0 ; j<=n ; j++)
        {
            if(i==0)
                dp[1][j] = j;
            else if(j==0)
                dp[1][j] = i;
            else if(s1[i-1]==s2[j-1])
                dp[1][j] = dp[0][j-1];
            else
                dp[1][j] = 1 + min(dp[0][j-1] , min(dp[1][j-1] , dp[0][j]));    //Replace _ Insert _ Remove
        }
        //copy values of second row into first
        for(int k=0 ; k<=n ; k++)
            dp[0][k] = dp[1][k];
    }
    return dp[1][n];
}

int main()
{
string s1 = "sunday";
string s2 = "saturday";

int n1 = s1.length();
int n2 = s2.length();

cout<<EditDistance(s1 , s2 , n1 , n2)<<endl;
cout<<EditDistanceBU(s1 , s2 , n1 , n2)<<endl;
cout<<EditDistanceSpaceOpt(s1 , s2 , n1 , n2);


return 0;
}
