/*
 *	Problem Name : A. Do Not Be Distracted!
 * 	Problem Url  : https://codeforces.com/problemset/problem/1520/A
 */


#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map> 


using namespace std;
#define debug(x) cout << '> ' << #x << ':' << x << endl;


const int INF =  1e9+5;
template<typename T>
void min_self(T &a, T b){
	a=min(a,b);
}
template<typename T>
void max_self(T &a, T b){
	a=max(a,b);
}


void test_case(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char,bool> m;
	int len = s.length();
	for(int i=0; i<len; ++i){
		if(m[s[i]] == true && s[i] != s[i-1]) {
			//~ for(auto x:m) cout << "[first: "<<x.first << ", second: " << x.second<<"] ";
			cout << "NO" << endl;
			return;
		}
		else{
			m[s[i]] = true;
		}
	}
	cout << "YES" << endl;
}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		test_case();
	}
	return 0;
	
}

/*
 * 
 * 
 * 
 */
