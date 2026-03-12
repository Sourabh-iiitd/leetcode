class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftmax(n,0);
        vector<int> rightmax(n,0);

        int lmax=height[0];
        leftmax[0]=lmax;
        for(int i=1;i<n;i++){
           if(height[i]>lmax) lmax=height[i];
            leftmax[i]=lmax;
        }
        int rmax=height[n-1];
        rightmax[n-1]=rmax;
        for(int i=n-2;i>=0;i--){
           if(height[i]>rmax) rmax=height[i];
            rightmax[i]=rmax;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int lim=min(leftmax[i],rightmax[i]);
            ans=ans+(lim-height[i]);
        }
        return ans;
    }
};