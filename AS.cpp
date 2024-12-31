#include<bits/stdc++.h>
using namespace std;
class Teacher{
private:
	int salary;

public:
	Teacher(Teacher &obj){
		this-> name = obj.name;
		this-> dept = obj.dept;
		this-> subject = obj.subject;
		this->salary = obj.salary;
	}
	string name;
	string dept;
	string subject;
// SETTER
	void setSalary(int s){
		salary = s;
	}
// GETTER
	void getSalary(){
		cout << salary << endl;
	}
};

int main(){
	Teacher t1;
	t1.name = "Sakshi";
	t1.dept = "ECE-AI";
	t1.subject = "OOPS";
	t1.setSalary(250000);
	t1.getSalary();
	cout << t1.name << " " << t1.subject << endl;
	return 0;
}