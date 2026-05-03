class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n1=s.size();
        int n2=goal.size();
        if(n1!=n2) return false;
        for(int i=0;i<n1;i++){
            string str1=s.substr(0,i+1);
            string str2=s.substr(i+1);
            string join=str2+str1;
            if(join==goal){
                return true;
            }
        }
        return false;
        

       

    }
};