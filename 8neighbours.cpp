#include <iostream>
#include <vector>
using namespace std;
bool isValid(int X, int Y, int n, int m){
    return (X>=0 && X<n && Y>=0 && Y<m);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        char arr[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j];
            }
        }

        int x, y;
        cin >> x >> y;
        x--;
        y--;
        
        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        bool flag = true;

        for(int i = 0; i<=7; i++){
            int a = x + dx[i];
            int b = y + dy[i];
            if(isValid(a,b,n,m) && arr[a][b] != 'x'){
                flag = false;
                break;
            }
        }


        if(flag){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
    return 0;
}
