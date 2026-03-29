class Solution{
public:
    bool check(int k,const vector<int>& nums,const vector<int>& nums2){

        for(int i=0;i<nums.size();i+=k){
            int drops=0;
            int drop_idx=-1;

            for(int j=0;j<k-1;j++){
                if(nums[i+j]>nums[i+j+1]){
                    drops++;
                    drop_idx=j;
                }
            }

            if(drops==0){
                for(int j=0;j<k;j++) if(nums[i+j]!=nums2[i+j]) return false;
            }

            else if(drops==1){
                if(nums[i+k-1]>nums[i]) return false;
                
                int start=drop_idx+1;
                for(int j=0;j<k;j++){
                    int rotated_idx=i+(start+j)%k;
                    if(nums[rotated_idx]!=nums2[i+j]) return false;
                }
            }
            else return false;
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums){
        int n=nums.size();
        vector<int> ks;
        for(int i=1;i<=n;i++) {
            if(n%i==0) ks.push_back(i);
        }

        vector<int> nums2=nums;
        sort(nums2.begin(),nums2.end());
        if(nums==nums2){
            int sum=0;
            for(int i=0;i<ks.size();i++) sum+=ks[i];
            return sum;
        }
        

        int sum=0;
        for(int i=1;i<ks.size();i++) {
            if(check(ks[i],nums,nums2)) sum+=ks[i];
        }
        return sum;
    }
};