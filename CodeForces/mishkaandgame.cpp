/*
 *	Problem Name : A. Mishka and Game
 * 	Problem Url  : https://codeforces.com/problemset/problem/703/A
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



int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int mish=0, chris=0;
	for(int i=0; i<n; ++i){
		int m,c;
		cin>>m>>c;
		if(m==c) continue;
		if(m>c) mish++;
		if(m<c) chris++;
		if(chris>n/2 || mish>n/2) break;
		
	}
	if(chris == mish)  cout << "Friendship is magic!^^" <<endl;
	if(chris > mish)  cout << "Chris" << endl;
	if(chris < mish)  cout << "Mishka" << endl;
	return 0;
	
}

/*
 * On souhaite trouver le nombre minimum de d'operations pour egalier tout les nombres 
 * dans deux tableau differents
 * 
 * 
 */
