//Using BFS

{
    public:
        
        bool bfs(int start,int V,vector<int>adj[],int color[])
        {
            queue<int> q;
	        q.push(start);
	        color[start]=0;
	        while(!q.empty())
	        {
	           int node=q.front();
	           q.pop();
	               
	           for(auto it : adj[node])
	           {
	               if(color[it]==-1)
	               {
	                   color[it] = !color[node];   
	                   q.push(it);
	               }
	               else if(color[it] == color[node])
	               {
	                   return false;
	               }
	           }
	       }
	       return true;
        }
        
	    bool isBipartite(int V, vector<int>adj[])
	    {
	       int color[V];
	       for(int i=0;i<V;i++)
	       {
	           color[i]=-1;
	       }
	       for(int i=0;i<V;i++)
	       {
	           if(color[i]==-1)
	           {
	                if(bfs(i,V,adj,color)==false)
	                    return false;
	           }
	       }
	       return true;
	    }

};


//Using DFS


{
    public:
    
        bool dfs(int start,int col,vector<int> adj[],int color[])
        {
            color[start]=col;
            
            for(auto it : adj[start])
            {
                if(color[it]==-1)
                {
                
                    if(dfs(it,!col,adj,color)==false)
                        return false;
                }
                else if(color[it]==color[start])
                    return false;
            }
            return true;
        }
        
	    bool isBipartite(int V, vector<int>adj[])
	    {
	        int color[V];
	        for(int i=0;i<V;i++)
	            color[i]=-1;
	        
	        for(int i=0;i<V;i++)
	        {
	            if(color[i]==-1)
	            {
	                if(dfs(i,0,adj,color)==false)
	                    return false;
	            }
	        }
	        return true;
	    }

};
