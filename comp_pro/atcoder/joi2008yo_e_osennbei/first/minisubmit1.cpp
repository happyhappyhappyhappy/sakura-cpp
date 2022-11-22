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

void nowFIXed(int bit,int R){
    // TODO: これを持って何が固定されるかされないかチェックする
    debug("====ここで固定される物====\n");

    for(int j=0;j<R;j=j+1){
        if((bit & (1<<j))!=0)
        {
            debug("%d行目をひっくり返し「ます」\n",j);
        }
        else{
            debug("%d行目はひっくり返し「ません」\n",j);
        }
    }
}

int main(void){
    initial();
    int R,C;
    cin >> R >> C;
    vector<vector<int>> main_net(R,vector<int>(C));
    for(int j=0;j<R;j=j+1){
        for(int k=0;k<C;k=k+1){
            cin >> main_net[j][k];
        }
    }
    for(int j=0;j<R;j=j+1){
        for(int k=0;k<C;k=k+1){
            cout << main_net[j][k] << " ";
        }
        cout << "\n" << flush;
    }
    for(int bit=0;bit<(1<<R);bit=bit+1){
        nowFIXed(bit,R);
    }
    return 0;
}

