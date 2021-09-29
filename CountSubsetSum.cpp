#include <bits/stdc++.h>
using namespace std;

int subsetSum(int a[], int n, int sum)
{
	// Initializing the matrix
	int t[n + 1][sum + 1];
// Initializing the first value of matrix
	t[0][0] = 1;
	for (int i = 1; i <= sum; i++)
		t[0][i] = 0;
	for (int i = 1; i <= n; i++)
		t[i][0] = 1;

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
	int n = 6;
	int a[] = {2,3,5,6,8,10};
	int sum = 10;

	cout << (subsetSum(a, n, sum));
}