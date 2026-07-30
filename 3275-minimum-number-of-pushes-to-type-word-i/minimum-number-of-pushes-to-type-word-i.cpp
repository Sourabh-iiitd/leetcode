class Solution {
public:
    int minimumPushes(string word) {
        int c=0;
        int i=1;
        int len=1;
        while(true){
            if(len>word.length()){
                break;
            }
            
            if(len>8*i){
                i++;
            }
            c=c+i;
            len++;

        }
        return c;
    }
};