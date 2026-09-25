#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

vector<string> balance_brackets ;

void generate_parenthesis(string &brackets, int open , int close){
    //cout << brackets << endl ;

    if(open==0 and close==0){
        balance_brackets.push_back(brackets) ;
        return ;
    }

    if(open>0){
        brackets.push_back('(') ;
        generate_parenthesis(brackets,open-1,close) ;
        brackets.pop_back() ;
    }

    if(close>0 and close>open){
        brackets.push_back(')') ;
        generate_parenthesis(brackets,open,close-1) ;
        brackets.pop_back() ;
    }
}


int main(){

    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n ; cin >> n ; string s ;

    generate_parenthesis(s,n,n) ;

    for(auto bracket_sequence:balance_brackets) cout << bracket_sequence << endl ;

    return 0 ;
}
