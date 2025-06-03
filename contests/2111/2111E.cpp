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
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    set<ll> ba, bc, ca, cb;
    for (ll i = 0; i < Q; i++){
        char x, y;
        cin >> x >> y;
        if (x == 'b' && y == 'a')
            ba.insert(i);
        else if (x == 'b' && y == 'c')
            bc.insert(i);
        else if (x == 'c' && y == 'a')
            ca.insert(i);
        else if (x == 'c' && y == 'b')
            cb.insert(i);
    }
    for (ll i = 0; i < N; i++){
        char c = S[i];
        if (c == 'b'){
            if (!ba.empty()){
                ba.erase(ba.begin());
                S[i] = 'a';
            } else {
                if (!bc.empty() && !ca.empty()){
                    ll bc_idx = *bc.begin();
                    auto it = ca.lower_bound(bc_idx);
                    if (it != ca.end()){
                        ca.erase(it);
                        bc.erase(bc.begin());
                        S[i] = 'a';
                    }
                }
            }
        } else if (c == 'c'){
            if (!ca.empty()){
                ca.erase(ca.begin());
                S[i] = 'a';
            } else if (!cb.empty()){
                ll cb_idx = *cb.begin();
                cb.erase(cb.begin());
                S[i] = 'b';
                auto it = ba.lower_bound(cb_idx);
                if (it != ba.end()){
                    ba.erase(it);
                    S[i] = 'a';
                }
            }
        }
    }
    cout << S << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--)
        solve();
}