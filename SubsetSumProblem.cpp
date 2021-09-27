#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={2,3,7,8,10};
   int sum=10;
   //approach is as same and simple as knapsack with some variations in matrix.
    int n= sizeof(arr)/sizeof(arr[0]);
    bool t[n+1][sum+1];
   for(int i=0;i<n+1;i++)
   {
       for(int j=0;j<sum+1;j++)  //Initialization of matrix
       {
           if(i==0)
           t[i][j]=false;
          else if(j==0)
           t[i][j]=true;
       }
   }
   for(int i=1;i<n+1;i++)
   {
       for(int j=1;j<sum+1;j++)
       {
         if(arr[i-1]<=j)  //val array is neglected when we have tow choose any one from we use wt[] of jnapsack
         {
             t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j]; //replaced max with || because values are boolean
         }
         else 
         t[i][j]=t[i-1][j];
       }
   }
   cout<<t[n][sum];
}