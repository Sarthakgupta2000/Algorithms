#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,((long long)numbers[first]) * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(std::vector<int> v){

    sort(v.begin(), v.end(),std::greater<int>());
    return ((long long)v[0])*v[1];

}

long long MaxPairwiseProductFastest(std::vector<int> v){

    int index1 = 0;
    for(int i = 1; i<v.size(); i++){
        if(v[i]>v[index1]){
            index1 = i;
        }
    }
    int index2 = 0;
    if(index1==0){
        index2 = 1;
    }
    for(int i = 1; i<v.size(); i++){
        if(v[i]>v[index2] && i!=index1){
            index2 = i;
        }
    }
    return ((long long)v[index1])*v[index2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    //std::cout << MaxPairwiseProduct(numbers) << "\n";
    //std::cout << MaxPairwiseProductFast(numbers) << "\n";
    std::cout << MaxPairwiseProductFastest(numbers) << "\n";
    return 0;
}
