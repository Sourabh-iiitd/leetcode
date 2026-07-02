class Solution {
public:
    int maxDistance(string moves) {
        int h=0, v=0, u=0;
        for(char c:moves){
            if(c=='R') h=h+1;
            else if(c=='L') h=h-1;
            else if(c=='U') v=v+1;
            else if(c=='D') v=v-1;
            else u++;
        }
        return abs(h)+abs(v)+u;

    }
};