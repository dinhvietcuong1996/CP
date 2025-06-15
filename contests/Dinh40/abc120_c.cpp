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

ll MOD = 998244353;

void solve(){
    string S;
    cin >> S;
    ll cnt = 0;
    ll stack_0 = 0, stack_1 = 0;
    for (ll i = 0; i < S.size(); i++){
        char c = S[i];
        if (c == '0'){
            stack_1++;
            if (stack_1 == 1 && stack_0 > 0){
                stack_0--;
                stack_1--;
                cnt += 2;
            }
        } else {
            stack_0++;
            if (stack_0 == 1 && stack_1 > 0){
                stack_0--;
                stack_1--;
                cnt += 2;
            }
        }
    }
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--)
        solve();
}