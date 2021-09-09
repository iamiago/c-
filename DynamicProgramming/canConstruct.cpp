#include <iostream>
#include <vector>
#include <string>
using namespace std;



// Is it possible to construct the target string with the words given in wordBank?
bool canConstruct(string target, vector<string> wordBank){
	//if target is empty then we can construct
	if (target == "") return true;
	// for each word in the wordBank
	for(auto word : wordBank){
		// if word is a prefix of target
		if(target.rfind(word,0) == 0){
			//we get the suffix which is the target without the prefix
			string suffix = target.substr(word.length());
			//we check recursively if we can construct this suffix
			if(canConstruct(suffix, wordBank)){
				//if we can construct it return true
				return true;
			}
		}
	}
	//if we get here, it means we cannot construct the target from words in wordBank
	return false;
}


// canConstruct with memoization


//canconstruct with tabulation
bool canConstructTabulation(string target, vector<string> wordBank){
	// a table filled with false values (a[0] = empty string, a[1] =target[0]
	vector<bool> a(target.length()+1, false);
	//the first index represent a empty string so its true, we can obtain itfrom the wordbank
	a[0] = true;
	//we iterate over the table values to check if we can obtain the subtring of length i from the word bank
	for(int i =0; i<=(int)target.length(); ++i){
		//if we can obtain a prefix subtring of length i from target string
		//this means target[i-1] is reachable
		//target = "abcdef"  a[2] = true => "ab" is in the wordbank
		if(a[i] == true){
			// we check if we can obtain a substring of the suffix from words in the wordbank
			for(auto word : wordBank){
				//if we can find a substring from target that starts in the i-th index(begining of suffix)
				//target = "abcdef"  a[2] = true => "ab" is in the wordbank
				//now we check if a word in the wordbank is in the string "abcdef" from position 2
				//which means if theres a word in the wordbank that is substring of "cdef"
				if((int)target.find(word) == i){
					// then we can obtain the subtring from suffix (subtring of target going from i to target.length)
					// if "cd" is in the word bank then a[2+2]=a[4]=true
					//which means "abcd" can be obtained from the words in wordbank
					a[i+word.length()] = true;
				}
			}
		}
	}
	
	//~ for(int i=0; i<(int)target.length()+1; ++i){
		//~ cout << "i : " << i << " target[i]: " << target[i] << " a[i]: " << a[i] <<"\n";
	//~ }
	//~ cout << a[target.length()];
	return a[target.length()];
	
}
int main (){
	//~ string word="pot";
	//~ string target ="potato";
	//~ cout << target.rfind(word,0)<< endl;
	//~ cout << target.substr(word.length())<< endl;
	
	canConstruct("abcdef",{"ab","abc","cd","def","abcd"}) ? cout << "True" << endl: cout << "False" << endl;
	canConstruct("skateboard",{"bo","rd","ate","t","ska","sk","boar"}) ? cout << "True" << endl: cout << "False" << endl;
	canConstruct("potato",{"t","a","o"}) ? cout << "True" << endl: cout << "False" << endl;
	
	cout << "\ncanConstruct with tabulation \n";
	canConstructTabulation("abcdef",{"ab","abc","cd","def","abcd"}) ? cout << "True" << endl: cout << "False" << endl;
	canConstructTabulation("skateboard",{"bo","rd","ate","t","ska","sk","boar"}) ? cout << "True" << endl: cout << "False" << endl;
	canConstructTabulation("potato",{"t","a","o"}) ? cout << "True" << endl: cout << "False" << endl;
	
	return 0;
	
}
