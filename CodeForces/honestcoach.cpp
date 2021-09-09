/*
 *	Problem Name : B. Honest Coach
 * 	Problem Url  : https://codeforces.com/problemset/problem/1360/B
 */


#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>


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

void test_case (){
	int n;
	scanf("%d", &n);
	vector<int> s(n);
	for(int i=0; i<n; ++i){
		scanf("%d",&s[i]);
		
	}
	//~ for(auto x :s) cout << x << " " ;
	//~ int max = *max_element(s.begin(), s.end());
	int ans =INF;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(i!=j) min_self(ans,abs(s[i] - s[j]));
		}
	}
	cout << ans << endl;
		
}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	scanf("%d", &t);
	while(t--){
		test_case();
		
	}
	return 0;
	
}

/*
 * On souhaite trouver le nombre minimum de d'operations pour egalier tout les nombres 
 * dans deux tableau differents
 * 
 * 
 */
