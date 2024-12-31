#include<bits/stdc++.h>
using namespace std;
class A{
public:
	void print(){
		cout << "I am inside A"<<endl;
	}
};

class B : public A{
public:
	void print(){
		cout << "I am inside B" << endl;
	}

};

int main(){
	vector<A> v;
	B b;
	v.push_back(b);
	v[0].print();
}