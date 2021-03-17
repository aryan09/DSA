#include<iostream>
using namespace std;

void readline(char b[])
    {
        char ch;
        ch=cin.get();
        int i=0;
        while(ch!='\n')
        {
            b[i]=ch;
            i++;
            ch=cin.get();
        }
        b[i]='\0';

    }

int main()
{
char ch[100];
readline(ch);
cout<<ch;

//OR BY INBUILT FUNCTION
cin.getline(ch,100,'.');        //DELIMETER IS USED TO GET INPUT TILL SPECIFIC VALUE
cout<<ch;

return 0;
}
