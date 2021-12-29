#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool solver(int bx,int by,int& cx,int& cy){
    if((bx+by)%2==1){
        cx = -1;
        cy = -1;
        return false;
    }
    int i_ax=0;
    int i_ay=0;
    for(int i_cx=0;i_cx<=50;i_cx++){
        for(int i_cy=0;i_cy<=50;i_cy++){
            int a2c=abs(i_cx)+abs(i_cy);
            int b2c=abs(i_cx-i_bx)+abs(i_cy-i_by);
            if(a2c == b2c){
                cx = i_cx;
            }

        }
    }
    return true;
}

int main(void){
    initial();
    int t_c;
    cin >> t_c;
    for(int ii =0;ii<t_c;ii++){
        int b_x,b_y;
        int c_x,c_y;
        solver(b_x,b_y,c_x,c_y);
        cout << c_x << " " << c_y;
    }
    return 0;
}
