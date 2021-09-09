
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

template<class T>
void print(const vector<T>& v, string s = string("data")){
	
	cout << "\n" << s <<", size of vector: " << v.size() << "\n[";
	for(auto i=v.begin();  i!=v.end(); ++i)
	 {
		 // the iterator i points to one specific element in the vector
		 // if we dereference it, we get the element itself
		 cout << *i ;
		 if(i!=(v.end()-1)) cout <<", ";
	 }
	 cout << "]\n";
}

bool myGreater(double x, double y)
{
	return x>y;
}

class Join
{
	public:
	//overloading operator()
	string operator() (const string& s1, const string& s2)
	{
		return s1 + " and " + s2;
	}
};

string UpperCase(string s)
{
	for(size_t i=0; i<s.length(); ++i)
	{
		if(s[i] >='a' && s[i] <= 'z') s[i] -= 'a' - 'A';
	}
	return s;
}
void vectors()
{
	size_t n =10;
	double val = 3.14;
	vector<double> myVec(n,val);
	print(myVec);
	
	//Access elements of vector by using indexing operator []
	myVec[0] = 2.0;
	myVec[1] = 356.70;
	int last_element = myVec.size() -1;
	myVec[last_element] = 55.65;
	print(myVec, string("myVec: "));
	
	//Algorithms
	vector<double> myVec2(myVec.size());
	list<double> myList(myVec.size());
	//Copy source range of type  T1 into target range of type T2
	copy(myVec.begin(), myVec.end(), myVec2.begin());
	print(myVec2, string("myVec2: "));
	
	copy(myVec.begin(), myVec.end(), myList.begin());
	cout << "myList:\n";
	for(auto x : myList) cout << x << " ";
	cout << endl;
	
	//shift elements of vector to left, the remaining are inserted at the end
	int N=6;
	vector<double> myVec3(N);
	
	for(int i=0; i<N; ++i)
	{
		//~ cout << (double)i << endl;
		myVec3[i] = (double)i;
	}
	print(myVec3, string("myVec3: "));
	int shiftFactor = 2;
	rotate(myVec3.begin(), myVec3.begin() + shiftFactor, myVec3.end());
	print(myVec3, string("Rotated myVec3 by 2 units"));
	
	//replace() algorithm replaces each and every occurrence of the value of an element by a new value
	//~ myVec3[4] = 2;
	double oldVal = 2;
	double newVal = 999;
	replace(myVec3.begin(), myVec3.end(), oldVal, newVal);
	print(myVec3, string("Modified value of vec3"));
	
	//remove() algorithm removes all elements from a sequence that equal to a given value
	remove(myVec3.begin(), myVec3.end(), newVal);
	print(myVec3, string("Removed element 999 from vec3"));
	
	//stable_sort() algorithm sorts elements in stable order
	myVec3[myVec3.size()-1] = 9999.99;
	stable_sort(myVec3.begin(), myVec3.end());
	print(myVec3, string("Sorted vec3 with '<' ASCENDING "));
	
	//we can use a function as comparitor
	stable_sort(myVec3.begin(), myVec3.end(), myGreater);
	print(myVec3, string("Sorted vec3 with DESCENDING comparitor function"));
	
	//merge() algorihtm merges two containers
	//merging two sorted vectors
	vector<double> vec4(N,2.51);
	vector<double> vec5(myVec3.size()+vec4.size());
	merge(myVec3.begin(), myVec3.end(), vec4.begin(), vec4.end(), vec5.begin());
	print(vec5, string("Merged vector"));
	sort(vec5.begin(), vec5.end());
	print(vec5, string("Merged vector sorted"));
	
	
	//copy elements while at the same time transforming them in some way
	vector<string> first(3);
	first[0] = "Bill";
	first[1] = "Abbott";
	first[2] = "Bassie";
	
	vector<string> second(3);
	second[0] = "Ben";
	second[1] = "Costello";
	second[2] = "Addriaan";
	
	vector<string> couples(3);
	//converting first name to uppercase
	transform(first.begin(), first.end(), first.begin(), UpperCase);
	print(first, string("An upper case vector"));
	
	//now we join
	transform(first.begin(), first.end(), second.begin(), couples.begin(), Join());
	print(couples, string("Joined couples"));
	
}
template<class Tf, class Ts>
void printmap(const map<Tf,Ts>& m, string s= string("Data: ")){
	cout << s << "\n";
	cout << "Map: ";
	for(auto x: m){
		//~ cout <<"key: "<< x.first <<", value:" << x.second <<"---"<<;
		cout <<"< "<<x.first<<","<<x.second<<" >  ";
		//~ cout << "\n";
	}
	cout << "\n";
}

void print (const map<char,double>& m)
{
	cout << "Number of elements in map: " << m.size() << "\n";
	map<char,double>::const_iterator i =m.begin();
	while(i!=m.end())
	{
		cout <<"["<< i->first << "] : " << i->second << "\n";
		++i;
	}
}

