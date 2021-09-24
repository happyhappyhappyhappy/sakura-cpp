#include<iostream>
#include<vector>
#include<string>

using namespace std;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);    
}

int main(void){
    initial();
    int goods;
    cin >> goods;
    for(int bit=0;bit < (1<<goods);bit=bit+1){
        string str="";
        for(int goodsselect=0;goodsselect < goods;goodsselect=goodsselect+1){
            if(bit & (1 << goodsselect)){
                str = str + "○";   
            }
            else{
                str=str+"×";
            }
        }
        cout << str << "\n";
    }
}