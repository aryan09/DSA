#include<iostream>
using namespace std;

int length(char a[])
    {
    int i;
    for(i=0;a[i]!='\0';i++)
        {
        }
    return i;
    }

int main()
{
int n,len,j,i;
cin>>n;
char a[100]="elephant";
len=length(a);
i=len-1;
j=n+len-1;

for(i=len-1;i>=0;i--)
    {
        a[j]=a[i];
        j--;
    }

cout<<a<<endl;

i=0;
j=len;






return 0;
}
