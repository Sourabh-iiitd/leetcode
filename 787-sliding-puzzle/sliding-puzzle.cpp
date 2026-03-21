class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target="123450";
        string curr="";
        for(int i=0;i<3;i++){
            curr+=(board[0][i] + '0');
        }
        for(int i=0;i<3;i++){
            curr+=(board[1][i] + '0');
        }
        queue<pair<string,int>> q;
        q.push({curr,0});

        vector<vector<int>> adj={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{4,2}};
        
        unordered_set<string> st;
        st.insert(curr);

        while(!q.empty()){
            string str=q.front().first;
            int steps=q.front().second;
 
            if(str==target) return steps;

            q.pop();

            int zero_idx=-1;
            for(int i=0;i<6;i++) {
                if(str[i]=='0') {
                    zero_idx=i;
                    break;
                }
            }
            string og=str;
            vector<int> add=adj[zero_idx];
            for(int i=0;i<add.size();i++){
                string temp=str;
                swap(temp[zero_idx],temp[add[i]]);
                if(!st.contains(temp)) {
                    st.insert(temp);
                    q.push({temp,steps+1});
                }       
            }

        }

        return -1;

    }
};