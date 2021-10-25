/* Dynamic Programming implementation of LCS problem */
#include<bits/stdc++.h>
using namespace std;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs( char *X, char *Y, int m, int n )
{
int t[m+1][n+1];

/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
for (int i=0; i<=m; i++)
{
	for (int j=0; j<=n; j++)
	{
	if (i == 0 || j == 0)
		t[i][j] = 0;
	else if (X[i-1] == Y[j-1])
		t[i][j] = t[i-1][j-1] + 1;
	else
		t[i][j] = max(t[i-1][j], t[i][j-1]);
	}
}

// Following code is used to print LCS
int index = t[m][n];

// Create a character array to store the lcs string
char lcs[index+1];
lcs[index] = '\0'; // Set the terminating character

// Start from the right-most-bottom-most corner and
// one by one store characters in lcs[]
int i = m, j = n;
while (i > 0 && j > 0)
{
	// If current character in X[] and Y are same, then
	// current character is part of LCS
	if (X[i-1] == Y[j-1])
	{
		lcs[index-1] = X[i-1]; // Put current character in result
		i--; j--; index--;	 // reduce values of i, j and index
	}

	// If not same, then find the larger of two and
	// go in the direction of larger value
	else if (t[i-1][j] > t[i][j-1])
		i--;
	else
		j--;
}

// Print the lcs
cout << "LCS of " << X << " and " << Y << " is " << lcs;
}

/* Driver program to test above function */
int main()
{
char X[] = "AGGTAB";
char Y[] = "GXTXAYB";
int m = strlen(X);
int n = strlen(Y);
lcs(X, Y, m, n);
return 0;
}



// #include<bits/stdc++.h>
// using namespace std;
// const int maximum=1000;
// int LCS(string X,string Y,int m,int n,int t[][maximum])
// {  
//      for(int i=0;i<=m;i++)
// {
//     for(int j=0;j<=n;j++)
//     {
//         if(i==0|| j==0)
//         t[i][j]=0;
//     }
// }     
//    for(int i=1;i<=m;i++)
// {
//     for(int j=1;j<=n;j++)
//     {
//         if(X[i-1]==Y[j-1])
//         t[i][j]=t[i-1][j-1]+1;
//         else
//         t[i][j]=max(t[i-1][j],t[i][j-1]);
//     }
// }
// //Now write a code to print LCS
// int index=t[m][n];
// char lcs[index+1]; //size+1 for storing terminating character.
// lcs[index]='\0';
// int i=m,j=n;
// while(i>0 && j>0)
// {
//     if(X[i-1]==Y[j-1]){
//         lcs[index-1]=X[i-1];
//         i--;
//         j--;
//     }
//     else if(t[i-1][j]>t[i][j-1])
//                 i--;
//     else
//            j--;
// }
// cout<<"LCS of the string:"<<lcs;
     
// }
// int main()
// {
//     string X = "AGGTAB";
//     string Y = "GXTXAYB";
//     int m=X.length();
//     int n=Y.length();
//     int t[m][maximum];
//     memset(t,-1,sizeof(t));
//   cout<<"Longest common Subsequence:"<<LCS(X,Y,m,n,t);

//     return 0;
// }