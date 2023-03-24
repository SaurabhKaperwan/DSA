class Solution

{

	public:	//Function to find number of strongly connected components in the graph.

	

	void dfs(int node, vector<vector<int>> &adj, stack<int> &st, vector<int> &visited)

	{

	    visited[node] = 1;

	    

	    for(auto it : adj[node])

	    {

	        if(!visited[it])

	            dfs(it, adj, st, visited);

	    }

	    

	    st.push(node);

	}

	

	void newDfs(int node, vector<int> revAdj[], vector<int> &visited)

	{

	    visited[node] = 1;

	    

	    for(auto it : revAdj[node])

	    {

	        if(!visited[it])

	            newDfs(it, revAdj, visited);

	    }

	}

	

    int kosaraju(int V, vector<vector<int>>& adj)

    {

        vector<int> visited(V, 0);

        stack<int> st;

        vector<int> revAdj[V];

        

        //Sort the vertices in the term of finishing time

        for(int i = 0; i < V; i++)

        {

            if(!visited[i])

                dfs(i, adj, st, visited);

        }

        

        //Reverse all edges

        

        for(int i = 0; i < V; i++)

        {

            visited[i] = 0;

            for(auto it : adj[i])

            {

                revAdj[it].push_back(i);

            }

        }

        

        int strong = 0;

        

        while(!st.empty())

        {

            int node = st.top();

            st.pop();

            

            if(!visited[node])

            {

                strong++;

                newDfs(node, revAdj, visited);

            }

        }

        return strong;

        

    }

};
