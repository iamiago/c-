#include <iostream>
#include <vector>
using namespace std;

// grid travaller recursive O(2^(row+col)
long long gridTraveler(int row, int col){
	
	if(row<=0 || col<=0) return 0;
	if(row==1 && col==1) return 1;
	return gridTraveler(row-1,col)+gridTraveler(row,col-1);
	
}

// grid traveller with memoization O(row*col)
vector<vector<long long>> memoi(20, vector<long long> (20,-1));
long long gridTravelerMemo(int row, int col){
	if(memoi[row][col] == -1){
		if(row <=0 || col <= 0) memoi[row][col] = 0;
		else if(row==1 && col==1) memoi[row][col] =1;
		else memoi[row][col] = gridTravelerMemo(row-1,col)+gridTravelerMemo(row,col-1);
	}
	return memoi[row][col];
}

//grid traveller with tabulation

long long gridTravelerTabulation(int row, int col){
	vector<vector<long long>> a(row+1, vector<long long>(col+1,0));
	a[1][1] = 1;
	for(int i=0; i<=row; ++i){
		for(int j=0; j<=col ; ++j){
			if(i+1 <= row) a[i+1][j] += a[i][j];
			if(j+1 <= col) a[i][j+1] += a[i][j];
		}
	}
	//~ for(int i=0; i<=row; ++i){
		//~ for(int j=0; j<=col ; ++j)
			//~ cout << a[i][j]<< " ";
		//~ cout << "\n";
	//~ }
	//~ cout << "\n";
	return a[row][col];
	
}
int main (){
	
	//~ cout << gridTraveler(2,3) << "\n";
	//~ cout << gridTraveler(3,2) << "\n";
	//~ cout << gridTraveler(3,3) << "\n";
	//~ cout << gridTraveler(18,18) << "\n";
	
	//~ int n=5,m=5;
	//~ for(int i=1; i<=n; ++i)
		//~ for(int j=1; j<=m; ++j)
			//~ cout << gridTraveler(i,j) << " ";
	//~ cout << "\n";
	
	cout << gridTravelerMemo(2,3) << "\n";
	cout << gridTravelerMemo(3,2) << "\n";
	cout << gridTravelerMemo(3,3) << "\n";
	cout << gridTravelerMemo(18,18) << "\n";
	
	cout << gridTravelerTabulation(18,18) << "\n";

	return 0;
	
	
}
