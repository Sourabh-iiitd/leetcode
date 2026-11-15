class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int> pref(n+1,0);
       
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+arr[i];
        }
        long long ods=0,ev=0;
        for(int i=0;i<=n;i++){
            if(pref[i]%2==0) ev++;
            else ods++;
        }
        return (ods*ev)% 1000000007;
    }
    

};
// 0 1 4 9 ods=2 ev=2 =2*2=4

// 0 2 6 12  ev=4 od=0

//0 1 3 6 10 15 21 28 ev= 4 od=4= 4*4=16