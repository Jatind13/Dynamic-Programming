//Problem statement-Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert the minimum number of characters from/in str1 to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

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
    string X = "GEEKSFORGEEKS";//just reverse the given string  
    string Y = "SKEEGROFSKEEG";//and pass this string to LCS and the length we grt in return is the 
    int m=X.length();//length of the longest palindromic sequence.
    int n=Y.length();
    int t[m][maximum];
    memset(t,-1,sizeof(t));
    cout<<"Longest Palindromic sequence: "<<LCS(X,Y,m,n,t);
     return 0;
}