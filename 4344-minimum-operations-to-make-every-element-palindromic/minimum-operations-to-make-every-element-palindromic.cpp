class Solution {
public:
    long long minOperations(vector<int>& nums) {

           long long ans = 0;

           int n = nums.size();

           vector<long long>oddPal, evenPal;

           for(int len = 1; len <= 10; len++){

                 int halfLen = (len + 1)/2;

                 long long start = len == 1 ? 0 : pow(10, halfLen -1);
                 long long end = pow(10, halfLen) - 1;

                 for (long long x = start; x <= end; ++x) {
                       long long temp = x;
                       long long num = x;
        
                       if (len % 2 == 1) {
                           temp /= 10;
                       }
                       while (temp > 0) {
                        num = num * 10 + (temp % 10);
                        temp /= 10;
                       }

                      if (num % 2 == 0) {
                      evenPal.push_back(num);
                     } 
                      else {
                     oddPal.push_back(num);
                   }
              }
           }


           for(int i = 0; i< n; i++){

                int parity = nums[i] % 2;
                int p1 =  -1;
               
                if(parity == 1)p1 = upper_bound(oddPal.begin(),oddPal.end(), nums[i]) - oddPal.begin();
                else p1 = upper_bound(evenPal.begin(),evenPal.end(), nums[i]) - evenPal.begin();

                long long smaller = -1000000;
                long long greater = 1e9;

                int sz = parity ? oddPal.size() : evenPal.size();
               
                if(p1 < sz)greater = parity ? oddPal[p1] : evenPal[p1];

                if(p1 > 0){

                     smaller = parity ? oddPal[p1 -1] : evenPal[p1 -1];
                }

               
                ans += min((greater - nums[i])/2, (nums[i] - smaller)/2 );

                
           }

           return ans;
    }
};