class Solution {
public:
    string finalString(string s) {
        vector<char> arr;
        for(char x:s){
            if(x!='i'){
                arr.push_back(x);
            }
            else{
                reverse(arr.begin(),arr.end());
            }
        }
        int j=0;
        string ans="";
        for(int i=0;i<arr.size();i++){
            ans+=arr[i];
            // j++;
        }
        return ans;
    }
};