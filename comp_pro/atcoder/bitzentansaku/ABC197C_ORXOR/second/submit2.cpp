#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
// const int yamaMAX_INT = 1 << 29; <- 今回はIntが使える範囲ギリギリまで増やすのでこれは無し
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

const ll yamaMAX_LL = 1LL << 60;
int N;
int yamaMAX_INT;
vector<vector<int>> XORL;
vector<int> A;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    yamaMAX_INT=(1<<30)+1;
}
int solver(void){
    int result=yamaMAX_INT;
    int fwc=N-1;
    for(int bit=0;bit<(1<<fwc);bit=bit+1){
        string fw;
        vector<vector<int>> XORTable;
        vector<int> ORList;
        ORList.push_back(A[0]);
        for(int j=0;j<fwc;j=j+1){
            int flag= (bit>>j) & 1;
            if(flag){ // 今のORListを締め切る
                XORTable.push_back(ORList);
                // 新規 ORListの作成
                ORList.clear();
                ORList.push_back(A[j+1]);
            }
            else{
                // リストに付け足すだけ
                ORList.push_back(A[j+1]);
            }
        }
        XORTable.push_back(ORList);

        // 回答を出す
        // まず各列の配列で計算する
        vector<int> XORList;
        for(int j=0;j<int(XORTable.size());j=j+1){
            vector<int> thisList=XORTable[j];
            int nowNum=thisList[0];
            for(int k=1;k<int(thisList.size());k=k+1){
                nowNum = nowNum | thisList[k];
            }
            XORList.push_back(nowNum);
        }
        int XORTRes=XORList[0];
        for(int j=1;j<(int)XORList.size();j=j+1){
            XORTRes=XORTRes ^ XORList[j];
        }
        chmin(result,XORTRes);
        XORTable.clear();
    }
    return result;
}
int main(void){
    initial();
    cin >> N;
    A.resize(N);
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    cout << solver() << "\n" << flush;
    // cout << yamaMAX_INT << "\n" << flush;
    return 0;
}
