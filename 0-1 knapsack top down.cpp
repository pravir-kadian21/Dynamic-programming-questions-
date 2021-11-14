#include<bits/stdc++.h>
using namespace std;


int max_profit(int *wt,int *val,int w,int n){
  int dp[n+1][w+1];

  for(int i=0;i<n+1;i++){
    for(int j=0;j<w+1;j++){
      if(i==0 || j==0){
        dp[i][j]=0;
      }
    }
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<w+1;j++){
      if(wt[i-1]<=j){
        dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
      }
      else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][w];
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

  
  cout << max_profit(wt,val,w,n) << endl;

  return 0;
}