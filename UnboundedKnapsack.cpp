#include<bits/stdc++.h>
using namespace std;
int main()
{
    int wt[]={1,50};
    int val[]={1,30};
    int w=100;
    int n= sizeof(val)/sizeof(val[0]);
    int t[n+1][w+1];
   for(int i=0;i<n+1;i++)
   {
       for(int j=0;j<w+1;j++)
       {
           if(i==0|| j==0)
           t[i][j]=0;
       }
   }
   for(int i=1;i<n+1;i++)
   {
       for(int j=1;j<w+1;j++)
       {
         if(wt[i-1]<=j)
         {
             t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]); //bss yhin pae change hoga agr    element include kr lia hai fir bhi elemnt include ho skta hai in unbounded knapsack so we will process even after includinbg the element.
         }
         else 
         t[i][j]=t[i-1][j];
       }
   }
   cout<<t[n][w];

    return 0;
}
