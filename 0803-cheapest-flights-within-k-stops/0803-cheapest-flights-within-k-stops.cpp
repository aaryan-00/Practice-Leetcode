class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n]; // Create an adjacency list to represent the graph
        for(auto it: flights){
            vector<int> x = it;
            adj[x[0]].push_back({x[1], x[2]}); // Add edges to the adjacency list with corresponding weights
        }
        vector<int> distance(n, 1e9); // Initialize an array to store the minimum distance from source to each node, set to a high value initially
        distance[src] = 0; // Set the distance from source to itself as 0
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // Create a min heap (priority queue) to store {stops, {node, cost}} pairs, sorted by cost in ascending order
        pq.push({0, {src, 0}}); // Push the source node with stops and cost as 0 into the queue
        while(!pq.empty()){ // Perform BFS until the queue is empty
            auto it = pq.top(); // Get the top element from the min heap
            pq.pop(); // Pop the top element from the min heap
            int stops = it.first; // Get the number of stops taken so far
            int node = it.second.first; // Get the current node
            int cost = it.second.second; // Get the current cost to reach the current node
            if(stops > k) continue; // If the number of stops taken exceeds k, skip to the next iteration
            for(auto x : adj[node]){ // Iterate through the neighbors of the current node
                int edge_weight = x.second; // Get the weight of the edge
                int adjacent_node = x.first; // Get the neighboring node
                if(stops <= k && edge_weight + cost < distance[adjacent_node]){
                    // If the number of stops taken is less than or equal to k, and the new cost to reach the neighboring node is less than the current minimum distance, update the minimum distance and push the neighboring node into the queue with updated stops and cost
                    distance[adjacent_node] = edge_weight + cost;
                    pq.push({stops + 1, {adjacent_node, cost + edge_weight}});
                }
            }
        }
        if(distance[dst] == 1e9) return -1; // If there is no path from source to destination, return -1
        return distance[dst]; // Return the minimum distance from source to destination
    }
};