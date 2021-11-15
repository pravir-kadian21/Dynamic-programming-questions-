#include<bits/stdc++.h>
using namespace std;

int count_subset_sum(int n,int *a,int sum){
	int dp[n+1][sum+1];

	for(int j=0;j<sum+1;j++){
		dp[0][j]=0;
	}
	for(int i=0;i<n+1;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(a[i-1]<=j){
				dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}


int count_subset_with_diff(int *a,int n,int diff){
	int sum = 0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	int target = (sum+diff)/2;
	return count_subset_sum(n,a,target);
}




int main(){

	int n; cin>>n;
	int a[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int diff; cin>>diff;
	cout << count_subset_with_diff(a,n,diff) << endl;

	return 0;
}