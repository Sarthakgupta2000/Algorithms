#include <iostream>

// int fibonacci_sum_squares_naive(long long n) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;
//     long long sum      = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//         sum += current * current;
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

long long get_fibonacci_huge_fast(long long n,int m){

    if(n==0) return 0;
    if(n==1) return 1;

    //period for mod 10 is 60
    int period = 60;
    n = n % period;
    int result  = fibonacci_fast_mod(n,m);
    return result ;

}

int fibonacci_sum_squares_fast(long long n) {
    if (n <= 1)
        return n;
    int sum = (get_fibonacci_huge_fast(n, 10)*get_fibonacci_huge_fast(n+1, 10)) % 10;

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    int result = fibonacci_sum_squares_fast(n);
    if(result<0) result+=10;
    std::cout << result<<std::endl; 
    return 0;
}
