class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=0;
        int maxi2=0;
        for (int num : nums) {
            if (num > maxi) {
                maxi2=maxi;
                maxi=num;
            } else {
                maxi2=max(maxi2, num);
            }
        }
        
        return (maxi-1)*(maxi2-1);
    }
};