class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;

        unordered_map<int,int> mp;
        for(int num: hand){
            mp[num]++;
        }

        priority_queue<int, vector<int>, greater<int> > pq;
        for(auto &x: mp){
            pq.push(x.first);
        }

        while(!pq.empty()){
            int top = pq.top();
            for(int i=top;i<top+groupSize;i++){
                if(mp.find(i) == mp.end())
                    return false;
                mp[i]--;
                if(mp[i] == 0){
                    if(i != pq.top())
                        return false;
                    pq.pop();
                }
            }
        }
        return true;
    }
};
