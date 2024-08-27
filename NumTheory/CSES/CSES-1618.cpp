#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 

const int MOD = 1e9 ;

ll fact(int n){
    if(n==1) return 1 ;
    else return (n*fact(n-1)) % MOD ;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int n ; cin >> n ;
    ll ans = 0 ;
    while(n>=5){
        n /=5 ;
        ans +=n ;
    }
    cout << ans ;
    
    return 0 ;
}
/*
5 ->1
6,7,8,9 ->1
10 ->2
11,12,13,14 ->2
15 ->3

25-> 6
100/5
20*5

numbers like 25, 125,... have more 5s than (n / 5). 


n/5 counts the number of multiples of 5 less than or equal to n
25 -> 5 10 15 20 25 = 5

but there is number that contributes with more than 1 5 

5,10,15,20 contributes one 5 only
25 contributes 5^2


*/