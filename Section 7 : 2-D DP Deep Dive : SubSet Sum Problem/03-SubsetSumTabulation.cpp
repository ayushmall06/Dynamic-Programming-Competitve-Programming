#include<bits/stdc++.h>

using namespace std;

/* ---------------------------------------------------------------------------
					PROBLEM STATEMENT
	Given a SUM and an array of non-negative numbers. Determine if subset of 
	array exists with equal SUM.

-----------------------------------------------------------------------------*/



int main() {

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int sum, n;
	cin >> sum >> n;

	int a[n+1];
	a[0] = 0;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	bool dp[n + 1][sum + 1];
	dp[0][0] = 1;

	for(int j = 1; j <= sum; j++) {
		dp[0][j] = false;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= sum; j++) {

			// exclusion
			dp[i][j] = dp[i-1][j];


			// inclusion
			if(j - a[i] >= 0) {
				dp[i][j] |= dp[i-1][j - a[i]];
			}
		}
	}


	cout << dp[n][sum];

	



	return 0;
}