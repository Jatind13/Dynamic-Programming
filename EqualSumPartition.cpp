#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[],int sum,int n)
{
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



int main()
{
    int a[]={2,5,11,5};
     int n=sizeof(a)/sizeof(a[0]);
     int sum=0;
     for(int i=0;i<n;i++)
     {
         sum+=a[i];
     }
     if(sum%2 !=0)
     cout<<false;
     else  if(sum%2==0)
     subsetSum(a,sum/2,n);
return 0;
}