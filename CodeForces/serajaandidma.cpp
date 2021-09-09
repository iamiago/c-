#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<int> cards(n);
	for(int i=0; i<n; ++i){
		scanf("%d",&cards[i]);
	}
	int sereja=0, dima=0;
	while(!cards.Empty()){
		int i=0;
		if(cards.begin() >= cards.end()){
			sereja+=cards.begin();
			erase(cards.begin(), cards.end(),cards.begin());
		}else{
			sereja+=cards.end();
			erase(cards.begin(), cards.end(),cards.end());
		}
		
	}
	//~ for(int i=0; i<n; ++i){
		
		
		//~ if(cards[i] >= cards[n-1-i]){
			//~ cout << i << " : " << cards[i] << endl;
			//~ if (i%2==0) sereja += cards[i];
			//~ else dima += cards[i];
		//~ }else{
			//~ cout << i << " : " << cards[n-1-i] << endl;
			//~ if(i%2==0) sereja += cards[n-1-i];
			//~ else dima += cards[n-1-i];
		//~ }
	//~ }
	cout << sereja << " " << dima << endl;
	
	return 0;
}

