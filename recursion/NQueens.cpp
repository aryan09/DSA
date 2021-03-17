#include<iostream>
using namespace std;

bool isSafeToPut(int board[100][100],int i,int j,int n)
    {
        //For Vertical and Horizontal
        for(int k=0;k<n;k++)
        {
        if(board[i][k]==1 || board[k][j]==1)
            {
            return false;
            }
        }
        //For right diagonal
        int r=i;
        int c=j;
        while(r>=0 && c<n)
        {
            if(board[r][c]==1)
            {
                return false;
            }
            r--;
            c++;
        }
        //For left diagonal
        r=i;
        c=j;
        while(r>=0 && c>=0)
        {
            if(board[r][c]==1)
            {
                return false;
            }
            r--;
            c--;
        }

        return true;
    }

bool nqueen(int board[100][100],int n,int i,int &ctr)
    {
    if(i==n)
        {
        for(int a=0;a<n;a++)
        {
            for(int b=0;b<n;b++)
            {
                if(board[a][b])
                {
                    cout<<"Q ";
                }
                else
                {
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        ctr++;
        cout<<endl;
        return false;
        }

    for(int j=0;j<n;j++)
        {
        if(isSafeToPut(board,i,j,n))
            {
            board[i][j]=1;
            bool KyaBaakiBaatBani=nqueen(board,n,i+1,ctr);
            if(KyaBaakiBaatBani)
                {
                return true;
                }
            }
        board[i][j]=0;

        }

    return false;
    }


int main()
{
int board[100][100]={0};
int n,ctr=0;
cin>>n;
nqueen(board,n,0,ctr);
cout<<"total solutions :"<<ctr;

return 0;
}
