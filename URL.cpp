#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.length();
    int ques = -1;
    for(int i = 0; i<n; i++){
        if(s[i] == '?'){
            ques = i;
            break;
        }
    }

    for(int i = ques+1; i<n; i++){
        if(s[i] == '='){
            cout << ": ";
            continue;
        }
        if(s[i] == '&'){
            cout << endl;
            continue;
        }
        cout << s[i];
    }
    return 0;
}