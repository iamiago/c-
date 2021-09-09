#include <iostream>
#include <vector>
using namespace std;

int main (){
	
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		for(auto &x:a) scanf("%d",&x);
		
		int indexA, indexB, A, cptA=0, cptB=0;
		A=a[0];
		for(int i=0; i<(int)a.size(); ++i){
			if(A==a[i]){
				 cptA++;
				 indexA=i+1;
			 }else{
				 
				 cptB++;
				 indexB=i+1;
			 }
		}
		if(cptA==1) printf("%d\n",indexA);
		else printf("%d\n",indexB);
		
		//~ for(auto x : a) printf("%d ",x);
		//~ printf("\n");
	}
	
	return 0;
}
