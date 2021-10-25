#include<bits/stdc++.h>
using namespace std;
int main()
{
    int length[]={1,2,3,4,5,6,7,8};
    int price[]={1,5,8,9,10,17,17,20};
    int rod_length=8;
    int n= sizeof(length)/sizeof(length[0]);
    int t[n+1][rod_length+1];
   for(int i=0;i<n+1;i++)
   {
       for(int j=0;j<rod_length+1;j++)
       {
           if(i==0 || j==0)
           t[i][j]=0;
       }
   }
   for(int i=1;i<n+1;i++)
   {
       for(int j=1;j<rod_length+1;j++)
       {
         if(length[i-1]<=j)
         {
             t[i][j]=max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]); //bss yhin pae change hoga agr element include kr lia hai fir bhi elemnt include ho skta hai in unbounded knapsack so we will process even after including the element.
         }
         else 
         t[i][j]=t[i-1][j];
       }
   }
   cout<<t[n][rod_length];

    return 0;
}
