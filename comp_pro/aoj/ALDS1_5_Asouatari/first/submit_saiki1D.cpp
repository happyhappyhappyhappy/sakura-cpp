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

bool solver(int q_sum,int pos,vector<int> &A){
// 前提チェック
    debug("余り%dの状態で%d番目の検索に入ります\n",q_sum,pos);
    // 番兵ここから
    // 条件に達した
    if(q_sum == 0){
        debug("合計が引き切れました->条件達成!!\n");
        return true;
    }
    if(q_sum < 0){
        // これ以上やっても仕方ない
        debug("合計が引き切れました\n");
        return false;
    }
    // 最後まで調べた
    if(A.size() <= pos){
        debug("最後まで検索しました\n");
        return false;
    }
    
    // 番兵ここまで
    bool selected,unselected;
    selected = solver(q_sum-A[pos],pos+1,A);
    unselected = solver(q_sum,pos+1,A);
    return selected || unselected;
}

int main(void){
    initial();
    int elem;
    cin >> elem;
    vector<int> A(elem);
    for(int j=0;j<elem;j=j+1){
        cin >> A[j];
    }
    int qs;
    cin >> qs;
    while(qs--){
        int Q;
        cin >> Q;
        debug("===%dの調査開始===\n",Q);
        if(solver(Q,0,A)){
            cout << "yes\n" << flush;
        }
        else{
            cout << "no\n" << flush;
        }
    }
    return 0;
}
