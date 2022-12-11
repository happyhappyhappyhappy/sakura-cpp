#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool solver(int count,string S){
    if((count%3)==2){
//        debug("%d 個では 半端が出来るのが鉄板\n",count);
        return false;
    }
    int j=0;
    while(j < count){
        // debug("%c-",S.at(j));
        j=j+1;
        if(j==count){
            // debug("1番目だけで最後まで行きました\n");
            return true;
        }
        char two= S.at(j);
        // debug("%c-",two);
        j=j+1;
        // 存在しない場合はすでに前で取り除いている
        char three = S.at(j);
        // debug("%c\n",three);
        if(two != three){
            return false;
        }
        j=j+1;
    }
    return true;
}

int main(void){
    initial();
    int testcase;
    cin >> testcase;
    while(testcase--){
        int count;
        string S;
        cin >> count;
        cin >> S;
        string output;
        if(solver(count,S)){
            output="YES";
        }
        else{
            output="NO";
        }
        cout << output << "\n" << flush;
    }
    return 0;
}

