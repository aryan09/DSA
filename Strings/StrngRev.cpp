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

void printstring(char a[],int len)
    {
        for(int i=0;i<=len-1;i++)
        {
            cout<<a[i];
        }
    }

int main()
 {
 char a[100]="hello";
 int strt,end;
 int len=length(a);
strt=0;
end=len-1;
while(strt<end)
    {
        //swap
    char ch;
    ch=a[strt];
    a[strt]=a[end];
    a[end]=ch;

    strt++;
    end--;
    }

printstring(a,len);

 return 0;
 }
