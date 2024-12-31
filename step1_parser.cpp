#include<bits/stdc++.h>
using namespace std;

bool isValidJSON(const string &json){
	return json == "{}";
}

int main(){
	string input;
	cin >> input;

	if(isValidJSON(input)){
		cout << "Valid JSON" << endl;
		return 0;
	}
	else{
		cerr << "Invalid JSON" << endl;
		return 1;
	}
}