class Solution {
public:
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        for(int i=1;i<=9;i++){
            int x=i;
            int next=i+1;
            while(next<=9) {
                x=x*10+next;
                if(x>=low && x<=high) ans.push_back(x);
                next++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};