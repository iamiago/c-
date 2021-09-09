/*
 *	Problem Name : B.Gifts Fixing
 * 	Problem Url  : https://codeforces.com/problemset/problem/1399/B
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
	int a,b;
	scanf("%d%d",&a,&b);
	//~ debug(a);
	cout << min(max(2*b,a),max(2*a,b))*min(max(2*b,a),max(2*a,b)) << endl;
		
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
