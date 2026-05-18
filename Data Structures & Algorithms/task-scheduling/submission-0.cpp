class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for(int ct: freq){
            if(ct > 0)
                pq.push(ct);
        }

        int time = 0;
        queue<pair<int,int>> q;
        while(!pq.empty() || !q.empty()){
            time++;
            if(pq.empty()){
                time = q.front().second;
            }
            else{
                int top = pq.top() - 1;
                pq.pop();
                if(top > 0)
                    q.push({top, time+n});
            }

            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
