#include<iostream>
#include<cmath>
using namespace std;

bool isSafeToPut(int mat[9][9],int num,int i,int j,int n)
    {
        for(int k=0;k<n;k++)
        {
            if(mat[i][k]==num || mat[k][j]==num)
            {
                return false;
            }
        }
        int ctr=0;
        int rootn=sqrt(n);
        int i1=(i/rootn)*rootn;
        int j1=(j/rootn)*rootn;
        for(int a=i1;a<i1+3;a++)
        {
            for(int b=j1;b<j1+3;b++)
            {
                if(mat[a][b]==num)
                {
                    return false;
                }
            }
        }
        return true;
    }

bool SudokuSolver(int mat[9][9],int n,int i,int j)
    {
        //Base Case
        if(i==n)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<mat[i][j]<<" ";
                }
            cout<<endl;
            }
        return true;
        }

        if(j==n)
        {
            return SudokuSolver(mat,n,i+1,0);
        }

        if(mat[i][j]!=0)
        {
            return SudokuSolver(mat,n,i,j+1);
        }

        //RECURSIVE

        for(int num=1;num<=n;num++)
        {
            if(isSafeToPut(mat,num,i,j,n))
            {
            mat[i][j]=num;
            bool KyaAageBaatBani = SudokuSolver(mat,n,i,j+1);

            if(KyaAageBaatBani)
                {
                return true;
                }
            else
                {
                mat[i][j]=0;
                }

            }
        }
        return false;
    }

int main(){
	int mat[9][9] =
	{
	{5,3,0,0,7,0,0,0,0},
	{6,0,0,1,9,5,0,0,0},
	{0,9,8,0,0,0,0,6,0},
	{8,0,0,0,6,0,0,0,3},
	{4,0,0,8,0,3,0,0,1},
	{7,0,0,0,2,0,0,0,6},
	{0,6,0,0,0,0,2,8,0},
	{0,0,0,4,1,9,0,0,5},
	{0,0,0,0,8,0,0,7,9}
	};
	SudokuSolver(mat,9,0,0);
	cout<<endl;
	return 0;
}
