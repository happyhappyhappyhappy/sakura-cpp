#include<iostream>
#include<algorithm>

using namespace std;

int n; // 全商品の数
int W; // バッグに入れられる最大重量
int v[100]; // 各商品の価値
int w[100]; // 各商品の重さ

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);    
}

int knap(int j,int k); // 今見ている商品,今バッグに入れられる重量

int main(){

    initial();
    cin >> n >> W;
    for(int j=0;j<n;j++)
    {
        cin >> w[j] >> v[j];
    }
    cout << knap(0,W) << "\n";
    return 0;
}

int knap(int j,int k){
//    cout << "Now Goods : " << j << "\tNow Remain : " << k << "\n";
    int answer;
    if(j == n){
        answer = 0;
    }
    else if( k < w[j]){
        answer = knap(j+1,k);
    }
    else{
        answer = max(knap(j+1,k),knap(j+1,k-w[j])+v[j]);
    }

    return answer;



}