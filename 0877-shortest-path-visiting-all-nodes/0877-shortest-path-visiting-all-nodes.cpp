class Solution {
public:
/* a type of multisource bfs with each node as source
        ->BFS traversal from all nodes
        ->Basic BFS while maintaining visited arr will not work because we will be revisiting a node if necessary
        ->we need to avoid infinite loop, for this we will maintain the visited state of nodes(in bitmask) with current visiting node in a queue.

        In example 1, final bitmask will look like 1111
        */
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==1) return 0;

        int final_bitState = (1<<n) -1;
        // 1 << 4 == 10000 which in decimal is 16, 16-1 =15, 
        //which in binary is 1111


        queue<pair<int,int>> q;
        //<visiting node, bitmask>

        for(int i=0; i<n; i++){
            //now entering every node as starting point in queue
            q.push({i, (1<<i)});
        }

        //now to store all possible state of node
        int visitedNodes[n][final_bitState+1];
        memset(visitedNodes, 0, sizeof(visitedNodes));
        //[][each node having 2^n visited node]

        int shortest_path =0;

        while(!q.empty()){
            int size_of_lev = q.size();
            shortest_path++;

            for(int i=0; i<size_of_lev; i++){
                auto temp = q.front();
                q.pop();
                int node = temp.first;
                int bitstate = temp.second;

                //visiting the neighbours of the node
                for(auto neighbour : graph[node]){
                    int updated_bitstate = bitstate | (1<<neighbour);
                    if(updated_bitstate == final_bitState) return shortest_path;
                    //if already visited node with same bitstate then ignore
                    if(visitedNodes[neighbour][updated_bitstate] == 1) continue;
                    visitedNodes[neighbour][updated_bitstate] = 1;
                    
                    q.push({neighbour, updated_bitstate});
                }
            }
        }

        return -1;
    }
};