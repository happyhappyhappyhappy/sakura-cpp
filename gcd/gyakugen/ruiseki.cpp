#include<iostream>
using namespace std;
using ll=long long;
ll MAXPOW = 20;
ll BASENUM = 3;

ll newpow(ll a,ll n){
    ll result = 1; 
    cout << "------a=" << a << "^" << n << "start!!------" << endl; 
    while(n > 0){
        if(n & 1){
            
            ll tmp = result;
            cout << n << "&1:True" << endl;
            cout << "n=" << n << endl;
            result = result * a;
            cout << result << "=" << tmp << "*" << a << endl;
        }
        else{
            cout << "n=" << n << "& result=" << result << "->noaction" << endl;  
        }
        a = a * a;
        n = n >> 1;
        cout << "NEXT n=" << n << ":a=" << a << endl;
    }
    return result;
}

int main(int argc, char const *argv[])
{    
    for(ll i = 1; i <= MAXPOW; i++){
        ll result = newpow(BASENUM,i);
        cout << BASENUM << "^" << i << "=" << result << endl; 
    }               return 0;
}
