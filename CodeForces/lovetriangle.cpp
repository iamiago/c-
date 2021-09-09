#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n; 
	cin>>n;
	//~ int f[n];
	vector<int> f(n+1);
	for(int i=0; i<n; ++i){
		cin>> f[i];
	}
	
	for(int i=0; i<n; ++i){
		if(f[f[f[i]]] == i) {cout << "yes" << endl; return 0;}
	}
	cout << "no" << endl;
	
	return 0;
}
