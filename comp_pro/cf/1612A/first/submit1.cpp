#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(int bx,int by,int& cx,int& cy){
    int result=0;
    int answer=0;
    if((bx+by)%2==1){
        cx = -1;
        cy = -1;
        result = -1;
        return result;
    }
    int i_ax=0;
    int i_ay=0;
    for(int i_cx=0;i_cx<=50;i_cx++){
        for(int i_cy=0;i_cy<=50;i_cy++){
            int a2c=abs(i_cx)+abs(i_cy);
            int b2c=abs(i_cx-bx)+abs(i_cy-by);
            if(a2c == b2c){
                if(((i_cx+i_cy)*2)==(bx+by)){
                    cx = i_cx;
                    cy = i_cy;
                    answer = a2c;
                }
            }
        }
    }
    return answer;
}

int main(void){
    initial();
    int t_c;
    cin >> t_c;
    // t_c = 1;
    for(int ii =0;ii<t_c;ii++){
        int b_x,b_y;
        int c_x,c_y;
        int answer=0;
        cin >> b_x >> b_y;
        answer = solver(b_x,b_y,c_x,c_y);
        if(answer==-1){
            cout << "-1 -1" << "\n" << flush;
            continue;
        }
        cout << c_x << " " << c_y << "\n" << flush;
    }
    return 0;
}
