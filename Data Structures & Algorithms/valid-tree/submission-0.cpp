class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n!=edges.size()+1) return false;

        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        q.push(0);
        int nodes=0;
        vector<bool> vis(n, false);
        vis[0]=true;

        while(!q.empty()){
            int node=q.front();
            nodes++;
            q.pop();
            for (int nei: adj[node]){
                if (!vis[nei]) {
                    vis[nei] = true;
                    q.push(nei);
                }
            }
        }
        return nodes==n;
    }
};
