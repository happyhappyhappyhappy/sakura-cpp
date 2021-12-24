#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define RETFLUSH cout << "\n" << flush;
// 2021/12/24 四回の内2回以上の合計を求める
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10) ;
}
double comb(int repel,int front_n){
   int result=1;
   int bunsi=1;
   int bunbo1=1;
   int bunbo2=1;
   for(int ii = 1 ; ii <= repel ; ii++){
       bunsi = bunsi * ii;
   } 
   for(int ii = 1 ; ii <= front_n ; ii++ ){
       bunbo1 = bunbo1 * ii;
   }
   for(int ii = 1 ; ii <= (repel-front_n);ii++){
       bunbo2 = bunbo2 * ii;
   }
    result = bunsi / (bunbo1*bunbo2);
   return double(result); 
}

double prob(int repel,int front_n){
    double result=1.0;
    double pattern=1.0;
    const double half=0.5;
    pattern = comb(repel,front_n);
    result = pow(half,repel)*pattern;
    return result;
}
int coin_point(int repel,int front_n){
    int result=0;
    result = front_n * 2 + (repel - front_n) * 1;
    return result;
}
int main(void){
    initial();
    const int repel=4; // コインを投げる数
    double sum_prob=0.0;
    for(int front_n=2;front_n<repel+1;front_n++){
    cout << "合計が " << coin_point(repel,front_n) << " になる確率 ";
    cout << prob(4,front_n) ;
    RETFLUSH;
    sum_prob = sum_prob + prob(4,front_n);
    }
    cout << "合計が "<< coin_point(repel,2) << " 以上になる確率 " << sum_prob;
    RETFLUSH;
    return 0;
}
