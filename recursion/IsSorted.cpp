#include<iostream>
using namespace std;

bool isSorted(int a[],int n)
    {
    //Base Case
    if(n==1 || n==0)
        {
        return true;
        }

        //Assumption
        bool KyaChotaSortedHai=isSorted(a+1,n-1);

        if(a[0]<a[1] && KyaChotaSortedHai == 1)
            {
            return true;
            }

        else
        {
            return false;
        }
    }

/*bool isSorted2(int a[], int n,int i)
    {
        //BASE CASE
        if(n==0 || n==1)
        {
            return true;
        }

        //ASSUMPTION
        bool KyaChotaSortedHai=isSorted2(a,n-1);
        if()

    }*/



int main()
{
int a[]={1,2,3,7,5};
int n=sizeof(a)/sizeof(int);

if(isSorted(a,n))
    {
    cout<<"SORTED ";
    }
else
    {
    cout<<"UNSORTED ";
    }

return 0;}
