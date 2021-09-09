#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[2*n];
		for(int i=0; i<2*n; ++i){
			scanf("%d",&a[i]);
		}
		vector<int> used(n);
		vector<int> ans;
		for (int i=0; i<2*n; ++i){
			if(!used[a[i] -1]){
				used[a[i] -1] = 1;
				ans.push_back(a[i]);
			}
		}
		for(auto x: ans) cout << x << " ";
		cout << endl;
		
		//~ for (auto x:a) cout << x << " ";
		//~ cout << endl;
	}
	return 0;
}
