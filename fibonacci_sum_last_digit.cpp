#include <iostream>

// int fibonacci_sum_naive(long long n) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;
//     long long sum      = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//         sum += current;
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


int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n);
    int result = fibonacci_sum_fast(n);
    if(result<0) result+=10;
    std::cout << result<<std::endl; 
}
