#include <iostream>
#include <vector>
using namespace std;

int count(int ind, int sum, int nums[], int n)
{
	if(sum == 0) return 1;
	if(ind>=n || sum<0) return 0;
	
	int left = count(ind, sum-nums[ind], nums, n);
	int right = count(ind+1, sum, nums, n);
	
	return left+right;

}	

int countMemo(int ind, int sum, int nums[], int n, vector<vector<int>>& dp)
{
	if(sum == 0) return 1;
	if(ind>=n || sum <0) return 0;
	
	if(dp[ind][sum] != -1) return dp[ind][sum];
	
	int left = countMemo(ind, sum-nums[ind],nums,n,dp);
	int right = countMemo(ind+1,sum,nums,n,dp);
	
	dp[ind][sum] = left+right;
	return dp[ind][sum];
}

int main()
{
	int nums[] = {1,2};
	int sum = 4;
	int n = 2;
	
	cout << count(0,sum,nums,n) << endl;
	
	vector<vector<int>> dp(n, vector<int>(sum+1,-1));
	cout << countMemo(0,sum,nums,n,dp) << endl;
	return 0;
}
