#include <iostream>
#include <vector>
using namespace std;
void printv(vector<vector<int>> dp){
	const int n= dp.size();
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cout << "dp["<<i<<"]["<<j<<"] : " << dp[i][j];
			if( j!=n-1) cout << ", ";
		}cout << endl;
	 }cout << endl;
 }
int maxCoins(vector<int> nums){
	if(nums.empty()){
		return 0;
	}	
	const int n= nums.size();
	vector<vector<int>> dp(n,vector<int>(n));
	for(int L=n-1; L>=0; L--){
		for(int R=0; R<n; ++R){
			//~ cout << dp[L][R] << " ";
			for(int i=L; i<=R; ++i){
				cout << nums[i]*(L!=0?nums[L-1]:1)*(R==n-1?1:nums[R+1]) + (L<=i-1?dp[L][i-1]:0) +(i+1<=R?dp[i+1][R]:0) << endl;
				dp[L][R] = max(dp[L][R], nums[i]*(L!=0?nums[L-1]:1)*(R==n-1?1:nums[R+1]) + (L<=i-1?dp[L][i-1]:0) +(i+1<=R?dp[i+1][R]:0));
				cout << "L: "<<L <<", R: "<< R << endl;
				int a,b,c,d,e;
				a=nums[i];
				b=L!=0?nums[L-1]:1;
				c=R==n-1?1:nums[R+1];
				d=L<=i-1?dp[L][i-1]:0;
				e=i+1<=R?dp[i+1][R]:0;
				cout << a << "*"<<b << "*"<<c<< " + "<<d<< " + "<<e << " = " << a*b*c+d+e<< endl;
				printv(dp);
			}
		}
		
	}
	return dp[0][n-1];
}

void maxCoins2(vector<int> a){
		//~ if(a.empty()){
			//~ return 0;
		//~ }
		const int n= a.size();
		vector<vector<int>> dp(n,vector<int>(n));
		// from left to right
		vector<int> leftToRight(n);
		for(int i=0; i<n ; ++i){
			leftToRight[i] = a[i]*(i?a[i-1]:1)*(i+1<=n-1?a[i+1]:1);
		}
		for(auto x: leftToRight) cout << x << " ";
		cout << endl;
		
		vector<int> rightToLeft(n);
		for(int i=n-1; i>=0; --i){
			rightToLeft[(n-1)-i] = a[i]*(i?a[i-1]:1)*(i+1<=n-1?a[i+1]:1);
		}
		for(auto x : rightToLeft) cout << x << " ";
		cout << endl;
		vector<vector<int>> all (n, vector<int> (n));
		for(int i=n-1; i>=0; i--){
			for(int j=0; j<n; ++j){
				//~ all[i][j] = max(a[i]*(i?a[i-1]:1)*(i+1<=n-1?a[i+1]:1),a[j]*(j?a[j-1]:1)*(j+1<=n-1?a[j+1]:1));
				for(int k=i; k<j; ++k){
					all[i][j] = max(all[i][j],a[i]*(i?a[i-1]:1)*(i+1<=n-1?a[i+1]:1) +(i<=k-1?all[i][k-1]:0) +(i+1<=j?all[k+1][j]:0));

					//~ cout << (i<=k-1?all[i][k-1]:0) +(i+1<=j?all[k+1][j]:0) << endl;
					printv(all);
				}
				
			}
		}
		
}
/*		3 1 5 8
 * 		
 * 
 * 
 */

int main(){
	
	
	cout << maxCoins({3,1,5,8}) << endl;
	//~ maxCoins2({3,1,5,8});
	return 0;
}
