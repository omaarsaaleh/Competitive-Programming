#include<iostream>
using namespace std;

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        cout << n/2 << '\n' ;
    }
    return 0 ;
}