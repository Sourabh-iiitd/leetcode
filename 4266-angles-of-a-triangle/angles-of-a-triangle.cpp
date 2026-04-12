class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        vector<double> ans;
        if (sides[0] + sides[1] <= sides[2]) {
            return ans;
        }
        int a = sides[0], b = sides[1], c = sides[2];

        auto sq = [&](int x) -> int {
            return x * x;  
        };

    
        auto to_deg = [&](double rad) -> double {
            return (rad * 180.0) / M_PI;
        };
        
        double A = acos((sq(b) + sq(c) - sq(a)) / (2.0 * b * c));
        double B = acos((sq(a) + sq(c) - sq(b)) / (2.0 * a * c));
        double C = acos((sq(a) + sq(b) - sq(c)) / (2.0 * a * b));
        
        ans = {to_deg(A), to_deg(B), to_deg(C)};
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};