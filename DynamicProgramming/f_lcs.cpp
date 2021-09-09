/*
 *	Problem Name : F - LCS
 * 	Problem Url  : https://atcoder.jp/contests/dp/tasks/dp_f
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
template <typename T>
void max_self(T &a , T b){
	a=max(a,b);
}
template <typename T>
void min_self(T &a , T b){
	a=min(a,b);
}
const long long INFL = 1e18L  +5;
const int INF = 1e9 +5;
int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a,b;
	cin>> a;
	cin>> b;
	
	vector<vector<int>> dp(a.length()+1, vector<int>(b.length() +1,0));
	//dp[i][j] - the max total length so far
	 
	return 0;
}
