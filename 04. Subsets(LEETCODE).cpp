#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> power_set ;
    int n = 0 ;

    void generate_power_set(vector<int> &nums , int idx , vector<int> &subset){
        if(idx==n){
            power_set.push_back(subset) ;
            return ;
        }
        subset.push_back(nums[idx]) ;
        generate_power_set(nums,idx+1,subset) ;
        subset.pop_back() ;
        generate_power_set(nums,idx+1,subset) ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size() ; vector<int> subset ;
        generate_power_set(nums,0,subset) ;
        return power_set ;
    }
};