class DSU{
    vector<int> parent, size;
public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for (int i=0; i<n; i++){
            parent[i]=i;
            size[i]=i;
        }
    }

    int find(int node){
        if (node!= parent[node]){
            return find(parent[node]);
        }
        return parent[node];
    }

    bool unionBySize(int u, int v){
        int pu= find(u);
        int pv= find(v);

        if (pu==pv) return false;

        if (size[pu]>=size[pv]){
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
        else{
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows= grid.size();
        int cols=grid[0].size();
        DSU dsu(rows*cols);

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        int islands=0;

        auto index=[&](int r, int c){ return r*cols + c;};

        for(int r=0; r<rows; r++){
            for (int c=0; c<cols; c++){
                if (grid[r][c]=='1'){
                    islands++;
                    for (int i=0; i<4; i++){
                        int nr= r+dr[i];
                        int nc= c+dc[i];
                        if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == '1'){
                            if (dsu.unionBySize(index(r,c), index(nr,nc))){
                                islands--;
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};
