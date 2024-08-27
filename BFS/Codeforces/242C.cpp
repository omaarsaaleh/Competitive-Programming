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
#include <fstream>

using namespace std;
#define ll long long 
#define all(x) x.begin(), x.end()
#define for1(n) for (int i = 0; i<n; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define eache auto &e

const int dx[] = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1};
const int dy[] = {-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1};



int bfs(pair<int,int> st, pair<int,int> end, map<int,int> &hashed_r, map<int,int> &hashed_c, vector< vector< pair<int,int> > > &allowed,  vector<int> &dehashed_c) {
    queue<tuple<int,int,int>> q;
    map<pair<int,int>, bool> vis;
    q.push({st.first, st.second, 0});
    vis[st] = true;

    while(!q.empty()) {
        tuple<int,int,int> v = q.front();
        q.pop();

        if(make_pair(get<0>(v), get<1>(v)) == end) 
            return get<2>(v);

        for(int i = 0; i < 8; i++) {
            int x_n = dx[i] + get<0>(v);
            int y_n = dy[i] + get<1>(v);

            if( hashed_r.count(x_n) ) {

                if(!vis[{x_n, y_n}]) {
                    for(pair<int,int> allowed_cols : allowed[hashed_r[x_n]]){
                        if(dehashed_c[allowed_cols.first] <= y_n && dehashed_c[allowed_cols.second] >= y_n) {
                            vis[{x_n, y_n}] = true;
                            q.push({x_n, y_n, get<2>(v) + 1});
                            break;   
                        }
                    }
                
                } 
            
            }
        
        }
    }

    return -1;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    pair<int,int> st;
    cin >> st.first >> st.second;
    pair<int,int> target;
    cin >> target.first >> target.second;

    int n;
    cin >> n;

    map<int,int> hashed_r;
    map<int,int> hashed_c;

    vector<int> dehashed_c(1e5+1);

    int rh = 1;
    int ch = 1;


    vector< vector< pair<int,int> > > allowed(1e5+1, vector< pair<int,int> >(1, {0,0}));

    for1(n) {
        int r, c1, c2;
        cin >> r >> c1 >> c2;

        if(hashed_r[r] == 0) {
            hashed_r[r] = rh++;
        }

        for(int col : {c1, c2}) {
            if(hashed_c[col] == 0) {
                hashed_c[col] = ch;
                dehashed_c[ch++] = col;
            }
        }

        if(allowed[hashed_r[r]][0] == make_pair(0, 0)) 
            allowed[hashed_r[r]][0] = make_pair(hashed_c[c1], hashed_c[c2]);
        else{
            allowed[hashed_r[r]].push_back(make_pair(hashed_c[c1], hashed_c[c2])) ;

        } 
    }

    cout << bfs(st, target, hashed_r, hashed_c, allowed, dehashed_c);

    return 0;
}
