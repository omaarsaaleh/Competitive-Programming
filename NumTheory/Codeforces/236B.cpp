#include<iostream>

using namespace std;
#define ll long long 

const int N = 1e6+1;
int d[N];

void countDivisors() { // n logn better
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            d[j]++;
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    countDivisors();
    int a,b,c ; cin >> a >> b >> c ;
    ll ans = 0 ;
    for(int i=1 ; i<=a ; i++){
        for(int j=1 ; j<=b ; j++){
            for(int k=1 ; k<=c ; k++){
                ans += d[i*j*k] ;
            }
        }
    }
    cout << ans ;

    
    return 0 ;
}


// 5 6 7
/*
1 1 5
1 5 1
5 1 1

2 3 4

1 1 1 u
2 2 2 u

1 1 2 a1
1 2 1 a2
2 1 1 a3

1 2 2 b1
2 1 2 b2
2 2 1 b3

1 1 3
1 1 4
1 2 3
1 2 4
1 3 1
1 3 2
1 3 3
1 3 4
2 1 3
2 1 4
2 2 3
2 2 4
2 3 1
2 3 2
2 3 3
2 3 4


*/