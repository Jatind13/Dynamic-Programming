//Problem Statement:Given two strings a and y find that if string a is subsequence of b.
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
    string X = "AXY";
    string Y = "ADxCPY";
    int m=X.length();
    int n=Y.length();
    int t[m][maximum];
    memset(t,-1,sizeof(t));
 int lcs=LCS(X,Y,m,n,t);
 if(lcs==m) cout<<true;//this is the only difference from LCS.
 else cout<<false;

    return 0;
}