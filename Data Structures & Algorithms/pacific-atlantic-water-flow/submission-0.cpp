class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n= heights.size();
        int m=heights[0].size();
        vector<vector<bool>> atlvis(n, vector<bool>(m,false));
        vector<vector<bool>> pacivis(n, vector<bool>(m,false));

        queue<pair<int,int>> q;

        for (int i=0; i<n; i++){
            pacivis[i][0]=true;
            q.push({i,0});
        }
        for(int j=1; j<m; j++){
            pacivis[0][j]=true;
            q.push({0,j});
        }

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        while(!q.empty()){
            pair<int,int> node=q.front();
            q.pop();
            int r=node.first;
            int c=node.second;
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !pacivis[nr][nc] && 
                heights[nr][nc]>=heights[r][c]){
                    pacivis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }

        for (int i=0; i<n; i++){
            atlvis[i][m-1]=true;
            q.push({i,m-1});
        }
        for(int j=0; j<m-1; j++){
            atlvis[n-1][j]=true;
            q.push({n-1,j});
        }

        while(!q.empty()){
            pair<int,int> node=q.front();
            q.pop();
            int r=node.first;
            int c=node.second;
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !atlvis[nr][nc] && 
                heights[nr][nc]>=heights[r][c]){
                    atlvis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }

        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (pacivis[i][j] && atlvis[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};
