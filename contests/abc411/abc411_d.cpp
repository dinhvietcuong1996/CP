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

class Node {
public:
    string S;
    Node* parent;
};

void solve(){
    ll N, Q;
    cin >> N >> Q;
    vector<Node*> list_PCs(N);
    Node* server;
    for (ll i = 0; i < Q; i++){
        ll type;
        cin >> type;
        if (type == 1){
            ll p;
            cin >> p;
            p--;
            list_PCs[p] = server;
        } else if (type == 2){
            ll p;
            cin >> p;
            p--;
            Node* new_node = new Node();
            cin >> new_node->S;
            new_node->parent = list_PCs[p];
            list_PCs[p] = new_node;
        } else {
            ll p;
            cin >> p;
            p--;
            server = list_PCs[p];
        }
    }
    
    deque<string> output;
    while (server != nullptr) {
        output.push_front(server->S);
        server = server->parent;
    }
    for (const string& s : output)
        cout << s;
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