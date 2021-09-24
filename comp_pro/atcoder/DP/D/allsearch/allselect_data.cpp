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
    int goods,maxlimit;
    cin >> goods >> maxlimit;
    int w[goods]={0};
    int v[goods]={0};
    for(int j=0;j<goods;j++){
        cin >> w[j] >> v[j];
    }
    for(int bit=0;bit < (1<<goods);bit=bit+1){
        int this_weight=0;
        int this_value=0;
        string str="";
        for(int goodsselect=0;goodsselect < goods;goodsselect=goodsselect+1){
            if(bit & (1 << goodsselect)){
                str = str + "○";
                this_weight = this_weight + w[goodsselect];
                this_value = this_value + v[goodsselect];   
            }
            else{
                str=str+"×";
            }
        }
        cout << str << "→"<< " w= " << this_weight << 
        " v=" << this_value ;
        if(this_weight <= maxlimit) {
            cout << " → OK";
        }
        cout << "\n";

    }
}
/*
testcaseの検証結果
1
×××→ w= 0 v=0 → OK
○××→ w= 3 v=30 → OK
×○×→ w= 4 v=50 → OK
○○×→ w= 7 v=80 → OK
××○→ w= 5 v=60 → OK
○×○→ w= 8 v=90 → OK ← Answer!!
×○○→ w= 9 v=110
○○○→ w= 12 v=140
3
××××××→ w= 0 v=0 → OK
○×××××→ w= 6 v=5 → OK
×○××××→ w= 5 v=6 → OK
○○××××→ w= 11 v=11 → OK
××○×××→ w= 6 v=4 → OK
○×○×××→ w= 12 v=9 → OK
×○○×××→ w= 11 v=10 → OK
○○○×××→ w= 17 v=15
×××○××→ w= 6 v=6 → OK
○××○××→ w= 12 v=11 → OK
×○×○××→ w= 11 v=12 → OK
○○×○××→ w= 17 v=17
××○○××→ w= 12 v=10 → OK
○×○○××→ w= 18 v=15
×○○○××→ w= 17 v=16
○○○○××→ w= 23 v=21
××××○×→ w= 3 v=5 → OK
○×××○×→ w= 9 v=10 → OK
×○××○×→ w= 8 v=11 → OK
○○××○×→ w= 14 v=16 → OK
××○×○×→ w= 9 v=9 → OK
○×○×○×→ w= 15 v=14 → OK
×○○×○×→ w= 14 v=15 → OK
○○○×○×→ w= 20 v=20
×××○○×→ w= 9 v=11 → OK
○××○○×→ w= 15 v=16 → OK
×○×○○×→ w= 14 v=17 → OK ← Answer!!
○○×○○×→ w= 20 v=22
××○○○×→ w= 15 v=15 → OK
○×○○○×→ w= 21 v=20
×○○○○×→ w= 20 v=21
○○○○○×→ w= 26 v=26
×××××○→ w= 7 v=2 → OK
○××××○→ w= 13 v=7 → OK
×○×××○→ w= 12 v=8 → OK
○○×××○→ w= 18 v=13
××○××○→ w= 13 v=6 → OK
○×○××○→ w= 19 v=11
×○○××○→ w= 18 v=12
○○○××○→ w= 24 v=17
×××○×○→ w= 13 v=8 → OK
○××○×○→ w= 19 v=13
×○×○×○→ w= 18 v=14
○○×○×○→ w= 24 v=19
××○○×○→ w= 19 v=12
○×○○×○→ w= 25 v=17
×○○○×○→ w= 24 v=18
○○○○×○→ w= 30 v=23
××××○○→ w= 10 v=7 → OK
○×××○○→ w= 16 v=12
×○××○○→ w= 15 v=13 → OK
○○××○○→ w= 21 v=18
××○×○○→ w= 16 v=11
○×○×○○→ w= 22 v=16
×○○×○○→ w= 21 v=17
○○○×○○→ w= 27 v=22
×××○○○→ w= 16 v=13
○××○○○→ w= 22 v=18
×○×○○○→ w= 21 v=19
○○×○○○→ w= 27 v=24
××○○○○→ w= 22 v=17
○×○○○○→ w= 28 v=22
×○○○○○→ w= 27 v=23
○○○○○○→ w= 33 v=28




*/