#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

bool is_partitionable(vector<int> &vec , int target_sum , int current_sum , int index){

    if(index==(int(vec.size()))){
        return (current_sum == 0) ;
    }

    current_sum += vec[index] ;

    if(current_sum > target_sum){
        return false ;
    }

    if(target_sum == current_sum){
        return is_partitionable(vec,target_sum,0,index+1) ;
    }

    return is_partitionable(vec,target_sum,current_sum,index+1) ;

}

void solve_it_dummy(){
    int n ; cin >> n ; vector<int> vec(n) ;

    int sum = 0 ; vector<int> divisor ;

    for(int i = 0 ; i < n ; i++){
        cin >> vec[i] ; sum += vec[i] ;
    }

    for(int i = 1 ; i*i <= sum ; i++){
        if(sum%i==0){
            divisor.push_back(sum/i) ;
            if(sum/i != i){
                divisor.push_back(i) ;
            }
        }
    }

    sort(divisor.begin(),divisor.end()) ;

    for(auto reqSum:divisor){
        int sz = sum/reqSum ; int operation = n - sz ;
        if(is_partitionable(vec,reqSum,0,0)){
            cout << operation << endl ;
            return ;
        }
    }

}

int main(){

    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int testcase ; cin >> testcase ;

    while(testcase-->0){
        solve_it_dummy() ;
    }

    return 0 ;
}
