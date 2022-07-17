class MedianFinder {
public:
    
    priority_queue<int> maxq;
    priority_queue<int,vector<int>,greater<int>> minq;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int minq_sz=minq.size();
        int maxq_sz=maxq.size();
        
        if(minq.empty() || (!minq.empty() && num>minq.top())) {
            // cout<<"----------"<<endl;
            // cout<<"pushing in minq "<<num<<endl;
            minq.push(num);
        }
        else {
            // cout<<"pushing in maxq "<<num<<endl;
            maxq.push(num);
        }
        
        while(!maxq.empty() && maxq.size()>minq.size()) {
            int x=maxq.top();
            maxq.pop();
            // cout<<"shifting "<<x<<" into minq"<<endl;
            minq.push(x);
        }
        
        while(!minq.empty() && minq.size()>1+maxq.size()) {
            int x=minq.top();
            minq.pop();
            // cout<<"shifting "<<x<<" into maxq"<<endl;
            maxq.push(x);
        }
        
        // cout<<maxq.size()<<" "<<minq.size()<<endl;
    }
    
    double findMedian() {
        if(maxq.size()==minq.size()) {
            if(maxq.size()==0) {
                return -1;
            }
            double d=maxq.top();
            double d1=minq.top();
            d+=d1;
            d/=2;
            return d;
        }
        if(maxq.size()<minq.size()) {
            double d=minq.top();
            return d;
        }
        double d=maxq.top();
        return d;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */