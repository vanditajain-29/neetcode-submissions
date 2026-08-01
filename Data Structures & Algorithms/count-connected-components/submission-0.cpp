class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }

    int find(int i){
        if (parent[i]!=i){
            return find(parent[i]);
        }
        return i;
    }

    bool Union(int u, int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return false;
        if(rank[pv]>rank[pu]){
            swap(pu, pv);
        }
        parent[pv]=pu;
        rank[pu]+=rank[pv];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res=n;
        for (auto&edge: edges){
            if(dsu.Union(edge[0],edge[1])){
                res--;
            }
        }
        return res;
    }
};
