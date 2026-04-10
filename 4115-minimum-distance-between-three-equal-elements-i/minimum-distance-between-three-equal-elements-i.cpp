class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return -1;
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);    
        }
        int ans=INT_MAX;

        for(auto it:mpp){
            int num=it.first;
            vector<int> ind=it.second;
            if(ind.size()<3) continue;
            int a=INT_MAX;
            for(int i=0;i<ind.size();i++){
                if(i+2<ind.size()){

                int d1=abs(ind[i]-ind[i+1]);
                int d2=abs(ind[i+1]-ind[i+2]);
                int d3=abs(ind[i+2]-ind[i]);
                
                a=min(a,d1+d2+d3);
                }
                

            }
            ans=min(ans,a);

        }





        return ans==INT_MAX ? -1 : ans;
    }
};