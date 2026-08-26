class MedianFinder {
   public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    int cnt=0;
    MedianFinder() {}

    void addNum(int num) {
        cnt++;
        int size1 = maxh.size(), size2 = minh.size();
        if (size1 == 0)
            maxh.push(num);
        else if (size2 == 0) {
            if (maxh.top() > num) {
                minh.push(maxh.top());
                maxh.pop();
                maxh.push(num);
            } else
                minh.push(num);
        }
        else{
            int val1=maxh.top();
            int val2=minh.top();
            if(size1>size2){
                if(val1>num){
                    minh.push(val1);
                    maxh.pop();
                    maxh.push(num);
                }
                else
                    minh.push(num);
            }
            else{
                if(val2<num){
                    maxh.push(val2);
                    minh.pop();
                    minh.push(num);
                }
                else
                    maxh.push(num);
            }
        }
    }

    double findMedian() {
        if((cnt&1)==1)
            return maxh.top()*1.0;
        return (maxh.top()+minh.top())/2.0;
    }
};
