# Intuition
There is exactly one solution to this problem as given. 

A + B = result => result - A = B

We can calculate this result and check against other numbers in the array.

Running it individually for digit would produce O(n^2) solution since we wouldn't know initially if the digit we have is one of the pair forming the result. 

# Approach
We can alleviate above problem by keeping track of the complements using a hash table. Whenever on a new digit, check if its a complement of a previos number in hashtable, otherwise create a new entry by storing the new calculated complement with the result as the key and its index as value. 
Lookup would have time complexity $$O(1)$$

# Complexity
- Time complexity: $$O(n)$$


- Space complexity: $$O(n)$$

# Code
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> solution;
        unordered_map<int, int> umap;
        for(int i=0; i<n; i++){
            if(i>0){
            // since we need a pair, no point starting check from first index
                if(umap.find(nums[i]) == umap.end()){
                    int temp2 = target-nums[i];
                    umap[temp2] = i;
                    continue;
                }
                else{
                    solution.push_back(i);
                    solution.push_back(umap[nums[i]]);
                    break;
                }
            }
            int temp2 = target-nums[i];
            umap[temp2] = i;
        }
        return solution;
    }
};
```