class Solution {
public:
    int minInsertions(string s) {
        int ops=0;
        int ans=0;
    
        for(int i=0;i<s.size();i++){
            char c=s[i];

            if(c=='(') {
                ops++;
            }
            else if(c==')'){
                
                if(i+1<s.size() && s[i+1]==')')  {
                   if(ops>0) ops--;
                   else ans++;
                   i++;
                }
                else{
                    if(ops>0){
                        ops--;
                        ans++;
                    }
                    else {
                        ans+=2;
                    }
                }            
            }   
        }

        return ans+ ops*2;;
    }
};