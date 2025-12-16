#include<bits/stdc++.h>

using namespace std;

// Maximum size of N, add 5 for safety
const int MAXN = 1000005;
// Number of nodes N and number of edges M
int n, m;
// Graph
vector<int> g[MAXN];
int mark[MAXN];

bool dfs(int v) {
    mark[v] = 1;
    for(int to : g[v]) {
        if(mark[to] == 2)
            continue;
        if(mark[to] == 1)
            return true;
        bool res = dfs(to);
        if(res)
            return true;
    }
    mark[v] = 2;
    return false;
}

/**
 * Returns true, if graph has cycles and false otherwise
 */
bool has_cycles() {
    // This loop is optional, since all marks will be zero by default
    // However, if you intend to run this function several times,
    // resetting marks is necessary.
    for(int v = 0; v < n; v++) {
        mark[v] = false;
    }

    bool ans = false;
    for(int v = 0; v < n; v++) {
        if(mark[v] == 2)
            continue;
        bool res = dfs(v);
        if(res) {
            ans = true;
            break;
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }
    cout << has_cycles();
}