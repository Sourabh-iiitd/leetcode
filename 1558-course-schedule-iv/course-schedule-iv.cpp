class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<bool>> matrix(numCourses, vector<bool>(numCourses, false));

        // for(int i=0;i<n;i++){
        //     matrix[i][i]=true;
        // }
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            matrix[u][v]=true;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
                }
            }
        }

        vector<bool> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int uj=queries[i][0];
            int vj=queries[i][1];
            ans[i]=matrix[uj][vj];
        }
        return ans;

    }
};