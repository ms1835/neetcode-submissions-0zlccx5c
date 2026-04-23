/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 0) return true;
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
            return a.end < b.end;
        });
        for(int i=1;i<n;i++){
            if(intervals[i-1].end > intervals[i].start)
                return false;
        }
        return true;
    }
};
