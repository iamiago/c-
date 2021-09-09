#include <iostream>
#include <algorithm>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
//#define int long long


template<typename T>
void max_self(T& a, T b){
	a=max(a,b);
}
template<typename T>
void min_self(T& a, T b){
	a=min_self(a,b);
}

const long long INFL = 1e18L+5;
const int INF = 1e9+5;

int32_t main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; 
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		//~ int ans=0;
		//~ for(int i=1; i<=n; ++i){
			//~ for(int j=i+1; j<=n; ++j){
				//~ //cout << i << " " << j <<" "<<__gcd(i,j) << endl;
				//~ max_self(ans,__gcd(i,j));
			//~ }
		//~ }
		//~ cout << ans << endl;
		cout << n/2 << endl;
	}
	
	return 0;
}

//~ g = gcd(a,b)

//~ =>   g <= a,b
	//~ since a,b <= n
	
	//~ and the next multiple of g is 2*g
	//~ we need to have
	//~ 2*g <= n
