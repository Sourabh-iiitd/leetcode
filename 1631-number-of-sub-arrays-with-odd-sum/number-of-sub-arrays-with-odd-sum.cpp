class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
       
        long long ods=0,ev=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0) ev++;
            else ods++;  
        }
        return (ods*ev)% 1000000007;
    }
    

};
// 0 1 4 9 ods=2 ev=2 =2*2=4

// 0 2 6 12  ev=4 od=0

//0 1 3 6 10 15 21 28 ev= 4 od=4= 4*4=16