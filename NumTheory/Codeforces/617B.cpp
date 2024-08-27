#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 



int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int n ; cin >> n ;
    int x ;
    bool start = 0 ;
    int count = 0 ;
    ll ans = 1 ;
    while(n--){
        cin >> x ;
        if(x & !start) start = 1;
        else if(x & start) {
            ans*= (count+1) ;
            count = 0 ;
        }
        else if(!x && start ) count++ ;
    }
    cout << ((start)? ans : 0) ;
    return 0 ;
}

/*

000001


1 0 1 0 1
10 10 1
10 1 01
1 01 01
1 010 1

2 * 2
2^ count of zeros between ones

10010 2^2=4

0 2
2 0
1 1 

0 0 1 0 0 0 1 1 0 1 8

001 0001 10 1
001 0001 1 01
001000 1 1 01
001000 1 10 1
0010 00  
 * 2
0 3 
3 0
2 1
1 2

5
5 0
4 1
3 2
2 3
1 4
0 5



2-> 3
3-> 4
4-> 5
5-> 7

*= number of zeros between ones + 1 
*/