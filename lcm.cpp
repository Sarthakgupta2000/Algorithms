#include <iostream>
#include<algorithm>

long long lcm_naive(int a, int b) {
  for (long long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(long a, long b){
  long big=std::max(a,b);
  long small=std::min(a,b);
  long long temp = (long long) a * b;
  for(long long l = big; l <= temp; l+=big ){
    if(l % small == 0){
      return l;
    }
  }
  return temp;
}

int main() {
  long a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
