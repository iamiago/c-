#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//allConstruct with memoization
// return all the ways that the 'target' can be constructed by concatenating elements of the wordBank

vector<vector<string>> allConstruct(string target,vector<string> wordBank){
	vector<vector<string>> a;
	vector<vector<string>>empty(1,vector<string>());
	if(target == "") {
		empty[0].push_back("");
		return empty;
	}
	
	for(auto word : wordBank){
		if(target.find(word)==0){
			string suffix = target.substr(word.length());
			//~ cout << suffix << endl;
			vector<vector<string>> suffixways = allConstruct(suffix,wordBank);
			//~ for(auto vec : suffixways) for(auto x : vec) cout << x << endl;
			vector<vector<string>> targetways = suffixways;
			for(int i=0; i<(int)targetways.size(); ++i){
				targetways[i].push_back(word);
			}
			a.insert(a.end(), targetways.begin(), targetways.end());
			//~ for(auto &x :a) reverse(x.begin(), x.end());
		}
	}
	//~ reverse(a.begin(), a.end());
	
	return a;
}

// allConstruct with tabulation
vector<string> allConstructTabulation(string target, vector<string> wordBank){
	// table of table 
	vector<vector<string>> a(target.length()+1, vector<string>());
	//a[0] represents a empty string " " with can always be obtained from the wordBank
	a[0].push_back(" ");
	//we iterate over all the places of the array
	for(int i=0; i<(int)target.length()+1; ++i){
		//if its not empty, it means the substring prefix of length i can be generated by words in wordbank
		if((int)a[i].size() > 0){
			//for each word in the word bank we check if suffix or substring of suffix can be obtained
			for(auto word : wordBank){
				//if theres a word in the wordbank wich is a prefix of the suffix
				if((int)target.substr(i).find(word) == 0){
					// we copy the words used to generate the prefix
					a[i+word.length()] = a[i];
					// we add the words used to generate the prefix of suffix
					a[i+word.length()].push_back(word);
				}
			}
		}
	}
	//~ for(int i=0; i<(int)target.length()+1; i++){
		//~ for(int j=0; j<(int)a[i].size(); ++j){
			//~ cout << "a["<<i<<"]["<<j<<"] =["<<a[i][j] << "] ";	
		//~ }
		//~ cout << "\n";
	//~ }
	//~ cout << "\n";
	//~ for(auto x  : a[target.length()-1]) cout << x << endl;
	return a[target.length()];
}

void printv(vector<vector<string>> a){
	if(a.size() >0){
		
		for(int i=0; i<(int)a.size(); ++i){
			cout << "[" ;
			for(int j=0;j<(int)a[i].size(); ++j){
				if(a[i][j] != "")
				cout << a[i][j] ;
				if(j!=0 && j!=(int)a[i].size()-1) cout << ", ";
			}
			cout << "]\n";
		} 
		cout << "Numbers of way : " << a.size() << "\n";
	}else{
		cout << "\nempty array\n";
	}
	
}
int main (){
	cout << "allConstruct recursively \n";
	vector<vector<string>> a = allConstruct("test",{"te","s","t"});
	
	printv(a);
	
	a = allConstruct("purple",{"purp","p","ur","le","purpl"});
	
	printv(a); 
	
	a = allConstruct("abcdef",{"ab","abc","cd","def","ef","c","abcd"});
	
	printv(a);
	
	a = allConstruct("skateboard",{"bo","rd","ate","t","ska","sk","boar"});
	
	printv(a);
	
	a = allConstruct("aaaaaaaaaaaaaaaaaaaaaaaz",{"a","aa","aaa","aaaa","aaaaa",});
	
	printv(a);
	cout << "\nallConstruct with tabulation \n";
	vector<string> test = allConstructTabulation("test",{"te","s","t"});
	for(auto x : test) cout << x << endl;
	
	test = allConstructTabulation("purple",{"purp","p","ur","le","purpl"});
	for(auto x : test) cout << x << endl;
	return 0;
}
