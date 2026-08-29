class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     while(true){
        //         int smallest=nums[i];
        //         int idx=-1;

        //         for(int j=i+1;j<n;j++){
        //             if(abs(nums[i]-nums[j])<=limit){
        //                 if(nums[j]<smallest){
        //                     smallest=nums[j];
        //                     idx=j;
        //                 }
        //             }
        //         }
        //         if(idx!=-1) swap(nums[idx], nums[i]);
        //         else break;
        //     }
        // }
        // return nums;

        vector<int> vec=nums;
        sort(vec.begin(),vec.end());

        int group=0;
        unordered_map<int,int> numTogroup;unordered_map<int,list<int>> groupTolist;

        numTogroup[vec[0]]=group;
        groupTolist[group].push_back(vec[0]);
        
        
        for(int i=1;i<n;i++){
            if(vec[i]-vec[i-1]>limit){
                group++;
            }
            numTogroup[vec[i]]=group;
            groupTolist[group].push_back(vec[i]);
        }

        vector<int> res(n);
        for(int i=0;i<n;i++){
            int num=nums[i];
            int grp=numTogroup[num];
            res[i]=groupTolist[grp].front(); 
            groupTolist[grp].pop_front();
        }

        return res;

    }
};