class Solution {
public:
    bool isTrionic(vector<int>& arr) {

        int i=0;
        int n=arr.size();

        while(i+1<n && arr[i+1]>arr[i]){ //inc
            i++;
        }
        if(i==0 ||i==n-1) return false;
        
        while(i+1<n && arr[i+1]< arr[i]){//dec
            i++;
        }
        if(i==n-1) return false;
        while(i+1<n && arr[i+1]>arr[i]){//inc
            i++;
        }
        
        return i==n-1;
    }
};