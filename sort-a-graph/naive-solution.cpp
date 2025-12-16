#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<int> out[n]; // out[v] - vector of outgoing edges from v
    int in[n]; // in[v] - number of incoming edges into v
    bool used[n]; // used[v] - whether v already appears in ans or not
    for(int i = 0; i < n; i++) {
        out[i] = vector<int>();
        in[i] = 0;
        used[i] = false;
    }
     
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; // from a to b
        out[a].push_back(b);
        in[b]++;
    }

    vector<int> ans;
    bool is_impossible = false;
    for(int i = 0; i < n; i++) {
        int node = -1;
        for(int v = 0; v < n; v++) {
            if(!used[v] && in[v] == 0) {
                node = v;
                break;
            }
        }
        if(node == -1) {
            is_impossible = true;
            break;
        }
        ans.push_back(node);
        used[node] = true;
        for(int next : out[node]) {
            in[next]--;
        }
    }

    if(is_impossible) {
        cout << "IMPOSSIBLE";
    } else {
        for(int node : ans) {
            cout << node << ' ';
        }
    }
}

/*

4 4
0 1
1 2
0 3
3 2

Output:
0 1 3 2
0 3 1 2

3 3
0 1
1 2
2 0

Output:
IMPOSSIBLE

*/