#include<iostream>
using namespace std;

void print(int num,string *a)
    {
        if(num==0)
        {
            return;
        }
        //RECURSIVE
        print(num/10,a);

        for(int i=0;i<=9;i++)
        {
        if(num%10==i)
            {
            cout<<a[i]<<" ";
            }
        }


    }

int main()
{
int num;
string a[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
cin>>num;
print(num,a);
return 0;
}
