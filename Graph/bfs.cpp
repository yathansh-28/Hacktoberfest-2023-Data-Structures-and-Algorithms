#include <bits/stdc++.h>
using namespace std;
void findAdj(unordered_map<int, set<int>>& s, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        s[u].insert(v);
        s[v].insert(u);
    }
}

void solve(unordered_map<int, set<int>>& s, vector<int>& answer,
    unordered_map<int, bool>& visited, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int frontNode = q.front();
        answer.push_back(frontNode);
        q.pop();
        for (auto i : s[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    findAdj(adjList, edges);
    unordered_map<int, bool> visited;
    vector<int> answer;
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
            solve(adjList, answer, visited, i);
    }
    return answer;
    // Write your code here
}
int main()
{
    int vertex = 3;
    vector<pair<int, int>> edges;
    edges.push_back({ 0, 1 });
    edges.push_back({ 0, 3 });
    edges.push_back({ 1, 3 });
    vector<int> ans = BFS(vertex, edges);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
        /* code */
    }

    return 0;
}

/*
#include <iostream>
using namespace std;
string fun(string t, string s = "x", int r = 1)
{
    while(r--)
    {
        s += s;
        t = t + s;
    }
    return s;
}
int main()
{
    string str = "a";
    cout << fun(str);
    return 0;
}
*/
