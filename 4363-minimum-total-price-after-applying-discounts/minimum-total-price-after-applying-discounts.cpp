class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        int n=prices.size(), m=discounts.size();

        int i=0, j=0;

        double ans=0;

        while(i<n && j<m){
            double p=prices[i];
            double d=discounts[j];
            double div= p*(100-d);
            ans+= (div/100);
            i++;
            j++;
        }

        if(i<n){
            while(i<n){
                ans+=prices[i];
                i++;
            }
        }

        return ans;
    }
};