#include<bits/stdc++.h>
using namespace std;

int dfs( int node, vector<int> &lava, unordered_map<int,list<int>> &adj, int life, vector<int> &wt, int time, vector<vector<vector<int>>> &dp ) {

    if ( dp[node][time][life] != -1 ) return dp[node][time][life];
    life += wt[node];
    if ( life == 0 || lava[node] <= time ) return 0;
    int ans = 0;
    for ( auto it : adj[node] ) {
        ans = max( ans , 1 + dfs(it, lava, adj, life, wt, time+1, dp ) );
    }
    dp[node][time][life] = ans;
    return ans;
}

void dfs1( int node, vector<int> &lava, unordered_map<int,list<int>> &adj, int time, vector<int> &vis ) {

    vis[node] = 1;
    lava[node] = time;

    for ( auto it : adj[node] ) {
        if ( !vis[it] ) {
            dfs1( it, lava, adj, time+1, vis );
        }
    }
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n, st;
        cin >> n >> st;
        st -= 1;
        vector<int> wt(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> wt[i];
        }
        unordered_map<int,list<int>> adj;
        for ( int i = 0; i < n-1; i++ ) {
            int u, v;
            cin >> u >> v;
            u-- , v--;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> lava(n);
        vector<int> vis( n, 0);
        dfs1( 0, lava, adj, 0, vis );
        int mx = *max_element( lava.begin(), lava.end() );
        vector<vector<vector<int>>> dp( n+1, vector<vector<int>>( mx+5, vector<int>( mx+5, -1) ) );

        int ans = dfs( st, lava, adj, 1, wt, 0, dp );
        cout << ans << endl;
    }
    return 0;
}
