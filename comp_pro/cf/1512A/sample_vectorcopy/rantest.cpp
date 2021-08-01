#include <random>
// #include <fstream>
#include<iostream>
using namespace std;

int main() 
{
  random_device seed_gen;
  default_random_engine engine(seed_gen());

  // 0以上9以下の値を等確率で発生させる
  uniform_int_distribution<> dist(0, 9);

  // std::ofstream result_file("uniform_int_distribution.tsv");
  for (std::size_t n = 0; n < 1000; ++n) {
    // 一様整数分布で乱数を生成する
    int result = dist(engine);

    cout << result << "\t\n";
  }
}