#include<iostream>
using namespace std;

int main()
{
    char ch[100],flag;
    int strt=0,end=0,size,i;

    flag=cin.get();

    for(i=0;flag!='\n';i++)
    {
        ch[i]=flag;
        flag=cin.get();
    }
    i=0;
    end=size-1;
    while(i<=size)
    {
        if(ch[strt]==ch[end])
        {
            strt++;
            end--;
        }
        else
        {
            cout<<"Not palindrome";
            break;
        }
        if(strt>=end)
        {
            cout<<"Palindrome";
            break;
        }

    i++;
    }

    return 0;
}
