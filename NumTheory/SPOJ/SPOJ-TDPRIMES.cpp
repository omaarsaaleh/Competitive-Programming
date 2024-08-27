#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 


const int N = 1e8;
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
    int count = 0 ;
    for(int i=2; i<N ; i++){
        if(is_prime[i]) {
            count ++ ;
            if((count%100)==1) cout << i << '\n';
        }
    }
    
    return 0 ;
}
