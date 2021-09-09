#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int minCostPath(int row, int col, vector<vector<int>> &grid)
{
	int n=grid.size();
	int m=grid[0].size();
	
	if(row == (n-1) && col == (m-1)) return grid[row][col];
	if(row>=n || col>=m) return 1000;
	
	int right = grid[row][col] + minCostPath(row, col+1, grid);
	int left = grid[row][col] + minCostPath(row+1, col, grid);
	
	return min(left,right);
	
}

int minCostPathMemo(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp)
{
	int n=mat.size();
	int m=mat[0].size();
	
	if(i == (n-1) && j == (m-1)) return mat[i][j];
	
	if(i >= n || j >= m ) return 100000;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	int right = mat[i][j] + minCostPathMemo(i, j+1, mat, dp);
	int left = mat[i][j] + minCostPathMemo(i+1, j , mat, dp);
	
	dp[i][j] = min(right,left);
	
	return dp[i][j];
}

int minCostPathIterative( vector<vector<int>>& grid, vector<vector<int>>& dp)
{
	int n=grid.size();
	int m=grid[0].size();
	dp[0][0] = 0 ;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			
			dp[i][j] = grid[i][j] +  min(dp[i][(j>0)*(j-1)],dp[(i>0)*(i-1)][j]) ;
			cout << dp[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	
	return dp[n-1][m-1];
}

int minCost(vector<vector<int>>& grid, vector<vector<int>>& dp)
{
	dp[0][0] = grid[0][0];
	for(size_t i =0; i<grid.size(); ++i){
		for(size_t j =0; j<grid[0].size(); ++j){
			if(i<grid.size()-1) dp[i+1][j] =  grid[i][j] + dp[i][j];
			if(j<grid[0].size()-1)dp[i][j+1] = grid[i][j] + dp[i][j]; 
			//~ cout<< dp[i][j] << "  " ;
		}
		//~ cout << endl;
	}
	return dp[grid.size()-1][grid[0].size()-1];
}

/*
 * 
 * 3 3
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * 
 */

int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> grid(n, vector<int>(m,0));
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin>>grid[i][j];
		}
	}
	
	//~ cout << minCostPath(0,0,grid)<< endl;
	
	//~ vector<vector<int>> dp(n,vector<int>(m,-1));
	//~ cout << minCostPathMemo(0,0,grid,dp)<< endl;
	
	//~ vector<vector<int>> dp2(n,vector<int>(m,0));
	//~ cout << minCost(grid,dp2) << endl;
	
	vector<vector<int>> dp3(n,vector<int>(m,10000));
	cout << minCostPathIterative(grid, dp3);
	return 0;
}
