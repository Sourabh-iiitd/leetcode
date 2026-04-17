class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> matrix(n, vector<int>(n, 1e7));

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            matrix[u][v] = weight;
            matrix[v][u] = weight;
        }
        for (int i = 0; i < n; i++)
            matrix[i][i] = 0;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] =
                        min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        vector<int> ans(n,0);
        
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(matrix[i][j]<=distanceThreshold){
                        count++;
                    }
                }
            }
            ans[i]=count;
        }
        int city = -1, mini = INT_MAX;
        for(int i = 0; i < n; i++){
            if(ans[i] <= mini){
                mini = ans[i];
                city = i;
            }
        }

        return city;
    }
};