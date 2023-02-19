// You are given an undirected weighted graph of n nodes (0-indexed), 
// represented by an edge list where edges[i] = [a, b] is an undirected edge connecting 
// the nodes a and b with a probability of success of traversing that edge succProb[i].

// Given two nodes start and end, find the path with the maximum probability of success to go 
// from start to end and return its success probability.

// If there is no path from start to end, return 0. Your answer will be accepted if it differs 
// from the correct answer by at most 1e-5.

#include <vector>
#include <queue>
using namespace std;

//
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // build adjacency matrix
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            adj[edge[0]].push_back({edge[1], succProb[i]});
            adj[edge[1]].push_back({edge[0], succProb[i]});
        }
        //shortest distances
        vector<double> distances(n, 0);
        distances[start] = 1;

        // priority queue -> (cost, node)
        priority_queue<pair<double, int>> pq;
        pq.push({1, start});

        while (!pq.empty()) {
            double cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // if destination is reached, return cost to get here
            if (node == end) {
                return cost;
            }

            // check & relax all neighboring edges
            for (int i = 0; i < adj[node].size(); i++) {
                int neighbor = adj[node][i].first;
                double prob = adj[node][i].second;
                if (cost * prob > distances[neighbor]) {
                    distances[neighbor] = cost * prob;
                    pq.push({distances[neighbor], neighbor});
                }
            }
        }
        return 0;
    }
};