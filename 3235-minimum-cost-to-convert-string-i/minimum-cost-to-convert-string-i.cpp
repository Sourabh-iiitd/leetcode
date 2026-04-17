class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<long long>> matrix(26, vector<long long>(26, 1e7));

        for(int i=0;i<26;i++) matrix[i][i]=0;

        int n=original.size();
        for(int i=0;i<n;i++){
            char u= original[i];
            int ui=u-'a';
            char v= changed[i];
            int vi=v-'a';
            matrix[ui][vi] = min(matrix[ui][vi], (long long)cost[i]);
        }

        

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    matrix[i][j]=min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                }
            }
        }

        long long ans=0;

        for(int i=0;i<source.size();i++){
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(matrix[u][v] == 1e7) return -1;
            ans+=matrix[u][v];
        }


        return ans;

    }
};