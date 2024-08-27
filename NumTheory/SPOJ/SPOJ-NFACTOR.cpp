#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
#define ll long long 

const int N = 1e6;
int is_prime[N + 1];
int arr[11][N+1];

void solve() { 
    fill(is_prime, is_prime + N, 0);
    for (int i = 2; i <= N; i++) { 
        if (!is_prime[i]) {
            for (int j = i; j <= N; j += i){
                is_prime[j] ++;
            }
        }
    }

    for(int i=0 ; i<=10 ; i++){
        arr[i][0] = 0;
        for(int j=1 ; j<=N ; j++){
            arr[i][j] = arr[i][j-1] + (is_prime[j]==i);
        }
    }
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    solve();
    int t ; cin >> t ;
    while(t--){
        int st,end,n ; cin >> st >> end >> n;
        cout << arr[n][end] - arr[n][st-1] << '\n' ;
    }
    
    return 0 ;
}
