    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <climits>
    using namespace std;

    vector<vector<pair<int, int>>> tree;
    vector<bool> visited;
    int maxLength = 0;
    int point = 0;
    void dfs(int root, int sum) {
        if (visited[root]) return;
        if (maxLength < sum) { maxLength = sum; point = root; }
        visited[root] = true;
        for (auto i : tree[root]) {
            dfs(i.first, sum + i.second);
        }
    }

    int main()
    {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int N; cin >> N;
        tree = vector<vector<pair<int, int>>>(N);
        for (int i = 1; i < N; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            tree[u - 1].push_back({ v - 1, w });
            tree[v - 1].push_back({ u - 1, w });
        }
        visited = vector<bool>(N, false);
        dfs(0, 0);
        visited = vector<bool>(N, false);
        dfs(point, 0);
        cout << maxLength;
        return 0;
    }
