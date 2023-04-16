#include<iostream>
#include<stack>

int main(void){
    std::stack<int> ST;
    ST.push(1);
    ST.push(3);
    ST.push(5);
    while(ST.empty()==false){
        int nowst = ST.top();
        ST.pop();
        std::cout << nowst << "\n" << std::flush;
    }
    std::cout << "END\n" << std::flush ;
}
