#include<bits/stdc++.h>
using namespace std;

// O(M*N) Time
// O(M*N) Space
int LCSdp(string s1 , string s2 , int m , int n)
{
    int LCS[m+1][n+1] = {0};

    for(int i=0 ; i<=m ; i++)
    {
        for(int j=0 ; j<=n ; j++)
        {
            if(i==0 || j==0)
                LCS[i][j] = 0;
            else if(s1[i-1] == s2[j-1])             //coz 0 based indexing
                LCS[i][j] = 1 + LCS[i-1][j-1];
            else
                LCS[i][j] = max(LCS[i-1][j] , LCS[i][j-1]);
        }
    }
    //Print
    int i=m , j=n , index = LCS[m][n];
    char *lcs = new char[index];

    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1])
        {
            lcs[--index] = s1[i-1];
            i--;
            j--;
        }
        else if(LCS[i-1][j] > LCS[i][j-1])      //Move towards the larger subsequence side
            i--;
        else
            j--;
    }
    for(int i=0 ; i<LCS[m-1][n-1] ; i++)
        cout<<lcs[i]<<" ";
    cout<<endl;
    return LCS[m-1][n-1];
}
//We can optimise the space complexity to O(n) as each state depends on the just previous state
//O(M*N) time , O(N) space
int LCS_SpaceOpt(string s1 , string s2 , int m , int n)
{
    int LCS[2][n+1] = {0};

    for(int i=0 ; i<=m ; i++)
    {
        for(int j=0 ; j<=n ; j++)
        {
            if(i==0 || j==0)
                LCS[1][j] = 0;
            else if(s1[i-1] == s2[j-1])             //coz 0 based indexing
                LCS[1][j] = 1 + LCS[0][j-1];
            else
                LCS[1][j] = max(LCS[0][j] , LCS[1][j-1]);
        }
        //Copy values of second row into first row for the next state
        for(int k=0 ; k<=n ; k++)
            LCS[0][k] = LCS[1][k];
    }
    //But we wont be able to print the LCS using this technique
    return LCS[1][n];
}

int main()
{
char s1[] = "abcdefg";      //ends with "\0" null character
char s2[] = "bdegh";

//int n1 = sizeof(s1)/sizeof(char);
//cout<<n1<<endl;

cout<<LCS_SpaceOpt(s1 , s2 , 7 , 5)<<endl;
cout<<LCSdp(s1 , s2 , 8 , 6);

return 0;
}
