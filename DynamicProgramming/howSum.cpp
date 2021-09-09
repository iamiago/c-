#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// howSum recursively
bool howSum(int targetSum, vector<int> numbers, vector<int> &ans){
	if(targetSum==0) return true;
	if(targetSum <0) return false;
	for(auto x:numbers){
		int remainder = targetSum- x;
		if(howSum(remainder,numbers, ans)){
			 ans.push_back(x);
			 return true;
		}
	}
	return false;
}
// howSum with memoization
int INF = 1e5+5;
// howSum with tabulation
vector<int> howSumTabulation(int target, vector<int> numbers){
	vector<vector<int>> a(target+1, vector<int>(1,-1) );
	a[0][0] = 0;
	//~ for(int k=0; k<(int)a.size(); ++k){
		//~ for(int i=0; i<(int)a[k].size(); ++i){
			//~ cout << a[k][i] << " ";
		//~ }
		//~ cout <<"\n";
		
	//~ }
	//~ cout << "\n";
	for(int i=0; i<(int)a.size(); ++i){
		if(a[i][0] != -1){
			for(auto x : numbers){
				if(i+x<=target){
					if(a[i+x][0] == -1)
					a[i+x][0] = x;
					else {
						a[i+x] = a[i];
						a[i+x].push_back(x);
					}
				}
			}
		}
	}
	//~ for(int k=0; k<(int)a.size(); ++k){
		//~ for(int i=0; i<(int)a[k].size(); ++i){
			//~ cout << a[k][i] << " ";
		//~ }
		//~ cout <<"\n";
		
	
	
	
	return a[target];
	
}

int main (){
	vector<int> ans, ans1, ans2;
	howSum(7,{2,3},ans);
	for(auto x:ans) cout << x << " ";
	cout << "\n";
	
	howSum(7,{5,3,4,7},ans1);
	for(auto x:ans1) cout << x << " ";
	cout << "\n";
	
	howSum(7,{2,4},ans2);
	if(ans2.empty()) cout << "null\n";
	else for(auto x:ans2) cout << x << " ";
	cout << "\n";
	
	vector<int> test = howSumTabulation(7,{5,3,4,7});
	cout << "printing vector \n";
	for(auto x: test) x==-1 ? cout << "Impossible" << endl: cout << x << endl;
	
	test=howSumTabulation(7,{5,3,4,7});
	cout << "printing vector \n";
	for(auto x: test) x==-1 ? cout << "Impossible" << endl: cout << x << endl;
	
	test=howSumTabulation(7,{2,4});
	cout << "printing vector \n";
	for(auto x: test) x==-1 ? cout << "Impossible" << endl: cout << x << endl;
	
	test=howSumTabulation(8,{2,3,5});
	cout << "printing vector \n";
	for(auto x: test) x==-1 ? cout << "Impossible" << endl: cout << x << endl;
	
	return 0;
	
}
