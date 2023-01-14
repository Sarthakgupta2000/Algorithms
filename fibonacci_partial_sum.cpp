#include <iostream>
#include <vector>
using std::vector;

// long long get_fibonacci_partial_sum_naive(long long from, long long to) {
//     long long sum = 0;

//     long long current = 0;
//     long long next  = 1;

//     for (long long i = 0; i <= to; ++i) {
//         if (i >= from) {
//             sum += current;
//         }

//         long long new_current = next;
//         next = next + current;
//         current = new_current;
//     }

//     return sum % 10;
// }

int fibonacci_fast_mod(long long n, long long m) {
    if(n==0 || n==1){
        return n;
    }
    else {
        int one_behind = 1;
        int two_behind = 0;
        int iteration  = 0;
        for(int i=1; i<n; i++){
         iteration  = (one_behind + two_behind) % m;
            two_behind = one_behind;
            one_behind = iteration ; 
        }
        return iteration ;
    }

    return 0;
}

int fibonacci_sum_fast(long long n) {
    
    if(n==0) return 0;
    if(n==1) return 1;
    //sum of nth Fib series = F(n+2)-1 
    n += 2;  
    n= n % 60;    //pisano period of mod 10 is 60 seconds
    int sum  = fibonacci_fast_mod(n,10);

    return (sum - 1)%10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    
    int sum = fibonacci_sum_fast(to) - fibonacci_sum_fast(from-1);
    if(sum<0) sum += 10;
    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
