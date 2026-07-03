class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int max_len=0;

        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp;
            unordered_map<int,int> freq_count;

            for(int j=i;j<n;j++){
                int val=nums[j];

                if(mpp.count(val)){
                    int old_f=mpp[val];
                    freq_count[old_f]--;
                    if(freq_count[old_f]==0){
                        freq_count.erase(old_f);
                    }
                }

                mpp[val]++;
                int new_f=mpp[val];
                freq_count[new_f]++;

                if(mpp.size()==1){
                    max_len=max(max_len,j-i+1);
                }
                else if(freq_count.size()==2){
                    auto it=freq_count.begin();
                    int f1=it->first;
                    int f2=(++it)->first;

                    int min_f=min(f1,f2);
                    int max_f=max(f1,f2);

                    if(max_f==2*min_f){
                        max_len=max(max_len,j-i+1);
                    }
                }
            }
        }
        return max_len;
    }
};