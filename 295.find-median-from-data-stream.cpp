/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

#include <queue>

using namespace std;

// @lc code=start
class MedianFinder {
    priority_queue<int, vector<int>, less<void>> lt;
    priority_queue<int, vector<int>, greater<void>> gt;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lt.empty() && gt.empty())
            gt.push(num);
        else if (num >= gt.top())
        {
            gt.push(num);
            if (gt.size() > lt.size() + 1)
            {
                lt.push(gt.top());
                gt.pop();
            }
        }
        else
        {
            lt.push(num);
            if (lt.size() > gt.size())
            {
                gt.push(lt.top());
                lt.pop();
            }
        }
    }
    
    double findMedian() {
        if ((lt.size() + gt.size()) % 2 == 0)
            return (lt.top() + gt.top()) / 2.0;
        else return gt.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

