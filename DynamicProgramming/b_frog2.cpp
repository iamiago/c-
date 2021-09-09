#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9 + 5;
int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,k;
	cin>>n>>k;
	vector<int> h(n);
	for(auto&x:h) cin >> x;
	vector<int> dp(n,INF);
	dp[0] =0;
	for(int i=0; i<n; ++i){
		for(int  j =i+1; j<=i+k; j++){
			dp[j] = min(dp[j], dp[i] + abs(h[i]-h[j]));
		}
	}
	cout << dp[n-1];
	return 0;
}
