class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int countVowelSubstrings(string word) {
        int n=word.size();
        int ans=0;
       
        for(int i=0;i<n;i++){
            bool a=false;
            bool e=false;
            bool ii=false;
            bool o=false;
            bool u=false;

            for(int j=i;j<n;j++){
                if (!isVowel(word[j])) {
                    break;
                } 
                if(word[j]=='a') a=true;
                else if(word[j]=='e') e=true;
                else if(word[j]=='i') ii=true;
                else if(word[j]=='o') o=true;
                else if(word[j]=='u') u=true;
              
                if(a && e && ii && o && u) ans++;
            }
            
        }
        return ans;
    }
};