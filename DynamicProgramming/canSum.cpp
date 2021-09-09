#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void sleep(float seconds){
	clock_t startClock = clock();
	float secondsAhead = seconds*CLOCKS_PER_SEC;
	while(clock() < startClock+secondsAhead);
	return;
}

// is the targetSum achivable only by adding numbers from an array [...]? recursively
bool canSum(int targetSum, vector<int> numbers){
	if(targetSum==0) return true;
	if(targetSum<0) return false;
	for(int i=0; i<(int)numbers.size(); i++){
		int remainder = targetSum - numbers[i];
		if(canSum(remainder,numbers)) return true;
	}
	return false;
		
}

// canSum with memoization
vector<int> memoi(8,-1);
bool canSumMemo(int targetSum, vector<int> numbers){
	//~ cout << targetSum << endl;
	//~ if(targetSum>=0 && memoi[targetSum] == true)return true;
	//~ if(targetSum>=0 ) cout << "targetsum :" << targetSum << " memoi[targetSum]: " << memoi[targetSum] << endl;
	//~ if(targetSum <0) cout << targetSum << endl;
	//~ sleep(0.1);
	if(memoi[targetSum] != -1 && targetSum >=0) return memoi[targetSum];
	if (targetSum == 0) return true;
	if (targetSum < 0 ) return false;
	for(int i=0; i<(int)numbers.size(); i++){
		int remainder = targetSum-numbers[i];
		
		if(canSumMemo(remainder,numbers)) {
			memoi[targetSum] = 1;	
			return true;
		}
	}
	
	memoi[targetSum]=0;
	return false;
		
}
vector<bool> memo(100005,false);
bool canSumMemoization(int targetSum, vector<int> numbers){
	
	if (targetSum == 0){memo[targetSum] = true; }
	if (targetSum < 0 ) { return false;}
	for(int i=0; i<(int)numbers.size(); i++){
		int remainder = targetSum-numbers[i];
		if(canSumMemoization(remainder,numbers)) {
			memo[targetSum] = true;	
			return true;
		}if(memo[targetSum]== true) return true;
	}
	
	memo[targetSum]=false;
	
	return false;
		
}

// canSum tabulation
bool canSumTabulation(int targetSum, vector<int> numbers){
	vector<bool> a(targetSum+1,false);
	// to generate 0 we need no elements from the numbers
	a[0] = true;
	for(int i=0; i<=targetSum;  ++i){
		// if a position i is reacheable then for num in numbers position i+num is also reacheable
		if(a[i] == true){
			for(auto x: numbers)
				a[i+x] = true;
			
		}
		
	}
	//~ for(auto x : a) cout << x << endl;
	return a[targetSum];
	
}

int main (){
	
	
	int targetSum = 7;
	vector<int> a(2,0);
	a[0]=2;a[1] =3;
	cout << "canSum recursively" << endl;
	canSum(targetSum, a) ? cout << "True" << endl: cout << "False" << endl;
	canSum(7,{5,3,4,7}) ? cout << "True" << endl: cout << "False" << endl;
	canSum(7,{2,4}) ? cout << "True" << endl: cout << "False" << endl;
	canSum(8,{2,3,5}) ? cout << "True" << endl: cout << "False" << endl;
	canSum(250,{7,14}) ? cout << "True" << endl: cout << "False" << endl;
	
	//~ cout << "\ncanSum with memoization \n";
	//~ canSumMemo(targetSum, a) ? cout << "True" << endl: cout << "False" << endl;
	//~ canSumMemo(7,{5,3,4,7}) ? cout << "True" << endl: cout << "False" << endl;
	//~ canSumMemo(7,{2,4}) ? cout << "True" << endl: cout << "False" << endl;
	//~ canSumMemo(8,{2,3,5}) ? cout << "True" << endl: cout << "False" << endl;
	//~ canSumMemo(300,{7,14}) ? cout << "True" << endl: cout << "False" << endl;
	
	//~ cout << "\ncanSum with memoization made by me \n";
	//~ canSumMemoization(targetSum, a) ? cout << "True" << endl: cout << "False" << endl;
	//~ canSumMemoization(7,{5,3,4,7}) ? cout << "True" << endl: cout << "False" << endl;
	//~ canSumMemoization(7,{2,4}) ? cout << "True" << endl: cout << "False" << endl;
	//~ canSumMemoization(8,{2,3,5}) ? cout << "True" << endl: cout << "False" << endl;
	//~ canSumMemoization(300,{7,14}) ? cout << "True" << endl: cout << "False" << endl;
	
	cout << "\ncanSum with tabulation \n";
	canSumTabulation(targetSum, a) ? cout << "True" << endl: cout << "False" << endl;
	canSumTabulation(7,{5,3,4,7}) ? cout << "True" << endl: cout << "False" << endl;
	canSumTabulation(7,{2,4}) ? cout << "True" << endl: cout << "False" << endl;
	canSumTabulation(8,{2,3,5}) ? cout << "True" << endl: cout << "False" << endl;
	canSumTabulation(300,{7,14}) ? cout << "True" << endl: cout << "False" << endl;
	
	
	
	return 0;
	
}
