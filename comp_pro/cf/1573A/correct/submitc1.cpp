#include<bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        int result=0;
        char a;
        cin >> n;
        for(int j=1;j<=n;j=j+1){
            cin >> a;
            result = result + (int(a)-48);
            if(int(a) > 48 && j!= n){
                result = result + 1;
            }
            else{
                if(j == n){
                    cout << "j=n:  " << j << "=" << n <<" の為、足していない" << "\n";
                    }
            }
            
        }
        cout << result << "\n";
    }




}