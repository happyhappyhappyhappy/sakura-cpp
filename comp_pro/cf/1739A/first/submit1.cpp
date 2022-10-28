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

void solver(int &board_row,int &board_column,
int &ans_r,int &ans_c){
    if(board_row == 1 || board_column == 1){
        ans_r=1;
        ans_c=1;
    }
    else{
        ans_r=board_row/2+1;
        ans_c=board_column/2+1;
    }
}

int main(void){
    initial();
    int testcase;
    cin >> testcase;
    while(testcase--){
        int boardrow,boardcolumn;
        cin >> boardrow >> boardcolumn;
        int ans_r,ans_c;
        solver(boardrow,boardcolumn,ans_r,ans_c);
        cout << ans_r << " " << ans_c << "\n" << flush;
    }
    return 0;
}
