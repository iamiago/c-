#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

void solve(int i){
  ll n,a,b;
  cin>>n>>a>>b;
    if(a==1){
        // si a=1 , les multiplications ne servent a rien
        cout<< (b==1||n%b == 1 ? "Yes \n" : "No \n");

    }else{
        // on garde la trace de la puissance actuelle
        ll p=1;
        while(p<=n){
            if (b==1||n%b == p%b){
                cout << "Yes \n";
                return;
            }
            p *= a;
        }
        cout<<"No \n";

    }

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
#