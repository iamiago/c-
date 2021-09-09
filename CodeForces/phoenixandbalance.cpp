#include <iostream>
using namespace std;

int main (){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin >> n;
		//~ //heaviest coin in the first pile
		//~ int sum1 = (1<<N), sum2 =0;
		//~ for(int i=1; i<n/2; ++i)
		//~ {
			//~ sum1 += (1<<i);
		//~ }
		
		//~ cout <<"n: " << n << " 2^n: "<< (1<<n) << endl;
		
			int a=0, b=0, c=0,ans =0;
			a=1<<n; // a = 2^n
			b=1<<(n);// b =  2^(n-1)
			c=1<<((n/2)+1);// c = 2^((n/2) + 1)
			ans = a+c-b-2;
			cout << ans << endl;
		//~ int sum1 =2, sum2=0;
		//~ for(int i=2; i<=n; ++i){
			//~ int weight = 1<<(i);
			//~ if(min(sum1+weight-sum2,sum2+weight-sum1) ==sum1+weight-sum2){
				//~ sum1 += weight;
			//~ }else{
				//~ sum2 += weight;
			//~ }
		//~ }
		//~ cout << abs(sum1-sum2) << endl;
			
	
			
	}
	
	return 0;
}
/*

		  S[N] = 2^0 + 2^1 + 2^2 + ... + 2^N
		2*S[N] = 	   2^1 + 2^2 + 2^2 + ... + 2^(N+1)
  
   S[N]-2*S[N] = 2^0 - 2^(N+1)
     S[N](1-2) = 1 - 2^(N+1)
		  S[N] = 2^(N+1)-1
		  
		  
		  s[n] = 2^1 + 2^2 + ... + 2^n
		2*s[n] = 	 + 2^2 + ... + 2^n + 2^(n+1)
		
   s[n]-2*s[n] = 2^1 - 2^(n+1)
	 (1-2)s[n] = 2-2^(n+1)
		  s[n] = 2^(n+1) - 2
		  
		  
    s[n] - 2^n = 2^(n+1) - 2^n -2
    s[n] - 2^n = 2(2^n-2^(n-1)-1)
    
    
		s[n-1] = 2^1 + 2^2 + ... + 2^(n-1) 
	 => s[n-1] = 2^n -2
	s[n] - 2^n = 2^n -2
	
	  s[n/2-1] = 2^(n/2) - 2
	s[n/2,n-1] = 2^(n) - 2^(n/2)
	
	ans = 2^n + 2^(n/2) - 2 - (2^(n) - 2^(n/2))
	ans = 2^n +2((n/2)+1)- 2^(n-1) - 2 
	
	//general formula
	j>i
	
		s=s[j]-s[i] = (2^0 + 2^1 + ... + 2^j)-(2^0 + 2^1 + ... + 2^i)
		s=s[j]-s[i] = 2^i + 2^(i+1) + ... + 2^(j-1) + 2^j
 2*s =2*(s[j]-s[i]) = 	  + 2^(i+1) + ... + 2^(j-1) + 2^j + 2^(j+1)
			  s-2*s = 2^i - 2^(j+1)
				  s = 2^(j+1) - 2^i
 
		s[i] = 2^0 + 2^1 + ... + 2^i
		s[j] = 2^0 + 2^1 + ... + 2^j
*/
	
