#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int w,int n,int t[][1002])
{
    if(n==0 || w==0)
    return 0;

    if(t[n][w]!=-1)
    return t[n][w];

    else if(wt[n-1]<=w)
    {
        return t[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1,t), knapsack(wt,val,w,n-1,t));
    }

    else
    {
        return t[n][w]=knapsack(wt,val,w,n-1,t);
    }

}


int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int t[102][1002];
    memset(t,-1,sizeof(t));
   int prft= knapsack(wt,val,7,5,t);
   cout<<prft;
    return 0;
}
