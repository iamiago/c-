#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &x :a) cin>>x;
	
	vector<pair<int,int>> gather;
	for(int s=1; s<=n; ++s){
		for(int t=1; t*s<=n; ++t){
			int next_index=0;
			int sets_A =0, sets_B=0;
			bool is_ok = true;
			cerr<<"s : " << s << " t: " << t << " next_index : "<< next_index<< endl;
			while(max(sets_A,sets_B) < s && next_index <n){
				int A =0, B=0;
				while(max(A,B) <t && next_index < n){
					cerr<< "	A: " << A <<" B: "<< B <<" next_index: " <<next_index << " a[next_index]: "<< a[next_index] << "\n"; 
					if(a[next_index] == 1){
						++A;
					}else{
						++B;
					}
					++next_index;
					//~ cerr<< "	A: " << A <<" B: "<< B <<" next_index: " <<next_index << " a[next_index]: "<< a[next_index] << "\n"; 

				}
				if(max(A,B)<t) is_ok=false;
				if(A==t)sets_A++;
				else sets_B++;
				
				cerr<< "	sets_A: " << sets_A <<" sets_B: "<< sets_B << "\n"; 
			}
			if(max(sets_A,sets_B) <s) is_ok=false;
			if(next_index < n) is_ok=false;
			if(is_ok) {
				gather.push_back({s,t});
				cout << "{s,t} : "<< "{" << s << ", "<< t << "}\n";		
			}
		}
		
	}
	cout << gather.size() << "\n";
	for(auto p:gather) cout << p.first << " "<< p.second << "\n";
	
	
	return 0;
}
