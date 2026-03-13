class Solution {
public:
    using ll = long long;

    bool check(long long mid,int mountainHeight, vector<int>& workerTimes ){
        ll total=0;
        for(int &t:workerTimes){
            total+=(ll)(sqrt(2.0 * mid/t +0.25)-0.5);
            if(total>=mountainHeight) return true;
        }
        return total>=mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n=workerTimes.size();
        ll left=1;
        ll right=1e18;
        ll ans=0;
        while(left<=right){
            ll mid=left+(right-left)/2;
            if(check(mid,mountainHeight,workerTimes)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }

        }
        return ans;
    }
};