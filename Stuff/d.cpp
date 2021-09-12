#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
ll mod = 1000000000 + 7;
ll n;


long long lcm(long long  a, long long b){
    return a * b / __gcd(a,b);

}


void solve(int i){
    cin>>n;
    vector <ll> f(50) , g(50);
     

    ll lc=1;
    for(ll i=1; i<=50; i++){
        lc=lcm(lc,i);
        g[i] =  n-n/lc;
        f[i] = g[i] - g[i-1];

    }
    ll ans=0;
    for( ll i = 2; i<= 50; i++){
        ans = (ans+ i * f[i]) % mod;

    }
    cout << ans << "\n";
   

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
