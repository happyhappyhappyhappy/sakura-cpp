#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define WIN0 cout << "maomao90\n" << flush;
#define WIN1 cout << "errorgorn\n" << flush;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(vector<long> tree_l){
    int result = -1;
    long cut_size=0;
    for(long j=0;j<tree_l.size();j++){
        cut_size = cut_size + ( tree_l[j] - 1);
    }
    result = cut_size % 2;
    return result;
}
int main(void){
    initial();
    int tt=0;
    cin >> tt;
    while(0 < tt-- ){
        long tree;
        int ansc;
        cin >> tree;
        vector<long> tree_l(tree);
        for(auto& x:tree_l){
            cin >> x;
        }
        ansc = solver(tree_l);
        if(ansc == 0){
            WIN0
        }
        else{
            if(ansc == 1){
                WIN1
            }else{
                cout << "FREE MEISON!!!!!\n" << flush;
            }
        }
    }
    return 0;
}
