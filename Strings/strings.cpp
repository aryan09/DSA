#include<iostream>
using namespace std;
int main()
{
char a[7]="Aryan";     //we need to specify the size if we are not initialising
cout<<a<<endl;

string s="nandal";  //INITIALISATION
string s2("HELLO WORLD");   //INITIALISATION

cout<<s<<s2<<endl<<endl;

for(int i=0;s[i]!='\0';i++)
    {
        cout<<s[i]<<" ";
    }



return 0;
}
