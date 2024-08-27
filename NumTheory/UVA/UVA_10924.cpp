#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 


const int N = 1040;
bool is_prime[N + 1];
void Sieve() { // O(nlog(log(n))
    fill(is_prime, is_prime + N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i*i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}
int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    Sieve();
    
    string s ; 
    while(cin >> s ){    
        int sum = 0 ;
        for(auto &c : s){
            sum += ((isupper(c))? (c - 38) : (c - 96) ) ;
        }
        cout << ((is_prime[sum])? "It is a prime word.\n" : "It is not a prime word.\n");
    }
    
    return 0 ;
}
