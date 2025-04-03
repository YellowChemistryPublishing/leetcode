/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

#include <vector>
#include <map>
#include <queue>

using namespace std;

class Node {
    public:
        int val;
        vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };
    
// @lc code=start
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        map<Node*, Node*> m;
        queue<Node*> q;
        q.push(node);
        while (!q.empty())
        {
            Node* next = q.front();
            q.pop();
            if (!m.count(next))
            {
                m[next] = new Node(next->val);
            }
            for (auto n : next->neighbors)
            {
                if (!m.count(n))
                {
                    q.push(n);
                    m[n] = new Node(n->val);
                }
                m[next]->neighbors.push_back(m[n]);
            }
        }
        return m[node];
    }
};
// @lc code=end

