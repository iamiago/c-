#include <iostream>
using namespace std;
#define print(...) ' [' << #__VA_ARGS__": " << (__VA_ARGS__)  << "] "
int main(){
	
	int t; scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		cout<<print(a)<<endl;
		//~ if(a==b) cout << 0 << endl;
		//~ else if(a%2==0 && b%2==1) cout << 1 << endl;
		//~ else if(a%2==1 && b%2==0) cout << 2 << endl;
		//~ else if(a%2==0 && b%2==0) cout << 2 << endl;
		//~ else if(a%2==1 && b%2==1) cout << 1 << endl;
	}
	
	return 0;
}
