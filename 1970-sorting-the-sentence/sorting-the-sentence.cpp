class Solution {
public:
    string sortSentence(string s) {
        
        vector<string> arr(10);
        string word = "";
    
        for(int i=0;i<=s.size();i++){
            
            if(i==s.size() || s[i]==' '){
                
              
                int pos = word.back() - '0';
                word.pop_back();
                
                arr[pos] = word;
                word = "";
            }
            else{
                word += s[i];
            }
        }
    
        string res = "";
        for(int i=1;i<=9;i++){
            if(arr[i]!=""){
                if(res!="") res += " ";
                res += arr[i];
            }
        }
        
        return res;
    }
};
