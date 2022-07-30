class Solution {
public:
  int dfs(vector<vector<int>>& g, int i, int j, int s, int t_s) {//s is the current step t_s is total step
  if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == -1) 
      return 0;
  if (g[i][j] == 2)// reached the end
      return s == t_s ? 1 : 0;
  g[i][j] = -1;//visited so cant go
  int paths = dfs(g, i + 1, j, s + 1, t_s) + dfs(g, i - 1, j, s + 1, t_s) +
    dfs(g, i, j + 1, s + 1, t_s) + dfs(g, i, j - 1, s + 1, t_s);
  g[i][j] = 0;
  return paths;
}
int uniquePathsIII(vector<vector<int>>& g) {
  int i1 = 0, j1 = 0, steps = 0;// i1 j1 is start index
  for (int i = 0; i < g.size(); i++)
    for (int j = 0; j < g[0].size(); j++) {
      if (g[i][j] == 1){
          i1 = i;
          j1 = j;
      }
      if(g[i][j] != -1) 
          steps++;// calc total steps
    }
  return dfs(g, i1, j1, 1, steps);
  }
};