#include <iostream>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(n%2==1)
		cout << n/2 +1 << endl;
		else cout << n/2 << endl;
	}
	return 0;
}
