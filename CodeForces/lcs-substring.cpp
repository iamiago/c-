#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int lcs(int i, int j,string s1, string s2, set<char>& ans)
{
	if(i>=(int)s1.size() || j>=(int)s2.size()) return 0;
	if(s1[i] == s2[j]) {
		ans.insert(s1[i]);
		//~ ans += s1[i];
		return 1+lcs(i+1,j+1,s1,s2,ans);
	 }
	else{
		int left = lcs(i+1,j,s1,s2,ans);
		int right = lcs(i,j+1,s1,s2,ans);
		return max(left,right);
	}
}

int lcs(string s1, string s2)
{
	int len1= (int)s1.size();
	int len2= (int)s2.size();
	vector<vector<int>> dp(len1, vector<int>(len2));
	
	for(int i=0; i<len1; ++i){
		for(int j=0; j<len2; ++j){
			if(s1[i] == s2[j]) dp[i][j] = 1 + dp[(i>1)*(i-1)][(j>1)*(j-1)];
			else dp[i][j] = max(dp[(i>1)*(i-1)][j], dp[i][(j>1)*(j-1)]);
		}
	}
	
	return dp[len1-1][len2-1];
}
int main(){
	
	string s1, s2;
	cin >> s1 >> s2;
	//~ set<char> ans;
	//~ cout <<lcs(0,0,s1,s2,ans)<<endl;
	//~ for(auto x: ans) cout << x << "";
	//~ cout << endl;
	cout << lcs(s1,s2);
	return 0;
}
