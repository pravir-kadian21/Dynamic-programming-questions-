#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int *a,int n,int sum){

	bool dp[n+1][sum+1];
	for(int j=0;j<sum+1;j++){
		dp[0][j]=false;
	}
	for(int i=0;i<n+1;i++){
		dp[i][0]=true;
	}

	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(a[i-1]<=j){
				dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

int min_subset_sum_diff(int *a,int n){

	int range = 0;
	for(int i=0;i<n;i++){
		range+=a[i];
	}

	for(int i=range/2;i>=0;i--){
		if(subset_sum(a,n,i)){
			return range-2*i;
		}
	}
}


int main(){

	int n; cin>>n;
	int a[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout << min_subset_sum_diff(a,n) << endl;

	return 0;
}