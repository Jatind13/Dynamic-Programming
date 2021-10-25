#include<bits/stdc++.h>
using namespace std;
int main()
{
   int coin[]={1,2,3};
   int n= sizeof(coin)/sizeof(coin[0]);
   int sum=5;
   int t[n+1][sum+1];
    t[0][0]=1;
     for(int i=1;i<=n;i++){
      t[i][0]=1;
     }
           for(int i=1;i<=sum;i++){
           t[0][i]=0;
           }
           for(int i=1;i<=n;i++)
           {
               for(int j=1;j<=sum;j++)
               {
                   if(coin[i-1]<=j)
                   {
                       t[i][j]=t[i][j-coin[i-1]] + t[i-1][j];
                   }
                   else
                   t[i][j]=t[i-1][j];
               }
           }

           cout<<t[n][sum];
           return 0;
}