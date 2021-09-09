#include <iostream>
#include <vector>

using namespace std;

//bestSum recursively
bool bestSum(int targetSum, vector<int> numbers, vector<int> &ans){
	vector<int> shorter;
	if(targetSum==0) return true;
	if(targetSum<0) return false;
	for(auto x:numbers){
		int remainder = targetSum -x;
		if(bestSum(remainder,numbers,ans)){
			shorter.push_back(x);
			if(ans.empty() || shorter.size() < ans.size()){
				ans=shorter;
				
			}
		}
	}		
	return false;
}

//bestSum with memoization

//bestSum with tabulation

vector<int> bestSumTabulation(int targetSum, vector<int> numbers){
	vector<vector<int>> a(targetSum+1, vector<int>(1,-1));
	a[0][0] = 0;
	for(int i=0; i<=targetSum; ++i){
		if(a[i][0] != -1){
			for(auto num : numbers){
				if(i+num <=targetSum){
					if(a[i+num][0] == -1){
						if(a[i][0] != 0){ 
							a[i+num] = a[i];
							a[i+num].push_back(num);
						}else{
							a[i+num][0] = num;
						}
					}else{
						vector<int> aux =a[i];
						aux.push_back(num);
						
						if(a[i+num].size() > aux.size()){
							a[i+num] = aux;
						}
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
	//~ }
	//~ cout << "\n";
	return a[targetSum];
}

int main (){
	vector<int> ans, ans1, ans2;
	bestSum(7,{5,3,4,7},ans);
	for(auto x:ans) cout << x << " ";
	cout << "\n";
	
	bestSum(8,{2,3,5},ans1);
	for(auto x:ans1) cout << x << " ";
	cout << "\n";
	
	bestSum(8,{1,4,5},ans2);
	if(ans2.empty()) cout << "null\n";
	else for(auto x:ans2) cout << x << " ";
	cout << "\n";
	
	cout << "\n TEST \n";
	vector<int> test = bestSumTabulation(7,{5,3,4,7});
	cout << "printing vector Target : 7, best sum :\n";
	for(auto x: test) x==-1 ? cout << "Impossible" << endl: cout <<  x << " ";
	cout << "\n";
	
	test = bestSumTabulation(8,{2,3,5});
	cout << "printing vector Target : 8, best sum :\n";
	for(auto x: test) x==-1 ? cout << "Impossible" << endl: cout << x << " ";
	cout << "\n";
	
	 test = bestSumTabulation(8,{1,4,5});
	cout << "printing vector Target : 8, best sum :\n";
	for(auto x: test) x==-1 ? cout << "Impossible" << endl: cout << x << " ";
	cout << "\n";
	
	return 0;
	
}
