#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 

unsigned long long nCr(int n, int r){ //O(min(r,n-r))
    if(r>n) return 0 ;
    if (r > n-r ) r = n - r; 

    unsigned long long result = 1;
    for (int i = 0; i < r; i++) 
        result = result * (n - i)/(i + 1);
    
    return result;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int t ; cin >> t ; 
    while(t--){
        int n,k ; cin >> n >> k ;
        cout << nCr(n-1,k-1) << '\n' ;
    }
    
    return 0 ;
}

/*

n select
k availabe

n-1 C k-1

10 3
10-3*1 + 2 = 9
9c2

30 7
30-7+6 = 30-1 = 29
29C6

n-k = n-1-(k-1)

STARS AND BARS

divide 9 apples along a,b,c persons
apples = stars, persons = bars

&bars = num of persons - 1
like when you divide a bar into three parts u only need to cut it twice

11C2 = 55
problem transformed to how many ways to arrange the stars and bars

* * *  |  * *  |  * * * * an example from the possibilities 
  a        b         c   


what if each person need to receive at least one apple
take one apple out for each person
6 apples 2 bars
8C2 = 28

or

*_*_*_ *_*_*_ *_*_* there can only be one bar at each space
so that no one takes nothing so
8C2 = 28


24 apples shared among 3 each at least has 2

2+(24-3*2) = 20
20C2 = 190

10 seats, 3 persons none will sit next each other
10-3 = 7 stars
8 spaces , 3 persons 8C3

_*_*_*_*_*_*_*_ 




*/