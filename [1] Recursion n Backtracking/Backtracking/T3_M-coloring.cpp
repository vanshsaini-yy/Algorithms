#include <bits/stdc++.h>
using namespace std;


bool is_valid_coloring(int node, int color, vector<int> &color_map, vector<vector<int>> &adj)
{
    for (auto x : adj[node])
        if (color_map[x] == color)
            return false;
    return true;
}

// Check if we can color the graph with M colors
bool solve(int node, int M, vector<int> &color_map, vector<vector<int>> &adj)
{
    if (node == adj.size())
        return true;
    for (int color = 0; color < M; color++)
    {
        if (is_valid_coloring(node, color, color_map, adj))
        {
            color_map[node] = color;
            if (solve(node + 1, M, color_map, adj))
                return true;
            color_map[node] = -1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> adj = {{1, 2, 3}, {0, 3}, {0, 3}, {1, 2, 0}};
    vector<int> color_map(adj.size(), -1);
    int M;
    cin >> M;
    if (solve(0, M, color_map, adj))
    {
        cout << "POSSIBLE\n";
        for (int i = 0; i < adj.size(); i++)
            cout << i << " : " << color_map[i] << endl;
    }
    else
        cout << "NOT POSSIBLE\n";
    return 0;
}
