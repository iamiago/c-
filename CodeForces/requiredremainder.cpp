/*
 *	Problem Name : A. Required Remainder
 * 	Problem Url  : https://codeforces.com/problemset/problem/1374/A
 */


#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

void test (){
	//~ long long answer =0;
		//~ for(int k=n; k>=2; k--){
			//~ cout << "K%X : "<<k%x << endl;
			//~ if(k%x == y){
				//~ cout << k << endl;
				//~ answer=k;
				//~ break;
			//~ }
		//~ }
		//~ if(answer == 0) cout << 0<< endl;
		
}
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	scanf("%d", &t);
	while(t--){
		long long  x,y,n;
		scanf("%lld%lld%lld",&x,&y,&n);
		long long cnt=n/x;
		long long answer = x*cnt +y;
		//~ cout << "n: "<< n << " cnt: "<<cnt << " x: " << x << " y: " << y << " cnt * x +y : "<< answer << endl;

		if(answer>n) answer -= x;
		assert(answer%x==y);
		cout << answer << endl;
		
		
		
	}
	return 0;
	
}
/* On souhaite trouver le plus grand k dans [0,n] tel que k % x = y
 * on commence par le plus grand entier m multiple de x tel que x*m = n <=> m = floor(n/x)
 * ensuite on creer un candidat k = x*m + y <=> k - x*m = y <=> k mod x = y
 * il se peut que k > n au cas quel on soustrait un multiple de x
 * k=x*(m-1)+y  <=> k-=x;
 */
