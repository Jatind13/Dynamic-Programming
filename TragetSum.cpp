//PROBLEM:You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.


#include<bits/stdc++.h>
using namespace std;
int countSubsetSum(int a[],int sum,int n)
{
    int t[n+1][sum+1];
    t[0][0]=1;
    for(int i=1;i<n+1;i++)
    t[i][0]=1;
   
   for(int i=1;i<sum+1;i++)
    t[0][i]=0;

    	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
		// if the value is greater than the sum
			if (a[i - 1] > j)
				t[i][j] = t[i - 1][j];
			else
			{
				t[i][j] = t[i - 1][j] + t[i - 1][j - a[i - 1]];
			}
		}
	}


	return t[n][sum];
}
int main()
{
    int a[]={1,1,1,1,1};
    int target=3;
    int n=sizeof(a)/sizeof(a[0]);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    int val=(sum+target)/2;
    
    cout<<(countSubsetSum(a,val,n));
    return 0;
}