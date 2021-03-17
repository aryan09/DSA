#include<bits/stdc++.h>
using namespace std;


//APPROACH is to find the longest common subsequence and insert the rest of the charaters in the same order
//Time - O(M*N + (M+N))) ~ O(M*N)
void SCS(string s1 , string s2 , int m , int n)
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

    //Find the LCS
    int i=m , j=n , index = LCS[m][n];
    string lcs = "";

    //Calculate lcs in reverse order
    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1])
        {
            lcs += s1[i-1];
            i--;
            j--;
        }
        else if(LCS[i-1][j] > LCS[i][j-1])      //Move towards the larger subsequence side
            i--;
        else
            j--;
    }


    i = m-1;
    j = n-1;
    index = LCS[m][n];
    int k = 0;      //counts the no. of lcs characters used
    string ans = "";

    while(i>=0 || j>=0)                         //WHile both strings arent finished
    {
        if(k<index)
        {
            while(i>=0 && s1[i] != lcs[k])
                ans += s1[i--];
            while(j>=0 && s2[j] != lcs[k])
                ans += s2[j--];

            //Here s1[i] == s2[j] == lcs[k]
            ans += lcs[k++];
            i--;
            j--;
        }
        else
        {
            while(i>=0)
                ans += s1[i--];
            while(j>=0)
                ans += s2[j--];
        }
    }
    //Print the ans stored in reverse order
    for(int i= (ans.length())-1 ; i>=0 ; i--)
        cout<<ans[i];
return;
}

int main()
{
    string s1 = "apples";
    string s2 = "lestat";
    string s3 = "rapesza";

SCS(s1 , s2 , 7 , 7);
cout<<endl;
SCS(s1 , s3 , 7 , 8);


return 0;
}
