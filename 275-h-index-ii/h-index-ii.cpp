class Solution {
public:
    int hIndex(vector<int>& citations) {
        reverse(citations.begin(),citations.end());
        int low=0;
        int high=citations.size()-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(citations[mid]>=mid+1){
                low=mid+1;
            }
            else{
                high=mid-1;

            }
        }
        return low;
    }
};