#include<iostream>
using namespace std;

int main()
{
char a[100]="abccde";
char b[100]="cdceba";

int freq[26]={0};

for(int i=0;a[i]!='\0';i++)
    {
    char ch=a[i];
    int index = ch-'a';
    freq[index]++;
    }
for(int j=0;b[j]!='\0';j++)
    {
    char ch=b[j];
    int index = ch-'a';
    freq[index]--;
    }

int flag=0;

for(int i=0;i<=25;i++)
    {
    if(freq[i]==0)
        {
        flag++;
        }
    }

if(flag==26)
    {
    cout<<"it is permutation : "<<endl;
    }
else
    {
    cout<<"not permutation :"<<endl;
    }

return 0;
}

