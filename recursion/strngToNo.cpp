#include<iostream>
using namespace std;

int convertstring(char *s, int n)
    {
    //BAse case
    if(n==0)
        {
        return 0;
        }
    //recursive
    int l_dig=s[n-1] - '0';
    int ans= convertstring(s,n-1)*10 + l_dig;


    return ans;



    }

int main()
{
char s[]="1234";
int n=4;
cout<<convertstring(s,n);

return 0;
}
