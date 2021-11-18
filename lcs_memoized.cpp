#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int lcs(string s1, string s2, int n, int m)
{
	if (n == 0 || m == 0)
		return 0;

	if(dp[n][m]!=-1){
		return dp[n][m];
	}

	if (s1[n - 1] == s2[m - 1])
	{
		return dp[n][m]=1 + lcs(s1, s2, n - 1, m - 1);
	}
	else
	{
		return dp[n][m]=max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
	}
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	memset(dp,-1,sizeof(dp));
	cout << lcs(s1, s2,s1.length(),s2.length()) << endl;
	return 0;
}