#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main(){
	IOS;
	int t;
	cin>>t;
	while(t--){
		int w,h,n;
		cin>>w>>h>>n;
		//~ if( h%2==0 or w%2==0) cout << "We have a even number " << endl;
		int ans=1;
		while(w%2 == 0){
			ans*=2;
			w/=2;
		}
		while(h%2 == 0){
			ans*=2;
			h/=2;
		}
		
		if(ans >= n) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}

