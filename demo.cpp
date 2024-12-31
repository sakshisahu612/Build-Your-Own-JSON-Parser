#include<bits/stdc++.h>
using namespace std;
class Queue{
public:
	int n;
	int head = 0, tail = -1;
	int arr[n];
	Queue(int size){
		n = size;
	}

	// empty, front, pop
	bool is_empty(){
		if(tail == -1){
			return true;
		}
		return false;
	}

	void push_q(int a){
		if(tail == n){
			cout << "Queue is full...cannot push the element" << endl;
		}
		else if(tail+1 < n){
			arr[tail] = a;
		}
	}
	// class B -> B b
	vector<A> v; 
	v.push_back(b);
// a -> b,c,d
};

int main(){
	int n;
	cin >> n;
	Queue obj1(n);
	obj1.is_empty();
	//int arr[n];
	int head = 0, tail = 0;
	queue<int> b;
	b.push_q(5);

}