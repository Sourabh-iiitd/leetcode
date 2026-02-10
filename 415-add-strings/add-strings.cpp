class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string a = "";

        while(i >= 0 || j >= 0 || carry) {
            
            int n1 = (i >= 0 ? num1[i] - '0' : 0);
            int n2 = (j >= 0 ? num2[j] - '0' : 0);

            int sum = n1 + n2 + carry;
            
            a += (sum % 10) + '0';
            carry = sum / 10;

            i--;
            j--;
        }

        reverse(a.begin(), a.end());
        return a;
    }
};
