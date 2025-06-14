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
    vector<ll> list_X(Q);
    for (ll i = 0; i < Q; i++) cin >> list_X[i];
    vector<ll> list_boxes(N, 0);
    for (ll &x : list_X){
        if (x > 0){
            list_boxes[x - 1]++;
            cout << x << " ";
        } else {
            ll min_val = list_boxes[0];
            for (ll i = 1; i < N; i++)
                if (list_boxes[i] < min_val)
                    min_val = list_boxes[i];
            for (ll i = 0; i < N; i++){
                if (list_boxes[i] == min_val){
                    list_boxes[i]++;
                    cout << i + 1 << " ";
                    break;
                }
            }
        }
        // cout << "boxes: ";
        // for (ll i = 0; i < N; i++)
        //     cout << list_boxes[i] << " ";
        // cout << endl;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
//    cin >> T;
    while (T--)
        solve();
}