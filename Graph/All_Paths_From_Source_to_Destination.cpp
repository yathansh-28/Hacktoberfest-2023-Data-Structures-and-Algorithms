// LeetCode Problem Link:- https://leetcode.com/problems/all-paths-from-source-to-target
// Author :- Jayant Patidar

class Solution {

void solve(vector<vector<int>>& graph, int source, int target, vector<vector<int>>& ans, vector<int> ds)
{
    if(source == target){
        ds.push_back(source);        // it is the condition where we have found our right path 
        ans.push_back(ds) ;             // hence storing it to the ans 
    }

    ds.push_back(source) ;              // it may be a part of right path

    for(auto it: graph[source]){
        solve(graph, it, target, ans, ds) ;       // call dfs for every neighbour 
    }
}

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> ans;   // for storing the ans;
        vector<int> ds;             // for storing perticular path;

        int target = graph.size() ;     // the last node is the target node where we have to reach
        solve(graph, 0, target-1, ans, ds) ;         //dfs

        return ans;                // returning ans; 
    }
};
