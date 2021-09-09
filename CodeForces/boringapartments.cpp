#include <iostream>
//~ #include <bits/stdc++.h>
using namespace std;

int nb_digits(int n){
	int ans =0;
	while(n>0){
		n/=10;
		ans++;
	}

	return ans;
}

int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin>>x;	
		
		int nb = (x%10) ;
		int ans=0;
		for(int i=1; i<=nb-1; ++i){
			ans+=10;
		}
		//1+2+...+nb_digits = nb_digits*(nb_digits+1)/2
		for(int i=1; i<=nb_digits(x); ++i){
			ans+=i;
		}
		//~ ans+=nb_digits(x);
		//~ cout << nb_digits(x) <<" " << x%10 << " " << ans <<endl;
		cout << ans << endl;
	}
	return 0;
}


/*			22
 * 			1, 11, 111, 1111
 * 			2, 22
 */
