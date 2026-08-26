class MedianFinder {
public:
    // Smaller half
    priority_queue<int> maxh;

    // Larger half
    priority_queue<int, vector<int>, greater<int>> minh;

    MedianFinder() {}

    void addNum(int num) {

        // Put num into the smaller half first
        maxh.push(num);

        // Move the largest element of smaller half
        // to the larger half
        minh.push(maxh.top());
        maxh.pop();

        // Keep maxh equal in size to minh
        // or one element larger
        if (minh.size() > maxh.size()) {
            maxh.push(minh.top());
            minh.pop();
        }
    }

    double findMedian() {

        if (maxh.size() > minh.size())
            return maxh.top();

        return ((long long)maxh.top() + minh.top()) / 2.0;
    }
};