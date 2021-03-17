#include<iostream>
using namespace std;

bool RatInMaze(char maze[5][5],int i,int j,int m,int n,int sol[][10])
    {
        if(i==m-1 && j==n-1)
        {
            sol[i][j]=1;
        for(int a=0;a<m;a++)
        {
            for(int b=0;b<m;b++)
            {
                cout<<sol[a][b]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
        }
        //recursive

        sol[i][j]=1;
        //For checking from right
        if((j+1)<n && maze[i][j]!='X')
        {
            bool KyaRightSeBaatBani = RatInMaze(maze,i,j+1,m,n,sol);
            if(KyaRightSeBaatBani==1)
            {
                return true;
            }
        }
        if((i+1)<m && maze[i][j]!='X')
        {
            bool KyaNicheSeBaatBani= RatInMaze(maze,i+1,j,m,n,sol);
            if(KyaNicheSeBaatBani==1)
            {
                return true;
            }
        }


        sol[i][j]=0;
        return false;

    }

int main()
{
char maze[5][5]={"0000","00XX","0000","XX00"};

int sol[10][10]={0};

RatInMaze(maze,0,0,4,4,sol);

return 0;
}
