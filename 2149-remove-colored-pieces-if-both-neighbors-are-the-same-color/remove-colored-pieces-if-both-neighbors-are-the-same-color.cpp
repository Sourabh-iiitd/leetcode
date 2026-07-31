class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        if(n<3) return false;
        int a=0;
        for(int i=2;i<n;i++){
            if(colors[i-2]+colors[i-1]+colors[i]=='A'*3) a++;
            else if(colors[i-2]+colors[i-1]+colors[i]=='B'*3) a--;
        }
        
        return a>0;

    }
};