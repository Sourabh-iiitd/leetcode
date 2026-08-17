class Solution {
public:
    int charCost(char a, char b){
        int diff=abs(a-b);
        return min(diff, 26-diff);
    }
    int minOperations(string s) {
        int n=s.size();
        int ans=INT_MAX;

        for(int r=0; r<n ; r++){
            int currCost=r;
            for(int i=0;i<n/2;i++){
                char left=s[(i+r)%n];
                char right=s[(n-i-1+r)%n];

                currCost+=charCost(left,right);
            }
            ans=min(ans, currCost);

        }

        return ans;

    

    }
};