#include<bits/stdc++.h>

using namespace std;

// Maximum size of N, add 5 for safety
const int MAXN = 1000005;

vector<int> out[MAXN];
vector<int> answer;
int mark[MAXN];

bool dfs(int v) {
    mark[v] = 1;
    for(int next : out[v]) {
        if(mark[next] == 2)
            continue;
        if(mark[next] == 1)
            return true;
        if(dfs(next))
            return true;
    }
    answer.push_back(v);
    mark[v] = 2;
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        out[a].push_back(b);
    }
    // solution
    bool is_impossible = false;
    for(int i = 0; i < n; i++) {
        if(mark[i] == 2)
            continue;
        bool res = dfs(i);
        if(res) {
            is_impossible = true;
            break;
        }
    }
    
    if(is_impossible) {
        cout << "IMPOSSIBLE";
    } else {
        reverse(answer.begin(), answer.end());
        for(int i = 0; i < n; i++) {
            cout << answer[i] << ' ';
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