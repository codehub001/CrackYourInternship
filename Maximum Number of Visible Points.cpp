class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int answer = 0;
        double pi = acos(-1.0);
        vector<double> pointAngles;
        for(auto p : points){
            if(p[0] == location[0] && p[1] == location[1]){
                answer += 1;
            }else {
                int dx = p[0] - location[0];
                int dy = p[1] - location[1];
                double angle = atan2(dy,dx); 
                double angle1 = angle * (180) / pi;
                pointAngles.push_back(angle1);
            }
        }
        sort(pointAngles.begin(),pointAngles.end());
        int n = pointAngles.size();
        for(int i= 0; i < n ; ++i) {
            pointAngles.push_back(pointAngles[i] + 360);
        }
        int start = 0;
        int cnt = 0;
        for(int i =0; i < pointAngles.size(); ++i) {
            if(pointAngles[i] - pointAngles[start] > angle){
                start++;
            }
            cnt = max(cnt, i - start + 1);
        }
        answer += cnt;
        return answer;
    }
};
