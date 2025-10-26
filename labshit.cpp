//q1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<vector<int>> &mx, int i, int n, vector<bool> &visited) {
    if (!visited[i]) {cout << i << " "; visited[i] = true;}
    for (int j=0; j<n; j++) {
        if (mx[i][j] == 1 && !visited[j]) {
            mx[i][j] = 0; mx[j][i] = 0;
            dfs(mx, j, n, visited);
        }
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> mx(n, vector<int>(n, 0));
    vector<bool> visited(n, false);    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cin >> mx[i][j];
    }

    for (int i=0; i<n; i++) {
        if (!visited[i]) dfs(mx, i, n, visited);
    }

    return 0;
}

//q2
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void bfs(vector<vector<int>> &gph, int k, vector<bool> &visited) {
    queue<int> q; q.push(k);
    visited[k] = true;

    while (!q.empty()) {
        int tp = q.front();
        q.pop();
        cout << tp << " ";

        for (int i : gph[tp]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int n, e; cin >> n >> e;
    vector<vector<int>> gph(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b;
        gph[a].push_back(b); gph[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(gph, i, visited);
        }
    }
    return 0;
}

//q5
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &inStack) {
    visited[node] = true; inStack[node] = true;
    for (int i : graph[node]) {
        if (!visited[i]) {
            if (dfs(i, graph, visited, inStack))
                return true;
        } 
        else if (inStack[i]) {
            return true;
        }
    }
    inStack[node] = false;
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n + 1); 

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<bool> visited(n + 1, false), inStack(n + 1, false);
    bool hasCycle = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, visited, inStack)) {
                hasCycle = true;
                break;
            }
        }
    }
    cout << (hasCycle ? "YES" : "NO") << "\n";
    return 0;
}

//q3
#include <bits/stdc++.h>
using namespace std;

int m, n;

void dfs(vector<vector<int>> &mx, int i, int j) {
    if (i < 0 || j < 0 || i >= m || j >= n) return;
    if (mx[i][j] == 0) return;
    mx[i][j] = 0;
    dfs(mx, i + 1, j); dfs(mx, i - 1, j); 
    dfs(mx, i, j + 1); dfs(mx, i, j - 1); 
}

int main() {
    cin >> m >> n;
    vector<vector<int>> mx(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j=0; j<n; j++) cin >> mx[i][j];
    }

    int count = 0;

    for (int i= 0; i <m; i++) {
        for (int j = 0; j < n; j++) {
            if (mx[i][j] == 1) {
                count++; dfs(mx, i, j);
            }
        }
    }
    cout << count << "\n";
    return 0;
}

//q7
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int dist, vector<vector<int>> &gph, int &maxd, int &last) {
    if (dist > maxd) {
        maxd = dist; last = node;
    }
    for (int i : gph[node]) {
        if (i != parent) {
            dfs(i, node, dist + 1, gph, maxd, last);
        }
    }
}

int main() {
    int n, m;cin >> n >> m;
    vector<vector<int>> gph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        gph[u].push_back(v); gph[v].push_back(u);
    }
    int maxd = -1, last = 1;
    dfs(1, -1, 0, gph, maxd, last);
    maxd = -1;
    dfs(last, -1, 0, gph, maxd, last);

    cout << maxd << "\n"; 
    return 0;
}
//q8
#include <bits/stdc++.h>
using namespace std;

bool dfs(int j, int dest, vector<vector<int>> &gph, vector<bool> &visited) {
    if (j == dest) return true;
    visited[j] = true;
    for (int i : gph[j]) {
        if (!visited[i]) {
            if (dfs(i, dest, gph, visited))
                return true;
        }
    }
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> gph(n);
    for (int i = 0; i < m; i++) {
        int a, b;cin >> a >> b;
        gph[a].push_back(b);
    }
    int u, v; cin >> u >> v;
    vector<bool> visited(n, false);
    bool flag = dfs(u, v, gph, visited);
    cout << (flag ? "YES" : "NO") << "\n";
    return 0;
}

//q4
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int c, vector<vector<int>> &graph, vector<int> &color) {
    color[node] = c;

    for (int nbr : graph[node]) {
        if (color[nbr] == -1) {
            if (!dfs(nbr, 1 - c, graph, color)) return false;
        } else if (color[nbr] == c) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--; 
        graph[u].push_back(v); graph[v].push_back(u);
    }

    vector<int> color(n, -1); bool flag = true;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0, graph, color)) {
                flag = false;
                break;
            }
        }
    }
    cout << (flag ? "YES" : "NO") << "\n";
    return 0;
}
//q6
