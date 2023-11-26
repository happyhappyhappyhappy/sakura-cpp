#include <iostream>
#include <queue>
#include <string>
#include <utility>

int main ()
{
  std::priority_queue<std::pair<int, std::string>> que;

  que.emplace(3, "aaa");
  que.emplace(1, "bbb");
  que.emplace(4, "ccc");

  while (!que.empty()) {
    std::cout << que.top().first << ", " << que.top().second << std::endl;
    que.pop();
  }
}
