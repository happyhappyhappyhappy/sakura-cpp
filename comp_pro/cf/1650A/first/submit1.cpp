#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool solver(string inputd,char target){
    bool result=false;
    cout << "INPUT STR : " << inputd << "\n" << flush;
    cout << "TARGET CHAR : " << target << "\n" << flush; 
    
    return result;
}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    for(int j=0;j<testcase;j++){
        string problem;
        char targetc;
        cin >> problem;
        cin >> targetc;
        if(solver(problem,targetc)){
            cout << "YES" << "\n" << flush;
        }
        else{
            cout << "NO" << "\n" << flush;
        }
    }
    return 0;
}
