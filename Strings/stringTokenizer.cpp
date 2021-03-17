#include<iostream>
#include<cstring>`
using namespace std;
int main()
{
char a[]="11 123 321 1 1 12 13 14";

// char *strtok(char *a, char *listofDelimeters)

char *ans = strtok(a," ");

 // cout<<ans<<endl;

 while(ans!=NULL)
 {
     cout<<ans<<endl;
     ans=strtok(NULL," ");   //NULL is given so that the pointer continues on smame string

 }



return 0;
}
