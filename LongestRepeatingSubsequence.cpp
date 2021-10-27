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
        if(X[i-1]==Y[j-1]  && i!=j)//the only change in code from lCS is if(i==j)don't include
        t[i][j]=t[i-1][j-1]+1;
        else
        t[i][j]=max(t[i-1][j],t[i][j-1]);
    }
}
return t[m][n];

     
}
int main()
{
    string X = "AABEBCDD";
    string Y = "AABEBCDD";
    int m=X.length();
    int n=Y.length();
    int t[m][maximum];
    memset(t,-1,sizeof(t));
  cout<<"Longest common Subsequence:"<<LCS(X,Y,m,n,t);

    return 0;
}
/*----------------------METHOD 2 or using one string only----------
// C++ program to find the longest repeating
// subsequence
#include <iostream>
#include <string>
using namespace std;

// This function mainly returns LCS(str, str)
// with a condition that same characters at
// same index are not considered.
int findLongestRepeatingSubSeq(string str)
{
	int n = str.length();

	// Create and initialize DP table
	int dp[n+1][n+1];
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			dp[i][j] = 0;

	// Fill dp table (similar to LCS loops)
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			// If characters match and indexes are
			// not same
			if (str[i-1] == str[j-1] && i != j)
				dp[i][j] = 1 + dp[i-1][j-1];		
					
			// If characters do not match
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[n][n];
}

// Driver Program
int main()
{
	string str = "aabb";
	cout << "The length of the largest subsequence that"
			" repeats itself is : "
		<< findLongestRepeatingSubSeq(str);
	return 0;
}
*/