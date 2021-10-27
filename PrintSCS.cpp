#include<bits/stdc++.h>
using namespace std;
const int maximum=1000;
string SCS(string X,string Y,int m,int n,int t[][maximum])
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
// Following code is used to print shortest supersequence
 
    // dp[m][n] stores the length of the shortest supersequence
    // of X and Y
     
 
    // string to store the shortest supersequence
    string str;
 
    // Start from the bottom right corner and one by one
    // push characters in output string
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // If current character in X and Y are same, then
        // current character is part of shortest supersequence
        if (X[i - 1] == Y[j - 1])
        {
            // Put current character in result
            str.push_back(X[i - 1]);
 
            // reduce values of i, j and index
            i--; 
            j--;
        }
 
        // If current character in X and Y are different
        else if (t[i - 1][j] > t[i][j - 1])
        {
            // Put current character of Y in result
            str.push_back(X[i - 1]);
 
            // reduce values of j and index
            i--;
        }
        else
           if(t[i][j-1]>=t[i-1][j])
        {
            // Put current character of X in result
            str.push_back(Y[j - 1]);
 
            // reduce values of i and index
            j--;
        }
    }
 
    // If Y reaches its end, put remaining characters
    // of X in the result string
    while (i > 0)
    {
        str.push_back(X[i - 1]);
        i--;
    }
 
    // If X reaches its end, put remaining characters
    // of Y in the result string
    while (j > 0)
    {
        str.push_back(Y[j - 1]);
        j--;
    }
 
    // reverse the string and return it
    reverse(str.begin(), str.end());
    return str;

   
}
int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    int m=X.length();
    int n=Y.length();
    int t[m][maximum];
    memset(t,-1,sizeof(t));
  cout<<"Shortest common supersequence :"<<SCS(X,Y,m,n,t);

    return 0;
}