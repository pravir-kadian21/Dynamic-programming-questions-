#include<bits/stdc++.h>
using namespace std;


bool subset_sum(int n,int *arr,int sum){
  bool dp[n+1][sum+1];
  for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
      if(j==0){
        dp[i][j]=true;
      }
      else if(i==0 && j!=0){
        dp[i][j]=false;
      }
    }
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<sum+1;j++){
      if(arr[i-1]<=j){
        dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
      }
      else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][sum];
}

int main(){


  int n; cin>>n;

  int arr[100];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int sum; cin>>sum;
  if(subset_sum(n,arr,sum)){
    cout << "true" << endl;
  }
  else{
    cout << "false" << endl;
  }

  return 0;
}