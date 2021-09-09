#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
void max_self(T& a, T b)
{
	a=max(a,b);
}

int lis(int arr[], int n){
	int ans=0;
	int lis[n];
	lis[0] = 1;
	
	for(int i=0; i<n; ++i){
		lis[i] =1;
		for(int j=0; j<i; ++j){
			if(arr[i] > arr[j] && lis[j] + 1 > lis[i]){
				lis[i] = lis[j] + 1;
				max_self(ans,lis[i]);
			}
		}
	}
	
	int ind=0;
	int maxi=lis[0];
	
	// we get the indice of the highest number in the subsequence
	for(int i=n-1; i>=0; i--){
		if(lis[i]>maxi){
			maxi=lis[i];
			ind = i;
		}
	}
	
	vector<int> sequence;
	sequence.push_back(arr[ind]);
	
	for(int i=ind-1; i>=0; i--){
		if(lis[i] + 1 == lis[ind] && arr[i] < arr[ind])
		{
			ind = i;
			sequence.push_back(arr[ind]);
		}
	}
	reverse(sequence.begin(), sequence.end());
	cout << "The longest increasing subsequence: ";
	for(auto nb : sequence) cout << nb << " ";
	cout << endl;
	return ans;
}

int lisOpti(int arr[], int n)
{
	vector<int> sequence;
	sequence.push_back(arr[0]);
	
	for(int i=0; i<n; ++i)
	{
		if(sequence.back() < arr[i])
		{
			sequence.push_back(arr[i]);
		}
		else
		{
			// we get the index of the element that's smaller than arr[i] if it exists
			int ind = lower_bound(sequence.begin(), sequence.end(), arr[i]) - sequence.begin();
			sequence[ind] = arr[i];
			
		}
	}
	return sequence.size();
}

int main (){

	//~ int n;
	//~ scanf("%i",&n);
	//~ int arr[n];
	//~ for(int i=0; i<n; ++i){
		//~ scanf("%i",&arr[i]);
	//~ }
	
	int n=6;
	int arr[] = {50,3,10,7,40,80};
	
	int p=5;
	int arr2[] = {3,10,2,1,20};
	
	int k=9;
	int arr3[] = {2,5,3,7,11,8,10,13,6};
	//~ cout << lis(arr,n)<< endl;
	//~ cout << lis(arr2,p) << endl;
	
	cout << lisOpti(arr,n)<< endl;
	cout << lisOpti(arr2,p) << endl;
	cout << lisOpti(arr3,k) << endl;
	return 0;
}
