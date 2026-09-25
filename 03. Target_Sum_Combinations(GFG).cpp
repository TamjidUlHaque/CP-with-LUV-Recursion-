#include<bits/stdc++.h>
using namespace std ;

class Solution {
  public:

    vector<vector<int>> valid_combinations ;

    void create_sum(vector<int> &arr , int target,int curSum , vector<int> &vec,int idx){

        if(target==curSum){
            valid_combinations.push_back(vec) ;
            return ;
        }

        if(target<curSum){
            return ;
        }

        if(idx == (int(arr.size()))) return ;

        vec.push_back(arr[idx]) ;

        create_sum(arr,target,curSum + arr[idx],vec,idx) ;

        vec.pop_back() ;

        create_sum(arr,target,curSum,vec,idx+1) ;


    }

    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {

        sort(arr.begin(),arr.end()) ;

        arr.erase(unique(arr.begin(),arr.end()),arr.end()) ;

        vector<int> vec ;

        create_sum(arr,target,0,vec,0) ;

        return valid_combinations ;

    }
};
