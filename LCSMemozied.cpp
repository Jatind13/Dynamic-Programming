#include<bits/stdc++.h>
using namespace std;
const int maximum=1000;
int LCS(string X,string Y,int m,int n,int t[][maximum])
{   if(n==0 || m==0)
      return 0;

      if(t[m-1][n-1]!=-1)
       return t[m-1][n-1]; 

       if(X[m-1]==Y[n-1])
      {
          return t[m-1][n-1] = 1+LCS(X,Y,m-1,n-1,t);
      }
      else{
          return t[m-1][n-1] = max(LCS(X,Y,m,n-1,t),LCS(X,Y,m-1,n,t));
      }
}
int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    int m=X.length();
    int n=Y.length();
    int t[m][maximum];
    memset(t,-1,sizeof(t));
  cout<<"Longest common Subsequence:"<<LCS(X,Y,m,n,t);

    return 0;
}