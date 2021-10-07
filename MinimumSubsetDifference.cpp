#include<bits/stdc++.h>
using namespace std;
int subsetSum(int a[],int sum,int n)
{
 bool t[n+1][sum+1];

   for(int i=0;i<n+1;i++)
       t[i][0]=true;

       for(int i=0;i<sum+1;i++)  //Initialization of matrix
       t[0][i]=false;

   for(int i=1;i<n+1;i++)
   {
       for(int j=1;j<sum+1;j++)
       {
         if(a[i-1]<=j)  //val array is neglected when we have tow choose any one from we use wt[] of jnapsack
         {
             t[i][j]= t[i-1][j-a[i-1]] || t[i-1][j]; //replaced max with || because values are boolean
         }
         else 
         t[i][j]=t[i-1][j];
       }
   }
   // now we will move in the last row of the matrix and look for the values which are true and //can form subset and then take the minimu m difference of them.
    int diff = INT_MAX;
  
    // Find the largest j such that t[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j = sum / 2; j >= 0; j--) {
        // Find the
        if (t[n][j] == true) {
            diff = min(diff,(sum - 2 * j));
    
        }
    }
    return diff;
}
int main()
{
    //int a[]={1,6,11,5};
    int a[]={1,2,7};
    // int a[] = { 3, 1, 4, 2, 2, 1 };
    int n=sizeof(a)/sizeof(a[0]);
    int range=0;
    for(int i=0;i<n;i++)
    {
        range+=a[i];
    }
    cout<<(subsetSum(a,range,n));
    return 0;
}