class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ret;

        for(int h=0; h<=11; h++){
            string s = to_string(h) + ':';
            int rest = turnedOn - __builtin_popcount(h);

            for(int m=0; m<=59; m++){
                if(__builtin_popcount(m) != rest) continue;

                string t = s;
                if(m < 10) t += '0';
                t += to_string(m);

                ret.push_back(t);
            }
        }

        return ret;
    }
};