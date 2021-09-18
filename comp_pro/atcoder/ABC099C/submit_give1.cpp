#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

template<class XXX> inline bool changemin(XXX& x,XXX y){
    if(x > y){
        // ll BUFFERSIZE=1LL<<15;
        // char strfmt[]="DP[%lld]確定中: %lld";
        // char strbuf[BUFFERSIZE];
        // snprintf(strbuf,sizeof(strbuf),); 
        x = y;
        return true;
    }
    return false;
}

const ll INFDATA=1LL<<61;
const ll MAXBOX=101000;
vector<ll> DP(MAXBOX);

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);
    for(ll j=0;j < MAXBOX; j++){
        DP[j] = INFDATA;
    }    
    DP[0] = 0;
}
ll solver(ll x){
    ll result = x;
    for(ll j=0;j <= x ; j=j+1)
    {
        // * ONE Yen
        changemin(DP[j+1],DP[j]+1);
        // * SIX Yen
        ll sixYen = 6;
        while(true){
            changemin(DP[j+sixYen],DP[j]+1);
            sixYen = sixYen * 6;
            if(sixYen > x){
                break;
            }
        }
        // ? NINE Yen
        ll nineYen = 9; 
        while(true){
            changemin(DP[j+nineYen],DP[j]+1);
            nineYen = nineYen * 9;
            if(nineYen > x){
                break;
            }
        }
    }
    result = DP[x];
    return result;
}

int main(void){
    initial();
    ll inputdata;
    cin >> inputdata;
    cout << solver(inputdata) << "\n";
    return 0;
}