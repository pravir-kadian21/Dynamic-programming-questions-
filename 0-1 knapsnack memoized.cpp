#include<bits/stdc++.h>
using namespace std;

int dp[105][105];

int max_profit(int *wt,int *val,int w,int n){
  //base case
  if(w==0||n==0){
    return 0;
  }
  if(dp[n][w]!=-1){
    return dp[n][w];
  }
  //recursive 
  if(wt[n-1]<=w){
    int temp = max(val[n-1]+max_profit(wt,val,w-wt[n-1],n-1),max_profit(wt,val,w,n-1));
    dp[n][w]=temp;
    return temp;
  }
  else{
    int temp = max_profit(wt,val,w,n-1);
    dp[n][w]=temp;
    return temp;
  }
}


int main(){


  int n; cin>>n;

  int wt[10005];
  int val[10005];

  for(int i=0;i<n;i++){
    cin>>wt[i];
  }
  for(int i=0;i<n;i++){
    cin>>val[i];
  }
  int w; cin>>w;

  memset(dp,-1,sizeof(dp));
  cout << max_profit(wt,val,w,n) << endl;

  return 0;
}