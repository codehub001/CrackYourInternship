//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int N = Integer.parseInt(br.readLine().trim());
            String[] S1 = br.readLine().trim().split(" ");
            String[] S2 = br.readLine().trim().split(" ");
            int[] KnightPos = new int[2];
            int[] TargetPos = new int[2];
            for(int i = 0; i < 2; i++){
                KnightPos[i] = Integer.parseInt(S1[i]);
                TargetPos[i] = Integer.parseInt(S2[i]);
            }
            Solution obj = new Solution();
            int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
            System.out.println(ans);
       }
    }
}

// } Driver Code Ends


class Solution
{
    //Function to find out minimum steps Knight needs to reach target position.
    public int minStepToReachTarget(int KnightPos[], int TargetPos[], int N)
    {
        boolean [][]vis = new boolean[N+1][N+1];
        
        Queue<int[]> q = new ArrayDeque<>();
        q.add(KnightPos);
        
        vis[KnightPos[0]][KnightPos[1]] =true;
        int step =0;
        
        int [][]dir ={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
        
        while(q.size() > 0){
            
            int sz = q.size();
                
            while(sz-- >0 ){
                int []pos = q.poll();
                
                if( pos[0] == TargetPos[0] && pos[1] == TargetPos[1] ){
                    return step;
                }
                
                for(int i=0 ; i < 8 ;i++){
                    int r = pos[0] + dir[i][0];
                    int c = pos[1] + dir[i][1];
                    
                    if( r > 0 && r <= N && c > 0 && c <= N && !vis[r][c] ){
                        vis[r][c] =true;
                        q.offer( new int[]{r ,c } );
                    }
                }
                
            }
            step++;
        }
        return -1;
    }
}
