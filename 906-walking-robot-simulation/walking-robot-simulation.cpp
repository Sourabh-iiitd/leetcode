class Solution {
public:
    void move(int &x, int &y , int com, string &dir, set<vector<int>>& obstacles){
        if(com== -2) { //turn left
            if(dir=="N") dir="W";
            else if(dir=="S") dir="E";
            else if(dir=="W") dir="S";
            else if(dir=="E") dir="N";
        }
        else if(com==-1){ //turn right
            if(dir=="N") dir="E";
            else if(dir=="E") dir="S";
            else if(dir=="S") dir="W";
            else if(dir=="W") dir="N";
        }
        else{
            for(int step = 0; step < com; step++){
                int nx = x, ny = y;

                if(dir=="N") ny++;
                else if(dir=="S") ny--;
                else if(dir=="E") nx++;
                else if(dir=="W") nx--;

                if(obstacles.count({nx, ny})) break;

                x = nx;
                y = ny;
            }
        }
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0;
        int y=0;
        string dir = "N";
        int maxi=INT_MIN;
        set<vector<int>> obs(obstacles.begin(), obstacles.end());
        for(int i=0;i<commands.size();i++){
            move(x,y,commands[i],dir,obs);
            maxi = max(maxi, x*x + y*y);
        }

        return maxi;

    }
};