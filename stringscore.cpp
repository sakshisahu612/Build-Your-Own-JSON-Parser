#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int points = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        switch(c){

        case 'V':
            points += 5;
            break;
        
        case 'W':
            points += 2;
            break;
        case 'X':
            if(i != n-1){
                s[i+1] = '0';
            }
            break;
        case 'Y':
            if(i != n-1){
                s += s[i+1];
                s[i+1] = '0';
                n++;
            }
            break;
        case 'Z':
            if(i != n-1){
                if(s[i+1] == 'V'){
                    points = points/5;
                    s[i+1] = '0';
                }
                if(s[i+1] == 'W'){
                    points = points/2;
                    s[i+1] = '0';
                }
            }
        }
    }

    cout << points << endl;
    return 0;
}
