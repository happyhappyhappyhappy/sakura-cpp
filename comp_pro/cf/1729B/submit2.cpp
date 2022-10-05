#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

char getc2(int p){
    char ans = p - 1 + 'a';
    return ans;
}

string solver(int leng,string prob){
    int pos=leng-1;
    string res;
    while(0 <= pos){
        char take = prob.at(pos);
        if(take != '0'){
            char disp = getc2(take-'0');
            res=res+disp ;
            pos = pos-1;
        }
        else{
            int take2 = stoi(prob.substr(pos-2,2)); 
            char disp=getc2(take2);
            res=res+disp;
            pos = pos - 3;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(void){
    initial();
    int testcase;
    cin >> testcase;
    for(int j=0;j<testcase;j++){
        int count;
        cin >> count;
        string str;
        cin >> str;
        cout << solver(count,str) << "\n" << flush;
    }
    return 0;
}
