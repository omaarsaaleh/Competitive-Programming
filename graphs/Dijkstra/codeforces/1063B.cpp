#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
#include <string>
#include <map>
#include<queue>
#include<numeric>
#include <sstream>
 
 
using namespace std;
#define ll long long 
#define all(x) x.begin(), x.end()
#define for1(n) for (int i = 0; i<n; i++)
#define for2(n) for (int j = 0; j<n; j++)
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvpii vector<vector<pair<int,int>>>
#define pii pair<int,int>
#define eache auto &e

 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}

// Codeforces 1063B
// Labyrinth
// 0-1 BFS

// toReach = stCol + R - L 
// toReach - stCol = R - L
// someConstant = R - L
// R = someConstant + L
// so we need to minimize only one of them L or R

struct Cell{
    int i,j, rm, lm ;
    Cell(int i, int j, int r, int l) : i(i), j(j), rm(r), lm(l) {}
};

int r,c ; 
int stR,stC ; 
int rMvs, lMvs ;
vector<vector<bool>> grid;

vector<pii> moves ={
    {1,0}, {-1,0}, {0,1}, {0,-1}
};

bool isValidMove(int x, int y){
    return ( (x>-1 && x<r) && (y>-1 && y<c) && grid[x][y]);
}


int zero_one_bfs(){	
    int count = 1 ;
    vvi dis (r,vi(c, INT_MAX));
    deque<Cell> q;
    q.push_front(Cell(stR,stC,0,0));
    dis[stR][stC] = 0 ;
    while (!q.empty()) {
        pii pos = {q.front().i,q.front().j};
        int c_rms = q.front().rm;
        int c_lms = q.front().lm;
        q.pop_front();

        for(pii r : moves){
            int x_n = pos.first + r.first ;
            int y_n = pos.second + r.second ;
            if(!isValidMove(x_n,y_n)) continue;
            
            int rm_n = c_rms + (r.second==1),
            lm_n = c_lms + (r.second==-1);
            if(rm_n>rMvs || lm_n>lMvs) continue;

            int w = (r.second==1);

            if (dis[pos.first][pos.second] + w < dis[x_n][y_n]) {
                if(dis[x_n][y_n]==INT_MAX) count++;
                dis[x_n][y_n] = dis[pos.first][pos.second] + w;
                if (w == 1)
                    q.push_back(Cell(x_n,y_n,rm_n,lm_n));
                else
                    q.push_front(Cell(x_n,y_n,rm_n,lm_n));
            }
        }
    }
    return count;
}



int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    cin >> r >> c ;
    cin >> stR >> stC ;
    cin >> lMvs >> rMvs ;
    stR--, stC--;
    grid.resize(r,vector<bool>(c));

    for1(r){
        for2(c){
            char ch ; cin >> ch ;
            grid[i][j] = (ch=='.');
        }
    }

    cout << zero_one_bfs();

    return 0 ;
}