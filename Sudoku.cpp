#include <iostream>

using namespace std;

const int N=10;

bool lin[N][N],col[N][N],chenar[N][N],marcat[N][N];
int patrat[N][N],mat[N][N];

bool next(int &i, int &j)
{
  for (i=1;i<=9;i++)
    for (j=1;j<=9;j++)
      if (!mat[i][j])
        return 1;
  return 0;
}

void calculare_patrat()
{
  int i,j;  
  for (i=1;i<=3;i++)
  {
    for (j=1;j<=3;j++)
      patrat[i][j]=1;
    for (j=4;j<=6;j++)
      patrat[i][j]=2;
    for (j=7;j<=9;j++)
      patrat[i][j]=3; 
  } 
  for (i=4;i<=6;i++)
  {
    for (j=1;j<=3;j++)
      patrat[i][j]=4;
    for (j=4;j<=6;j++)
      patrat[i][j]=5;
    for (j=7;j<=9;j++)
      patrat[i][j]=6; 
  }
  for (i=7;i<=9;i++)
  {
    for (j=1;j<=3;j++)
      patrat[i][j]=7;
    for (j=4;j<=6;j++)
      patrat[i][j]=8;
    for (j=7;j<=9;j++)
      patrat[i][j]=9; 
  }
}

bool se_poate(int i, int j, int a)
{
  if (lin[i][a]==1||col[j][a]==1||chenar[patrat[i][j]][a]==1)
    return 0;
  return 1;
}

bool ok()
{
  int i,j;  
  if (!next(i,j))
    return 1;
  for (int k=1;k<=9;k++)
  {
    if (se_poate(i,j,k))
    {
      mat[i][j]=k,lin[i][k]=1,col[j][k]=1,chenar[patrat[i][j]][k]=1;
      if (ok())
        return 1;
      mat[i][j]=0,lin[i][k]=0,col[j][k]=0,chenar[patrat[i][j]][k]=0;
    }
  }
  return 0;
}

int main()
{
  cout<<"Hey! This little program can solve any classic Sudoku in a short amount of time. In order to get it to work, you'll have to manually type the given sudoku in the following way: \n If a digit is given, you may write it as it is. \n If the digit is not given, write a 0 in its place. \n \n Have fun! \n \n";  
  int a;
  bool finish=0;
  calculare_patrat();
  for (int i=1;i<=9;i++)
    for (int j=1;j<=9;j++)
    {
      cin>>a;
      if (a)
        marcat[i][j]=1,mat[i][j]=a,lin[i][a]=1,col[j][a]=1,chenar[patrat[i][j]][a]=1;
    }
  for (int i=1;i<=9;i++)
  {
    for (int j=1;j<=9;j++)
      cout<<mat[i][j]<<" ";
    cout<<'\n';
  }
  cout<<'\n';
  if (ok())
  {
    for (int i=1;i<=9;i++)
    {
      for (int j=1;j<=9;j++)
        cout<<mat[i][j]<<" ";
      cout<<'\n';
    }
    cout<<'\n'<<"Done!"<<'\n'<<'\n';
  }
  else 
    cout<<'\n'<<"Sorry, no solution available! :( ";
  return 0;
}