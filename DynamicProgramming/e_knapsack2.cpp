/*
 *	Problem Name : E - Knapsack 2
 * 	Problem Url  : https://atcoder.jp/contests/dp/tasks/dp_e
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T>
void max_self(T &a , T b){
	a=max(a,b);
}
template <typename T>
void min_self(T &a , T b){
	a=min(a,b);
}
const long long INF = 1e18L  +5;
int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, W;
	cin>>n>>W;
	vector<int> weight(n), value(n);
	for(int i=0; i<n; ++i){
		cin>>weight[i]>>value[i];
	}
	int sum_value=0;
	for(int  x : value){
		sum_value += x;
	}
	//~ cout << sum_value << endl;
	vector<long long> dp(sum_value+1,INF);
	dp[0] = 0;
	//dp[i] - the minimum total weight of items with total value exactly i
	for(int item = 0; item <n; ++item){
		
		for(int value_already =sum_value-value[item]; value_already >= 0; --value_already){
			min_self(dp[value_already +value[item]] ,dp[value_already] +weight[item]);
			//~ dp[value_already +value[item]] = max ( dp[value_already +value[item]],dp[value_already] +value[item]);
			//~ max_self(dp[value_already +value[item]], dp[value_already] +value[item]);
		}
	}
	//~ for(auto x: dp) cout << x << endl;
	long long answer =0;
	for(int i=0; i<= sum_value; ++i){
		if(dp[i] <= W){
			answer = max(answer,(long long) i);
		}
		//~ min_self(answer,dp[i]);
	}
	cout << answer << "\n";
	return 0;
}
