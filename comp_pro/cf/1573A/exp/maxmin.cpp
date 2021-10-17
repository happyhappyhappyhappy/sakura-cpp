#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a,b;
    while(true){
        cin >> a >> b;
        if(a==-1){
            break;
        }
        cout << min(a,b) << "\n";
    }
    return 0;
}