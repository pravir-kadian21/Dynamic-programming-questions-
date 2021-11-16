#include <bits/stdc++.h>
using namespace std;

int rod_cutting(int *price,int *arr,int n,int length){
	int dp[n+1][length+1];
	for(int i=0;i<n+1;i++){
		dp[i][0]=0;
	}	
	for(int j=0;j<length+1;j++){
		dp[0][j]=0;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<length+1;j++){
			if(arr[i-1]<=j){
				dp[i][j]= max(price[i-1]+dp[i][j-arr[i-1]],dp[i-1][j]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][length];
}

int main(){
	int n; cin>>n;
	int price[100];
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	int arr[100];
	for(int i=0;i<n;i++){
		arr[i]=i+1;
	}
	cout << rod_cutting(price,arr,n,n) << endl;
}/*  */