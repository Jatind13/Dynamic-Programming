#include<bits/stdc++.h>
using namespace std;
int main()
{
    int coin[]={1,2,3};
    int sum=5;
int n=sizeof(coin)/sizeof(coin[0]);
int t[n+1][sum+1];
t[0][0]=INT_MAX-1;
for(int i=1;i<=sum;i++)
  t[0][i]=INT_MAX-1;
  for(int i=1;i<=n;i++)
  t[i][0]=0;
  for(int j=1;j<=sum;j++)
  {
      if(j/coin[0]==0)
      t[1][j]=j/coin[0];
      else
      t[1][j]=INT_MAX-1;
  }
//   for(int i=0;i<=n;i++)
//   {
//       for(int j=0;j<=sum;j++)
//       {
//           cout<<t[i][j]<<" ";
//       }
//       cout<<endl;
//   }
for(int i=2;i<=n;i++)
{
    for(int j=1;j<=sum;j++)
    {
        if(coin[i-1]<=j)
        {
            t[i][j]=min(t[i-1][j],t[i][j-coin[i-1]]+1);
        }
        else 
        t[i][j]=t[i-1][j];
    }
}
cout<<t[n][sum];
  
    return 0;
}