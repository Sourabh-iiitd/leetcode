class CountIntervals {
    map<int,int> mpp;
    int c=0;
public:

    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it=mpp.lower_bound(left); 
        if (it!=mpp.begin() && prev(it)->second >= left) {
            it--; 
        }
        while (it != mpp.end() && it->first <= right) {
           
            left=min(left, it->first);
            right=max(right, it->second);
            
            
            c-=(it->second-it->first+1);
            
           
            it=mpp.erase(it);
        }
        mpp[left]=right;
        c+=(right-left+1);
    }
    
    int count() {
        return c;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj=new CountIntervals();
 * obj->add(left,right);
 * int parampp_2=obj->count();
 */