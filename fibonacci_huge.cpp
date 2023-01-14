#include <iostream>

// long long get_fibonacci_huge_naive(long long n, long long m) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }

//     return current % m;
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

long long get_pisano_period(long long n, long long m, int &flag) { 
    
    int prev = 0;
    int curr = 1;
    int iteration  = 0;
    while(true){
        int temp = curr;
        curr = (prev+curr) % m;
        prev = temp;
        iteration += 1;
        if (iteration ==n){
            flag=1;
            //returning result
            return prev;
        }
        if(prev==0 && curr==1){
            //returning period 
            return iteration ;
        } 
    }
    return -1;
}

long long get_fibonacci_huge_fast(long long n, long long m){

    if(n==0) return 0;
    if(n==1) return 1;

    int flag=0;
    int period = get_pisano_period(n,m,flag);
    //if flag has been updated, period actually contains the answer
    if(flag==1) return period; 

    n = n % period;
    int iteration  = fibonacci_fast_mod(n,m);
    return iteration ;

}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
