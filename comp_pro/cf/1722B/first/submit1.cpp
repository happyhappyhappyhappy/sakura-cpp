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

string solver(string &first,string &second){
    


}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    while(--testcase){
        int str_len;
        cin >> str_len;
        string prob_str1;
        string prob_str2;
        cin >> prob_str1;
        cin >> prob_str2;
        string answer;
        answer = solver(prob_str1,prob_str2);
        cout << answer << "\n" << flush;
    }
    return 0;
}
