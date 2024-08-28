class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        queue<pair<int,int>> q;
        q.push(make_pair(sr, sc));
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                pair<int,int> pixel = q.front();
                q.pop();
                if(pixel.first > 0 && !visited[pixel.first-1][pixel.second] && image[pixel.first-1][pixel.second] == image[pixel.first][pixel.second]) q.push(make_pair(pixel.first-1, pixel.second));
                if(pixel.first < image.size()-1 && !visited[pixel.first+1][pixel.second] && image[pixel.first+1][pixel.second] == image[pixel.first][pixel.second]) q.push(make_pair(pixel.first+1, pixel.second));
                if(pixel.second > 0 && !visited[pixel.first][pixel.second-1] && image[pixel.first][pixel.second-1] == image[pixel.first][pixel.second]) q.push(make_pair(pixel.first, pixel.second-1));
                if(pixel.second < image[0].size()-1 && !visited[pixel.first][pixel.second+1] && image[pixel.first][pixel.second+1] == image[pixel.first][pixel.second]) q.push(make_pair(pixel.first, pixel.second+1));
                image[pixel.first][pixel.second] = color;
                visited[pixel.first][pixel.second] = true;
            }
        }
        return image;
    }
};
