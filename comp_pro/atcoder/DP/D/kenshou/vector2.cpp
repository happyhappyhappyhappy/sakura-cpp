#include<iostream>
#include<array>
#include<vector>
#include<cstdio>
#include<chrono>
using namespace std;
using namespace std::chrono;
using li = long int;

int main(void){
    system_clock::time_point start,end;
    double elaspd;
    const li MAX=100000;
    vector<li> b2;
    cout << "Vector:push backの違い\n";
    start = chrono::system_clock::now();
    for(li j=0;j<MAX;j++){
        b2.push_back(j);
    } 
    li sum = 0;
    for(li j=0;j<MAX;j=j+1){
        sum = sum + b2[j];
    }
    end = system_clock::now();
    elaspd = chrono::duration_cast<microseconds>(end-start).count();
    cout << elaspd << " μs\n";
    return 0;
}