#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main(){
	IOS;
	vector<int> a(4);
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	string s;
	cin>> s;
	int ans = 0;
	for(size_t i =0; i<s.length(); ++i){
		if(s[i] == '1') ans+=a[0];
		else if(s[i] == '2') ans += a[1];
		else if(s[i] == '3') ans += a[2];
		else ans+=a[3];
	}
	cout << ans << endl;
	
	return 0;
}

