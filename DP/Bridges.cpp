#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define P pair<int,int>

int bridges(vector<P> pt , int n)
{
    sort(pt.begin() , pt.end());                   //Sort on basis of first array

    //LIS code on second(Bottom up dp)
    int *dp = new int[n];

    for(int i=0;i<n;i++)
        dp[i] = 1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(pt[j].S < pt[i].S)                   //Check for every j<i and arr[j]<arr[i]
                dp[i] = max(dp[i] , dp[j] + 1);
        }
    }

    int maxB = 0;
    for(int i=0 ; i<n ; i++)
        maxB = max(maxB , dp[i]);

    return maxB;
}

int main()
{
    int n,a,b;
    cin>>n;
    vector<pair<int,int> > pt;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        pt.push_back(make_pair(a,b));
    }
    cout<<bridges(pt , n);

return 0;
}
