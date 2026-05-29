class Solution {
public:
    int passwordStrength(string password) {

        vector<int> vis(256,0);

        int ans = 0;

        for(char ch : password){

            if(vis[ch]) continue;

            vis[ch] = 1;

            if(ch >= 'a' && ch <= 'z'){
                ans += 1;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ans += 2;
            }
            else if(ch >= '0' && ch <= '9'){
                ans += 3;
            }
            else if(ch=='!' || ch=='@' || ch=='#' || ch=='$'){
                ans += 5;
            }
        }

        return ans;
    }
};