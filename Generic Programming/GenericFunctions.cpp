#include<iostream>
#include<list>
using namespace std;

template <typename T>               //freedom from differetent data types
int Search(T arr[] , int n , T key)
{
    for(int p=0 ; p<n ; p++)
    {
        if(arr[p] == key)
            return p;
    }
return n;
}

int main()
{
    char ch[] = {'a' , 'e' , 'i' , 'o' , 'u'};
    int n = sizeof(ch)/sizeof(char);
    char key = 'e';

    float f[] = {1.1 , 1.2 , 1.3};
    int n2 = sizeof(f)/sizeof(float);
    float key2 = 1.3;

    cout<<key<<" found at "<<Search(ch , n , key)<<endl;
    cout<<key2<<" found at "<<Search(f , n2 , key2)<<endl;

return 0;
}
