#include<bits/stdc++.h>
// #include<iostream>
// #include<stdio.h>
using namespace std;

int main(void){
    int N = 5;
    int K = 3;
    char buffer[1<<15];
    int i = snprintf(buffer,sizeof(buffer),"%d %d",N,K);
    printf("%s\n",buffer);
    cout << "result i\t" << i << "\n";
}