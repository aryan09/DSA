#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{
    int n , cnt = 0;
    cin>>n;
    string s[n];
    int i = 0;
    while (i<n && std::cin >> s[i])
    {i++;}
    for(i=0 ; i<n ; i++)
        cout<<s[i]<<" ";
    cout<<endl;
}

return 0;
}

//Eg  - input
/*
5
2
start stop
2
restart stop
3
start restart stop
3
start stop stop
1
stop
*/
