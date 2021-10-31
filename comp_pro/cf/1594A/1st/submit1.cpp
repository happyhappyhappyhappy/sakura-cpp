#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")\n" 
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

pair<ll,ll> solver(ll problem){
    pair<ll,ll> result;
    result.second = problem;
    result.first = problem * (-1 ) + 1;
    return result;
}

int main(void){
    initial();
    int testcase;
    cin >> testcase;
    int j=testcase;
    while(j--){
        ll givenNumber;
        cin >> givenNumber;
        pair<ll,ll> answer;
        answer = solver(givenNumber);
        cout << answer.first << " " << answer.second << "\n";
    }
    return 0;
}