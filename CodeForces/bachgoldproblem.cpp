#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int INF = 1e5+5;
int main (){
	int n;
	scanf("%d",&n);
	if(n%2 == 0)
	{	
		cout << n/2 << endl;
		for(int i=0; i<n/2; ++i){
			cout << 2 << " ";
		}
		//~ cout << n/2 << endl;
	}else{
		cout << n/2 << endl;
		for(int i=0; i<(n/2)-1; ++i){
				cout << 2 << " ";
		}
		
		cout << 3 << endl;
	}
	//~ vector<int> a(INF);
	//~ for(int i=0; i<INF; ++i){
		//~ a[i] = i;
	//~ }
	//~ vector<bool> prime(INF,true);
	//~ for(int i=2; i*i<=INF; ++i){
		//~ if(prime[i] == true){
			//~ for(int j=i*i; j<n; j+=i){
				//~ prime[j] = false;
			//~ }
		//~ }
	//~ }
	//~ vector<int> p;
	//~ for(int i=2; i<n; ++i){
		//~ if(prime[i] == true){
			 //~ cout << i << " ";
			 //~ p.push_back(i);
		 //~ }
	//~ }
	//~ cout << endl;

	//~ vector<int> ans;
	//~ map<int,int> answer;
	//~ for(int i=0; i<(int)p.size(); ++i){
		//~ if(n>0 && n/p[i] >0){
			//~ answer.insert(make_pair(p[i],n/p[i]));
			//~ n-=n*(n/p[i]);
		//~ }
		
		//~ cout << "n: " << n << " p[i]: " <<p[i]<<" n/p[i]: "<< n/p[i] << endl;
	//~ }
	//~ int size=0;
	//~ vector<int> b;
	//~ for(auto x : answer){
		//~ size+=x.second;
		//~ for(int i=0; i<x.second; ++i){
			//~ b.push_back(x.first);
			//~ cout << x.first << " ";
		//~ }
	//~ }
	//~ cout << size << endl;
	//~ for(auto x: b) cout << x << " ";
	//~ for(auto x: ans) cout << x << " ";
	//~ cout << ans.size() << endl;
	//~ for(auto x: ans) cout << x << " ";
	//~ cout << endl;

	return 0;
}
