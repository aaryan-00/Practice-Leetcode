class Solution {
public:
    int n;
	vector<vector<int>> adjList;
	vector<int> sub_sz, dis_val, ans;

	void dfs1(int node, int par) {

		for (int child : adjList[node]) {
			if (child != par) {
				dfs1(child, node);
				sub_sz[node] += sub_sz[child];
				dis_val[node] += dis_val[child] + sub_sz[child];
			}
		}
		sub_sz[node]++;
	}

	void dfs2(int node, int par, int dpVal) {
		ans[node] = dis_val[node] + dpVal + (n - sub_sz[node]);

		for (int child : adjList[node]) {
			if (child != par)
            {
				dfs2(child, node, ans[node] - dis_val[child] - sub_sz[child]);
            }
		}
	}

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
		adjList.resize(n), sub_sz.resize(n), dis_val.resize(n), ans.resize(n);
		for (vector<int> &v : edges) {
			adjList[v[0]].push_back(v[1]);
			adjList[v[1]].push_back(v[0]);
		}
		dfs1(0, 0);
        // for(auto &i:sub_sz)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto &i:dis_val)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
		dfs2(0, 0, 0);
        return ans;
    }
};


// class Solution {
// public:
//     int n;
// 	vector<vector<int>> adjList;
// 	vector<int> sub_sz, dis_val, ans;

// 	void dfs1(int node, int par) {

// 		for (int child : adjList[node]) {
// 			if (child != par) {
// 				dfs1(child, node);
// 				sub_sz[node] += sub_sz[child];
// 				dis_val[node] += dis_val[child] + sub_sz[child];
// 			}
// 		}
// 		sub_sz[node]++;
// 	}

//     void dfs_new(int node, int par) {

// 		for (int child : adjList[node]) {
// 			if (child != par)
//             {
//                 dis_val[child] = dis_val[node] - sub_sz[child] + sub_sz.size() - sub_sz[child];
//                 dfs_new(child, node);
//             }
// 		}
// 	}
//     vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
//         n = N;
// 		adjList.resize(n), sub_sz.resize(n), dis_val.resize(n), ans.resize(n);
// 		for (vector<int> &v : edges) {
// 			adjList[v[0]].push_back(v[1]);
// 			adjList[v[1]].push_back(v[0]);
// 		}
// 		dfs1(0, 0);
//         dfs_new(0, 0);
// 		return dis_val;
//     }
// };


