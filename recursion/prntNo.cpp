//DO BY STORING in array

#include<iostream>
using namespace std;

void print(int n)
    {
    if(n==0)
        {
        return;
        }
        print(n/10);

        if(n%10==1)
            {
            cout<<"one ";
            }
        else if(n%10==2)
            {
            cout<<"two ";
            }
        else if(n%10==3)
            {
            cout<<"three ";
            }
        else if(n%10==4)
            {
                cout<<"Four ";
            }
        else if(n%10==5)
            {
                cout<<"Five ";
            }
        else if(n%10==6)
            {
                cout<<"Six ";
            }
    }
int main()
{
int n;
cin>>n;
print(n);
return 0;
}
