#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 

const int N = 1000;
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
    vector<int> primeNums ;
    for(int i=2;i<1000;i++){
        if(is_prime[i]) primeNums.push_back(i);
    }
    vector<int> twoneigh ;
    for(int i=0 ; i<primeNums.size()-1; i++){
        twoneigh.push_back(primeNums[i]+primeNums[i+1]) ;
    }

    int n , k ; cin >> n >> k ;
    int count = 0 ;
    
    for(const auto &e : primeNums){
        for(auto &i : twoneigh){
            if(e-1==i){
                count++ ; break ;
            }
            if(e-1<i) break;
        }
        if(count == k){
            cout << "YES\n" ;
            return 0;
        }
        if(e>n) break;
    }
    cout << "NO\n" ;
    
    return 0 ;
}
