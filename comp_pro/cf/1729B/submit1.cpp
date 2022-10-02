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

string solver(int &lng,string &str){
    string answer="";
    int pos=lng-1;
    COUT(lng);
    while(true){
        debug("Now pos = %d\n",pos);
        if(pos < 0){
            return answer;
        }
        if(str.at(pos)!='0'){ // 非0のケース→そのまま示す文字を出す
            int x=str.at(pos)-'0';
            cout << x << " =>" ;
            answer.push_back(x);
            pos=pos-1;
        }
        else{ // 0のケース次と次の数値からアルファベットを割り出す
            pos=pos-1;
            int oneth=str.at(pos)-'0';
            pos=pos-1;
            int tenth=str.at(pos)-'0';
            cout << tenth << oneth << " =>";
            answer.push_back(tenth*10+oneth);
        }
        cout << "\n" << flush;
    }
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
        COUT(strlng);
        COUT(numStr);
        cout << solver(strlng,numStr) << "\n" << flush;
    }
    return 0;
}