void modify(map<char, double>& m, double scale)
{//multiply each value by a double
	map<char,double>::iterator i = m.begin();
	while(i != m.end())
	{
		i->second *= scale;
		++i;
	}
	
}
void maps()
{
	//collection of key-value pair
	map<char,double> map1;
	//add values using indexing
	map1['A'] = 1.0;
	printmap(map1, string("maping a key to a value"));
	//add values using 'explicit' pair object
	pair<char,double> mypair('B', 2.0);
	map1.insert(mypair);
	printmap(map1, string("inserting B-2.0"));
	//using make_pair template function
	pair<char, double> tmp = make_pair('C', 3.0);
	map1.insert(tmp);
	printmap(map1, string("inserting"));
	//using anonymous objects
	map1.insert(pair<char,double>('D',4.0));
	printmap(map1, string("inserting"));
	
	//we have a map with 4 records, if we try to add a record that alreadt exists nothing happens:
	
	pair<char,double> tmp1 = make_pair('C', 55.0);
	map1.insert(tmp1);
	printmap(map1, string("adding a record that already exists"));
	
	//we can change the value of an existing record in a map by using the assignment operator
	map1['A'] = 199.009;
	printmap(map1);
	print(map1);
	
	double scaleF = 0.5;
	modify(map1, scaleF);
	print(map1);
	
	//erase a key
	map1.erase('B');
	print(map1);
	
	//erase one iterator
	map1.erase(map1.begin());
	print(map1);
	map1.insert(pair<char,double>('A',5346.432));
	map1.insert(pair<char,double>('E',4.0));
	map1.insert(pair<char,double>('G',46.3));
	print(map1);
	
	//erase between 2 iterator
	map<char,double>::iterator i = map1.begin();
	i++;
	i++;
	
	map1.erase(i,map1.end());
	print(map1);
	
	//clearing map
	map1.clear();
	print(map1);
	
	//sparse matrix example, matrice creuse (avec bcp de 0)
	
	
}
typedef map<int,double> SparseRow;
template<int N> struct SparseMatrix
{
	map<int,SparseRow> data;
};
template<int N>
void print(SparseMatrix<N>& sm)
{
	SparseRow srr;
	SparseRow::const_iterator it;
	
	for(int row = 0; row <N; ++row)
	{
		SparseRow sr = sm.data[row];
		for(it = sm.data[row].begin(); it!= sm.data[row].end(); ++it)
		{
			cout << it->second<< ", ";
		}
		cout << "\n";
	}
}
void sparseMatrix()
{
	const int N = 5;
	SparseRow current;
	current.insert(pair<int,double> (0, -2.0));
	current.insert(pair<int,double> (1, 1.0));
	SparseMatrix<N> sparseMat;
	sparseMat.data[0] = current;
	int currentIndex= 0;
	for(int row = 1; row <N-1; ++row)
	{
		//Inserting 3 elements
		current.clear();
		current.insert(pair<int,double> (currentIndex, 1.0));
		current.insert(pair<int,double> (currentIndex+1, -2.0));
		current.insert(pair<int,double> (currentIndex+2, 1.0));
		
		sparseMat.data[row] = current;
		currentIndex++;
		
	}
	current.clear();
	current.insert(pair<int,double> (N-2, 1.0));
	current.insert(pair<int,double> (N-1, -2.0));
	sparseMat.data[N-1] = current;
	print(sparseMat);
}
template<class T>
void print(const set<T>& set, const string& name)
{
	cout << "\n" << name << ", size of set is: " << set.size() << "\n[";
	
	for(auto it=set.begin(); it!=set.end(); ++it)
	{
		cout << *it ;
		
		it++;
		if(it!=set.end()) cout << ", ";
		it--;
	}
	cout << "]\n";
}

template<class T>
void unionSet(const set<T>& s1, const set<T>& s2, set<T>& myunion)
{
	set<int>::iterator i = myunion.begin();
	insert_iterator<set<int>> insertiter(myunion,i);
	//~ print(myunion, "myunion");
	set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), insertiter);
}

template<class T> bool subset(const set<T>& super, const set<T>& sub)
{// is one set subset of another set?
	return includes(super.begin(), super.end(), sub.begin(), sub.end());
	
}
template<class T> bool superset(const set<T>& super, const set<T>& sub)
{// is one superset of another one? (super set cotains sub)
	return subset(super,sub);	
}

void sets()
{
	//only unique new values can be added to a set
	set<string> first; // default constructor
	first.insert("r");
	first.insert("T");
	first.insert("sigma");
	
	set<string> second(first); // copy constructor
	second.insert("r");			//interest rate
	second.insert("K");			//strike price
	second.insert("S"); 		//current underlying price
	second.insert("b");			//cost of carry
	
	print(second, string("Second set"));
	second.erase("K");
	print(second, "Second set");
	
	set<int> f;
	f.insert(1);
	f.insert(2);
	f.insert(3);
	print(f,"first set");
	
	set<int> s;
	s.insert(51);
	s.insert(61);
	print(s,"second set");
	
	set<int> myuni;
	unionSet(f,s,myuni);
	print(myuni,"union of set 1 and 2");
	
	set<int> t(f);
	t.insert(51);
	t.insert(61);
	
	print(t,"third set");
	if(subset(t,f)== true) cout << "\nfirst set is subset of third, OK \n";
	
	if(superset(t,f) == true) cout << "third set is superset of first, OK\n";
}


int main (){
	
	//~ vectors();
	//~ maps();
	//~ sparseMatrix();
	sets();
	
	return 0;
	
}
