//Given a string of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. 

//Note: The order of characters should be maintained. 

#include<bits/stdc++.h>
using namespace std;
const int maximum=1000;
int LCS(string X,string Y,int m,int n,int t[][maximum])
{  
     for(int i=0;i<=m;i++)
{
    for(int j=0;j<=n;j++)
    {
        if(i==0|| j==0)
        t[i][j]=0;
    }
}     
   for(int i=1;i<=m;i++)
{
    for(int j=1;j<=n;j++)
    {
        if(X[i-1]==Y[j-1])
        t[i][j]=t[i-1][j-1]+1;
        else
        t[i][j]=max(t[i-1][j],t[i][j-1]);
    }
}
return t[m][n];
}
int main()
{
    string X = "AGBCBA";
    string Y = "ABCBGA";
    int m=X.length();
    int n=Y.length();
    int t[m][maximum];
    memset(t,-1,sizeof(t));
    cout<<"Longest Palindromic sequence: "<<(m-LCS(X,Y,m,n,t));//given string sai agr length of LCS subtract krdein then we get the minimum no. of deletions.
     return 0;
}