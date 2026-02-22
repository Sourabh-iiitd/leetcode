class Solution {
public:
    int scoreDifference(vector<int>& nums) {

        int total1 = 0;
        int total2 = 0;
        bool act1 = true;
        bool act2 = false;
        int c = 0;

        for(int i = 0; i < nums.size(); i++){
            int score = nums[i];

          
            if(score % 2 != 0){
                bool temp = act1;
                act1 = act2;
                act2 = temp;
            }

            c++;

          
            if(c == 6){
                bool temp = act1;
                act1 = act2;
                act2 = temp;
                c = 0;
            }

            if(act1) total1 += score;
            else total2 += score;
        }

        return total1 - total2;
    }
};