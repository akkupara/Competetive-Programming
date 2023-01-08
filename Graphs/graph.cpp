1.) BFS traversal of a graph

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;
        // push the initial starting node 
        q.push(0); 
        vector<int> bfs; 
        // iterate till the queue is empty 
        while(!q.empty()) {
           // get the topmost element in the queue 
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            // traverse for all its neighbours 
            for(auto it : adj[node]) {
                // if the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }
};



2.) DFS taversal of a graph


class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour is not visited
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int start = 0;
        // create a list to store dfs
        vector<int> ls; 
        // call dfs for starting node
        dfs(start, adj, vis, ls); 
        return ls; 
    }
};




3.) Detect cycle using BFS

class Solution {
  public:
  bool detect(int src, vector<int> adj[], int vis[])
  {
      vis[src] = 1;
      queue<pair<int, int>> q; // node, parent
      q.push({src, -1});
      while(!q.empty())//traverse till the queue is non empty
      {
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          //check it adjecent neighbours
          for(auto adjacenNode: adj[node])
          {
              if(!vis[adjacenNode])//if it is not visited
                {
                    vis[adjacenNode] = 1;
                    q.push({adjacenNode, node});
                    
                }
              else if(parent != adjacenNode)//if it is already visited
              {
                  return true;
              }
          }
          
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i < V; i++)
        {
            if(!vis[i])
            {
                if(detect(i, adj, vis) == 1)//this part is for not connected components,
                //if in any one of the component the cycle exists, then in the whole graph the cycld exists
                
                    return true;
            }
        }
        return false;
    }
};


