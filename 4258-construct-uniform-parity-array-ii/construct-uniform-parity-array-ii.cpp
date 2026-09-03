class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0;
        int ev=0;
        for(int x: nums1){
            if(x%2==0) ev++;
            else odd++;
        }
        if(ev==0) return true;

        if (odd==0)return true;

        return *min_element(nums1.begin(), nums1.end())%2!=0;
    }
};