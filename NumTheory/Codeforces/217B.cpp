#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 

const int N = 1e5+9;
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
    vector<int> primeNums;
    for(int i=0 ; i<N+1 ; i++){
        if(is_prime[i]) primeNums.push_back(i) ;
    }

    int n,m ; cin >> n >> m ;
    vector<vector<int>> v(n, vector<int>(m));
    int min_moves = INT_MAX ;
    int temp = 0 ;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> v[i][j] ;
            v[i][j] = *lower_bound(primeNums.begin(),primeNums.end(),v[i][j]) - v[i][j] ;
            temp += v[i][j] ;
        }
        min_moves = min(temp,min_moves) ;
        temp = 0;
    }
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            temp += v[j][i] ;
        }
        min_moves = min(temp,min_moves) ;
        temp = 0;
    }
    cout << min_moves ;
    
    
    return 0 ;
}
