class Solution {
public:
    int minSwaps(string s) {
        int cls=0;
        int max_cls=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                cls--;
            }
            else cls++;

            max_cls=max(max_cls,cls);
        }
        return (max_cls+1)/2;
    }
};