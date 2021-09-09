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

const int INF =  1e9+5;
template<typename T>
void min_self(T &a, T b){
	a=min(a,b);
}

void test_case (){
	int n;
	scanf("%d",&n);
	vector<int> a(n), b(n);
	int minb=INF;
	int mina=INF;
	for(int i=0; i<n; ++i){
		scanf("%d",&a[i]);
		min_self(mina,a[i]);
		
	}
	
	for(int i=0; i<n; ++i){
		scanf("%d",&b[i]);
		min_self(minb,b[i]);
	}
	long long ans=0;
	
	for(int i=0; i<n; ++i){
		if(a[i] == mina && b[i] == minb) continue;
		if(a[i] == mina && b[i] > minb) {
			ans += b[i] - minb;
			b[i] = minb;
		}
		if (a[i] > mina && b[i] == minb){
			ans += a[i] - mina;
			a[i] = mina;
		}
		if(a[i] > mina && b[i] > minb){
			int aa = a[i] - mina;
			int bb = b[i] - minb;
			ans += min(aa,bb);
			if (min(aa,bb) == aa ){
				a[i] = aa;
				b[i] -= aa;
				if(b[i] > minb){
					ans += b[i] - minb;
					b[i] = minb;
				}
			}else{
				b[i] =bb;
				a[i] -= bb;
				if(a[i] > mina){
					ans+= a[i] - mina;
					a[i] = mina;
				}
			}
		}
	}
	
	//~ cout << "mina: "<< mina << " minb: " << minb << endl;
	cout << ans << endl;
		
		
}

void test_case2(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	int mina = *min_element(a.begin(), a.end());
	int minb = *min_element(b.begin(), b.end());
	long long ans =0;
	for(int i=0; i<n; ++i){
		ans += max(a[i] - mina, b[i] - minb);
	}
	cout << ans << endl;
}
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	scanf("%d", &t);
	while(t--){
		test_case2();
		
	}
	return 0;
	
}

/*
 * On souhaite trouver le nombre minimum de d'operations pour egalier tout les nombres 
 * dans deux tableau differents
 * 
 * 
 */
