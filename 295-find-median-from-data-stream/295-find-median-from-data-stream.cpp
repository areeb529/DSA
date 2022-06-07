class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.size()<=pq2.size()){
            pq1.push(num);
        }
        else{
            pq2.push(num);
        }
        while(!pq1.empty()&&!pq2.empty()&&pq1.top()>pq2.top()){
            int num1=pq1.top();
            int num2=pq2.top();
            pq1.pop();
            pq2.pop();
            pq2.push(num1);
            pq1.push(num2);
        }
        
    }
    
    double findMedian() {
        double ans;
        if(pq1.size()==pq2.size()){
            ans=(pq1.top()+pq2.top())/2.0;
        }
        else ans=pq1.top();
        return ans;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */