class Solution {
public:
    void backtracking(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path, int src){
        if(src == graph.size() - 1)
        {
            paths.push_back(path);
            return;
        }
        
        for(auto nextNode : graph[src]){
            path.push_back(nextNode);
            backtracking(graph,paths,path,nextNode);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        path.push_back(0);
        backtracking(graph,paths,path,0);
        
        return paths;
    }
};