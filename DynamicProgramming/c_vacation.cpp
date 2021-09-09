#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9 + 5;
int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>> n;
	vector<int> dp(3);
	// dp[i] - the total cost by doing the i-th activity on the last considered day
	for(int day = 0; day<n; ++day){
		vector<int> new_dp(3,0);
		vector<int> c(3);
		for(int i=0; i<3; ++i){
			cin >> c[i];
		}
		// counter for 
		for(int i=0; i<3; ++i){
			// counter for activity
			for(int  j=0; j<3; ++j){
				//he cannot do the same activities for two or more consecuctive days.
				if(j!=i){
					new_dp[j] = max(new_dp[j], dp[i] + c[j]);
					cout << "new_dp["<<j<<"]: " << new_dp[j] << endl;
				}
			}
		}
		dp=new_dp;
	}
	cout << max({dp[0], dp[1], dp[2]}) << endl;
	return 0;
}
