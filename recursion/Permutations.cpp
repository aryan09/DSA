#include<iostream>
using namespace std;

void perm(char a[],int i)
    {
        if(a[i]=='\0')
        {
            cout<<a<<endl;
            return;
        }

        for(int j=i;a[j]!='\0';j++)
        {
            swap(a[i],a[j]);
            perm(a,i+1);
            swap(a[i],a[j]);
        }

    }

int main()
{
char a[]="abc";

perm(a,0);

return 0;
}
