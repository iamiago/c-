#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 1e5+5;

// fibo recursive O(2^n)
int fibo(int n){
	if(n<=2) return 1;
	return fibo(n-1)+fibo(n-2);
}

// 	memoization
 
vector<long long> memo(51,-1);
long long  fibomemo(int n){
	if(memo[n] == -1){
		if(n<=2) memo[n] =1;
		else memo[n] = fibomemo(n-1)+fibomemo(n-2);
		//~ n <= 1 ? memo[n] = n : memo[n]=fibomemo(n-1)+fibomemo(n-2);
	}
	return memo[n];
}


/*	n=5   (memo[5] == -1 && n>1) => memo[n] = fibomemo(4)+fibomemo(3);
	 
 *		fibomemo(4) : n=4 (memo[4] == -1 && n>1) => memo[4] = fibomemo(3)+fibomemo(2);
 *	 	fibomemo(3) : n=3 (memo[3] == -1 && n>1) => memo[3] = fibomemo(2)+fibomemo(1);
 *	 	fibomemo(2)	: n=2 (memo[2] == -1 && n>1) => memo[2] = fibomemo(1)+fibomemo(0);
 *	 	fibomemo(1) : n=1 (memo[1] == -1 && n<=1)=> memo[1] = 1;
 *	 	fibomemo(0) : n=0 (memo[0] == -1 && n<=1)=> memo[0] = 0;
 * 	 	
 */
 
 long long fiboTabulation(int n){
	 vector<long long> ans(n+1,0);
	 ans[1] = 1;
	 for(int i=1; i<=n; i++){
		 if(i+1<=n)ans[i+1] += ans[i];
		 if(i+2<=n)ans[i+2] += ans[i];
	 }
	 return ans[n];
 }
 

	
int main (){
	//~ for(int i=0; i<10; i++){
		//~ cout << fibo(i) << " ";
	//~ } cout << "\n";
	//~ cout << "Fibonnaci with memoization : \n";
	//~ for(int i=0; i<90; i++){
		//~ cout << fibomemo(i) << " ";
	//~ } cout << "\n";
	
	//~ int n=2,m=3;
	
	for(int i=0; i<90; i++)
		cout << fiboTabulation(i) << " ";
	cout << "\n";
	//~ for(int i=1; i<90; ++i)
		//~ if(fiboTabulation(i) != fibomemo(i)) cout << i << " "<< fiboTabulation(i) << " " << fibomemo(i)<<endl;
	
	
	return 0;
	
}
