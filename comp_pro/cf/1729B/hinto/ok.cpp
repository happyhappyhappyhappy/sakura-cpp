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

char myGet(int x){
    char input_X='a'+x-1;
    return 'a'+ x - 1;
}

string solver(int &lng,string &str){
    string answer;
    int pos=lng-1;
    while(0 <= pos){
        if(str[pos]!='0'){
            answer=answer+myGet(str[pos]-'0');
            pos=pos-1;
        }
        else{
            answer=answer+myGet(stoi(str.substr(pos-2,2)));
            pos = pos - 3;
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    while(testcase--){
        int strlng;
        cin >> strlng;
        string numStr;
        cin >> numStr;
        cout << solver(strlng,numStr) << "\n" << flush;
    }
    return 0;
}
