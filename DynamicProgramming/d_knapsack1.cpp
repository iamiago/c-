#include <iostream>
#include <vector>
using namespace std;



int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,W;
	cin>>N>>W;
	vector<int> w(N), v(N);
	for(int i=0; i<N; ++i){
		cin>>w[i]>>v[i];
	}
	//~ vector<int> dp(W+1,0);
	//~ for(int i=0; i<N; ++i){
		//~ if(W>=0){
			//~ dp[i+1] = max (dp[i+1], dp[i] + v[i]);
			//~ W-=w[i];
		//~ }
	//~ }
	//~ for(auto x: dp) cout << x << " " ;
	//~ cout << endl;
	

	//~ for(auto d: dp){ 
		//~ for(auto x: d){ 
			//~ cout << x << " ";
		//~ }
		//~ cout << endl;
	//~ }
	
	//dp[N][W] = the maximum possible value by selecting items in {1,2,..,N} with weight limit W
	//dp[N][W] = sum(v[1],..v[N]) and sum(w[1],..,w[n])<=W
	//if there are i packages to choose
	//dp[i][j] is the optimal sum of values of items when the maximum weight of this sum is j				
	// example:
	//dp[4][10] = 8 , it means in the optimal case, the total sum of the selected values is 8
	//				, when there are 4 items to chose from {1,2,3,4}
	//				, and the maximum weight of selected items is 10
	// dp[1][4] = 3 , it means when there is 1 item to chose
	//				, and the maximum weight of selected item is 4
	// 				, the total sum of the selected values is 3
	//dp[0][W] = 0  , it means in the optiaml case, the total sum of the selected values is 0
	//				, when tehere are 0 items to chose from
	//				, and the maximum weight of selecte items is  W
	// since 1<= <w[i] <= W
	// dp[1][j]=v[1]; when thre is 1 item to chose and the maximum wight of selected items is w[1]
	//				; the total sum of selected items is v[1]
	
	//when the weight limit is W
	//
	// The optimal solution among items  {1,2,..,i-1,i} to have the largest sum of values will have 2 possibilites:
	//
	//first: if the i package is not selected dp[i][W] = dp[i-1][W];
	//second: if the i package is selected and sum of weights of items selected <= W
	// then dp[i][W] = v[i] +  dp[i-1][W-w[i]];
	//
	//
	/*
	vector<vector<long long>> dp(N+1,vector<long long>(W+1,0));
	for(int i=1; i<=N;  ++i){
		for(int j=0; j<=W; ++j){
			dp[i][j] = dp[i-1][j];
			if((j>=w[i-1]) && (dp[i][j] < dp[i-1][j-w[i-1]] +v[i-1])){
				dp[i][j] =dp[i-1][j-w[i-1]] +v[i-1];
			}
		}
	}
	//~ for(auto d: dp){ 
		//~ for(auto x: d){ 
			//~ cout << x << " ";
		//~ }
		//~ cout << endl;
	//~ }
	cout << dp[N][W] << endl;
	*/
	
	
	vector<long long> dp(W+1);
	// dp[i] = the maximum possible sum of values by 
	//				selecting items in {1,2,...,i} 
	//				with sum of weights of items = i
	// dp[W] = the maximum possible sum of values by selecting items in {1,...,N} with sum of weights = W
	for(int i=0; i<N; ++i){
		for(int weight_already = W-w[i]; weight_already >= 0; --weight_already){
		//~ for(int weight_already = 0; weight_already <= W - w[i]; ++weight_already){
			
			dp[weight_already+w[i]] = max (dp[weight_already+w[i]], dp[weight_already] + v[i]);
			//~ cout << weight_already << " : " << dp[weight_already] << endl;
			cout << "j:"<<weight_already<<" ["<<weight_already+w[i]<<"]" << " : " << dp[weight_already+w[i]] << ", ";
		}
		cout << endl;
	}
	cout << endl;
	
	for(auto x: dp) cout << x << " ";
	cout << endl;
	
	long long answer = 0;
	for(int i=0; i<=W; ++i){
		answer = max(answer,dp[i]);
	}
	cout << answer << endl;
	
	
	return 0;
}
