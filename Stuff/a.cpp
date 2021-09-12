#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

void solve(int i){
    ll cnt[2]={0};
    ll x;
    ll n;
    cin >>n;

    for(ll i=0; i<2*n; i++){
        cin>>x;
        ++cnt[x % 2];
    }

   // cout << cnt[0] << cnt[1] << endl;
    cout << (cnt[0]==cnt[1] ? "YES\n" : "NO\n");
}

int main()
{   
    #ifdef iagodev_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
    cout<<setprecision(15)<<fixed;
    ll t;
    cin>> t;
    for(ll i=0; i<t; i++){
        solve(i);
    }
    #ifdef iagodev_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}
