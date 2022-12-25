#include<bits/stdc++.h>

using namespace std;

/* ---------------------------------------------------------------------------
					PROBLEM STATEMENT
	Given a SUM and an array of non-negative numbers. Determine if subset of 
	array exists with equal SUM.

-----------------------------------------------------------------------------*/

const int N = 1000;

vector<vector<int>> memo;

int a[N], n;

// Whether sum is possible from subset
//of a[....index]
int subsetSum(int index, int sum) {

	// no elements left for sum
	if(index == -1) return (sum == 0);

	if(memo[index][sum] != -1) return memo[index][sum];

	bool ans = false;
	// include a[index] in sum
	if(sum >= a[index]) {
		ans |= subsetSum(index, sum - a[index]);
	}
	

	// exclude a[index]
	ans |= subsetSum(index - 1, sum);
	return memo[index][sum] = ans;
}


int main() {

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int sum, n;
	cin >> sum >> n;

	memo.resize(n, vector<int>(sum+1, -1));
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << subsetSum(n-1, sum);



	return 0;
}