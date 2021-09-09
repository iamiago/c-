#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
int countConstruct(string target, vector<string> wordBank){
	//if the target is empty there's only one way
	if(target == "") return 1;
	
	int total=0;
	//for each word in the wordbank
	for(auto word : wordBank){
		//if the word a prefix of the target
		if(target.rfind(word,0) == 0){
			// we get the suffix (rest of the target string)
			string suffix = target.substr(word.length());
			int numWaysOfSuffix =countConstruct(suffix,wordBank);
			total+=numWaysOfSuffix;
			
		}
		
	}
	return total;
}

int countConstructMemo(string target, vector<string> wordBank, map<string,int> memo){
	// if target is empty theres only one way
	//~ if(memo[target] != 0)cout << "memo[target] = " << "memo["<<target<<"] = "<<memo[target]<< endl;

	//~ if(memo.count(target) > 0){
		//~ return memo[target];
	//~ }
	if(target =="") return 1;
	
	int cpt = 0;
	//for each word in the word bank
	for(auto word : wordBank){
		//if the word is a prefix of the target
		if(target.rfind(word,0) == 0){
			//we get the suffix (rest of the target string)
			string suffix = target.substr(word.length());
			int nbWays = countConstructMemo(suffix,wordBank,memo);
			cpt += nbWays;
		}
	}
	//~ memo.insert(pair<string,int>(target,cpt));
	memo[target] = cpt;
	//~ for(auto x : memo) if(x.first != "")cout << "key: "<<x.first <<"	value: "<< x.second << endl;

	//~ cout << "memo[target] = " << "memo["<<target<<"] = "<<memo[target]<< endl;
	if(memo[target]>0) return memo[target];
	return cpt;
}

int main(){
	cout << "countConstruct recursively : \n";
	cout << countConstruct("purple",{"purp","p","ur","le","purpl"}) << endl;
	cout << countConstruct("abcdef",{"ab","abc","cd","def","abcd"})  << endl;
	cout << countConstruct("skateboard",{"bo","rd","ate","t","ska","sk","boar"})  << endl;
	cout << countConstruct("enterapotentpot",{"a","p","ent","enter","ot","o","t"})  << endl;
	cout << countConstruct("potato",{"t","a","o"}) << endl;	
	cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeef",{"e","ee","eee","eeee","eeeee","eeeeee"}) << endl;

	cout << "\ncountConstruct with memoization : \n";
	map<string,int> memo;
	cout << countConstructMemo("purple",{"purp","p","ur","le","purpl"},memo) << endl;
	cout << countConstructMemo("abcdef",{"ab","abc","cd","def","abcd"},memo)  << endl;
	cout << countConstructMemo("skateboard",{"bo","rd","ate","t","ska","sk","boar"},memo)  << endl;
	cout << countConstructMemo("enterapotentpot",{"a","p","ent","enter","ot","o","t"},memo)  << endl;
	cout << countConstructMemo("potato",{"t","a","o"},memo) << endl;	
	cout << countConstructMemo("eeeeeeeeeeeeeeeeeeeeeeef",{"e","ee","eee","eeee","eeeee","eeeeee"},memo) << endl;
	return 0;
}
