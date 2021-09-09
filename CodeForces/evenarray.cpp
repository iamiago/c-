/*
 *	Problem Name : B.Even Array
 * 	Problem Url  : https://codeforces.com/problemset/problem/1367/B
 */


#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;

void test_case (){
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	for(int i=0; i<n; ++i){
		scanf("%d",&a[i]);
	}
	int w=0;
	int even = 0, odd =0;
	for(int i=0; i<n; ++i){
		if(i%2 == a[i]%2) continue;
		else{
			if(i%2==0)even++;
			else odd++;
				
			w++;
		}
	}
	
	even==odd? cout << even << endl: cout << -1 << endl;
		
		
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
 * On souhaite trouver le nombre minimum de swaps
 * si les parités ne correspondent pas, c-à-d i%2 != a[i]%2
 * alors on incremente la parite de i c-à-d pair++ ou impair++
 *  
 * si pair==impair on peut effectuer ce nombre de transferts pour que le tableau soit correcte
 * sinon c'est impossible
 */
