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

// Dijkstra's Algorithm
// Args:
//   src: source vertex
//   graph: adjacency list, where graph[u] is a vector of pairs {v, weight}
// Returns:
//   A vector of shortest distances from src to all other vertices.
vector<ll> dijkstra(ll src, vector<vector<pair<ll, ll>>>& graph) {
    ll N = graph.size();
    vector<ll> dist(N, INF);
    dist[src] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src}); // {distance, vertex}

    while (!pq.empty()) {
        ll cur_dist = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (cur_dist > dist[u]) {
            continue;
        }

        for (auto& edge : graph[u]) {
            ll v = edge.first;
            ll weight = edge.second;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Floyd-Warshall Algorithm
// Args:
//   graph: adjacency list, where graph[u] is a vector of pairs {v, weight}
// Returns:
//   A 2D vector representing the shortest distances between all pairs of vertices.
vector<vector<ll>> floyd_warshall(vector<vector<pair<ll, ll>>>& graph) {
    ll N = graph.size();
    vector<vector<ll>> dist(N, vector<ll>(N, INF));

    for (ll i = 0; i < N; ++i) {
        dist[i][i] = 0;
        for (auto& edge : graph[i]) {
            ll v = edge.first;
            ll weight = edge.second;
            dist[i][v] = min(dist[i][v], weight);
        }
    }

    for (ll k = 0; k < N; ++k) {
        for (ll i = 0; i < N; ++i) {
            for (ll j = 0; j < N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--)
        solve();
}