#include <iostream>
#include <vector>
using namespace std;

// fibonnaci recursively
int fibonnaci(int n){
	if(n<=0) return 0;
	if(n==1) return 1;
	return fibonnaci(n-1)+fibonnaci(n-2);
}
// fibonnaci with memoization
vector<long long> f(10005,0);
vector<bool> is_computed(10005,false);
long long fibonnacimemo(int n){
	if(n<2) return n;
	if(is_computed[n]) return f[n];
	
	f[n]=fibonnacimemo(n-1)+fibonnacimemo(n-2);
	is_computed[n] = true;
	
	return f[n];
}

// fibonnaci iteratively (tabulation)
long long fibonnacitab(int n){
	
	long long a[1001];
	a[0] =0;
	a[1] =1;
	for(int i=2; i<=n; ++i){
		a[i] =a[i-1]+a[i-2];
	}
	return a[n];
}
vector<long long> stair(10005,0);
vector<bool> is_stair_computed(10005,false);

long long stairs(int n){
	if(n==0) return 1;
	if(n<0) return 0;
	if(is_stair_computed[n]) return stair[n];
	
	long long total =0;
	
	for(int i :{1,2}){
		 total+= stairs(n-i);
	}
	stair[n] = total;
	is_stair_computed[n] =true;
	return stair[n];
	
	
}

long long stairstab(int n){
	vector<long long> a(n+1,0);
	a[0] = 1;
	for(int i=0; i<=n; ++i){
		if(i+1<=n) a[i+1] +=a[i] ;
		if(i+2<=n) a[i+2] +=a[i] ;
			
	}
	return a[n];
}

//combination sum recursively
//Given the target value N and an array of allowed numbers,
//count ways to write N as the sum of those numbers
long long combSum(int target, vector<int> nums){
	if (target ==0) return 1;
	if (target <0) return 0;
	long long total = 0;
	for(int i=0; i<(int)nums.size(); ++i){
		total += combSum(target-nums[i],nums);
	}
	return total;
}

//combination sum with memoization
vector<long long> sum(10005,0);
vector<bool> is_comb_computed(10005,false);
long long combSumMemo(int target, vector<int> nums){
	if(target ==0) return 1;
	if(target <0) return 0;
	if(is_comb_computed[target]) return sum[target];
	long long total =0;
	for(int i=0; i<(int)nums.size(); ++i){
		total += combSumMemo(target-nums[i],nums);
	}
	is_comb_computed[target] =true;
	sum[target]=total;
	return sum[target];
}

//combination sum with tabulation

long long combSumTab(int target, vector<int> nums){
	vector<long long> a(target+1, 0);
	a[0] =1;
	for(int i=0; i<=target; ++i){
		for(auto x : nums){
			a[i+x] += a[i];
		}
	}
	return a[target];
	
}

//Coin change (min) recursively
//You are given denominations of coins and the target amount N
//What is the minimum possible number of coins used?


// this count all the possible ways (not answering the question)
long long coinsChangeWay(int target, vector<int> coins){
	//~ vector<int> ans;
	if(target == 0) return  1;
	if(target < 0) return 0;
	long long total =0;
	
	for(int i=0;i<(int)coins.size(); ++i){
		total += coinsChangeWay(target-coins[i],coins);
		}
		
	
	return total;
	
}
int INF = 1e5+5;
// coin change min tabulation
long long coinsMinTab(int target, vector<int> coins){
	vector<long long> dp(target+1,INF);
	dp[0] =0;
	for(int i=1; i<target+1; ++i){
		for(auto coin : coins){
			if(i-coin>=0) {
				//~ cout << "dp["<<i<<"]: "<<dp[i] <<" dp["<< (i-coin) << "]: "<<dp[i-coin]  << endl;
				dp[i] = min(dp[i],dp[i-coin]+1);
				//~ cout << "dp["<<i<<"]: "<<dp[i] <<" dp["<< (i-coin) << "]: "<<dp[i-coin]  << endl;
		}

		}
	}
	return dp[target];
}


//Line of wines
// There are N wines in a row. Each year you sell either the leftmost or the rightmost wine.
// The i-th wine has initial price p[i] and price k*p[i] in the k-th year.
// What is the maximum total profit?



int main(){
	for(int i=0; i<40; ++i){
		cout << fibonnaci(i) << " ";
	}
	cout << "\n";
	
	for(int i=0; i<50; ++i){
		cout << fibonnacimemo(i) << " ";
	}
	cout << "\n";
	
	for(int i=0; i<50; ++i){
		cout << fibonnacitab(i) << " ";
	}
	cout << "\n";
	
	
	cout << fibonnaci(4) << endl;
	cout << "stairs " << endl;
	cout << stairs(48) << endl;
	cout << stairstab(48) << endl;
	
	cout << "combination sum " << endl;
	cout << combSum(4,{1,2,3}) << endl;
	cout << combSumMemo(4,{1,2,3}) << endl;
	cout << combSumTab(4,{1,2,3}) << endl;
	
	cout << "coins min " << endl;
	
	cout << coinsMinTab(6,{1,3,4}) << endl;
	
	cout << "coins change ways" << endl;
	cout << coinsChangeWay(6,{1,3,4}) << endl;
	cout << coinsChangeWay(5,{1,2,5}) << endl;
	
	
	//~ for(int i=0; i<50; ++i){
		//~ cout << "i:"<<i << " stairs(i):" <<stairs(i) << " \n";
	//~ }
	return 0;
}
