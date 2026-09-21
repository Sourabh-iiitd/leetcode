class Solution {
public:
    vector<int> nums;
    int k,n;
    vector<vector<long long>> memo;

    int helper(int i, int r){
        if(i<0) return 0;
        if (memo[i][r] != -1) return memo[i][r];

        long long c=0;

        int curr=nums[i] % k;

        if(curr==r) c+=1;

        for(int prevr=0; prevr<k; prevr++ ){
            if((prevr * curr)%k==r){
                c+=helper(i-1, prevr);
            }
        }

        return memo[i][r] = c;


    }
    vector<long long> resultArray(vector<int>& nums, int k) {
        this->k=k;
        this->n= nums.size();
        this->nums=nums;
        
        memo.assign(n, vector<long long>(k, -1));
        vector<long long> result(k,0);

        for(int i=0;i<n;i++){
            for(int r=0; r<k ; r++){
                result[r]+= helper(i,r);
            }
        }
        return result;
    }
};