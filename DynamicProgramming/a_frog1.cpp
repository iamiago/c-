#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 5;

int stone(int n, vector<int> h){
	vector<int> dp(n,INF);
	dp[0] =0;
	for(int i=0; i<n; ++i){
		for(int  j  :{i+1,i+2}){
			dp[j] = min(dp[j],dp[i] + abs(h[i]-h[j]));
		}
	}
	// dp[i] - the minimum total cost incurred to reach stone i
	//~ for(auto x:dp) cout << x << " ";
	cout << endl;
	return dp[n-1];
}

int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> h(n);
	for( auto &x :h) cin >> x;
	cout << stone(n,h) << endl;
	return 0;
}
