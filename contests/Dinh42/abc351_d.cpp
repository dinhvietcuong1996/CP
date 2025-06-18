#include <iostream>
#include <vector>
#include <limits>         // numeric_limits<type>::max(), numeric_limits<type>::min()
#include <string>
#include <algorithm>      // sort, max, min, reverse, swap
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>        // accumulate
#include <cmath>      // pow, floor, ceil, round, abs
#include <iomanip>    // setprecision
#include <functional> // for function
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;

const ll INF = numeric_limits<ll>::max();
const ll NEG_INF = numeric_limits<ll>::min();
ll MOD = 998244353;

void solve(){
    vector<pair<ll, ll>> direcs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    ll H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (ll i = 0; i < H; i++) cin >> grid[i];

    for (ll h = 0; h < H; h++){
        for (ll w = 0; w < W; w++){
            if (grid[h][w] != '#') continue;
            for (auto [dh, dw] : direcs){
                ll new_h = h + dh;
                ll new_w = w + dw;
                if (new_h < 0 || new_h >= H || new_w < 0 || new_w >= W) continue;
                if (grid[new_h][new_w] != '#') grid[new_h][new_w] = 'C';
            }
        }
    }

    vector<vector<ll>> visited(H, vector<ll>(W, 0));
    ll ans = 1;
    ll cur_BFS_idx = 0;
    for (ll h = 0; h < H; h++){
        for (ll w = 0; w < W; w++){
            if (grid[h][w] == 'C' || grid[h][w] == '#') continue;
            if (visited[h][w] > 0) continue;
            queue<pair<ll, ll>> q;
            q.push({h, w});
            cur_BFS_idx++;
            visited[h][w] = cur_BFS_idx;
            ll cur_cnt = 1;
            while (!q.empty()){
                auto [cur_h, cur_w] = q.front(); q.pop();
                for (auto [dh, dw] : direcs){
                    ll new_h = cur_h + dh;
                    ll new_w = cur_w + dw;
                    if (new_h < 0 || new_h >= H || new_w < 0 || new_w >= W) continue;
                    if (grid[new_h][new_w] == '#') continue;
                    if (visited[new_h][new_w] == cur_BFS_idx) continue;
                    visited[new_h][new_w] = cur_BFS_idx;
                    cur_cnt++;
                    if (grid[new_h][new_w] != 'C') q.push({new_h, new_w});
                }
            }
            ans = max(ans, cur_cnt);
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--)
        solve();
}
