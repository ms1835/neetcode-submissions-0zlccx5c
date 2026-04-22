class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int first, second;

        while(pq.size() > 1){
            first = pq.top(); pq.pop();
            second = pq.top(); pq.pop();
            if(first > second)
                pq.push(first - second);
            else if(second > first)
                pq.push(second - first);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
