#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 3
#define INF 1e9

// State representation as a flat array
struct Node {
    vector<int> mat; // Stores the state of the puzzle in a flat array
    int x, y;        // Blank tile coordinates
    int cost;        // Number of misplaced tiles
    int level;       // Number of moves so far

    Node(vector<int> mat, int x, int y, int cost, int level)
        : mat(mat), x(x), y(y), cost(cost), level(level) {}
};

// bottom, left, top, right (movement directions)
int row[] = {1, 0, -1, 0};
int col[] = {0, -1, 0, 1};

// Function to calculate the number of misplaced tiles
int calculateCost(const vector<int>& current, const vector<int>& final) {
    int count = 0;
    for (int i = 0; i < N * N; i++) {
        if (current[i] && current[i] != final[i]) {
            count++;
        }
    }
    return count;
}

// Function to check if (x, y) is a valid coordinate
bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Comparison object to be used to order the priority queue
struct comp {
    bool operator()(const Node& lhs, const Node& rhs) const {
        return (lhs.cost + lhs.level) > (rhs.cost + rhs.level);
    }
};

// Function to solve the N*N - 1 puzzle using Branch and Bound
int solve(const vector<int>& initial, int x, int y, const vector<int>& final) {
    // Create a priority queue to store live nodes of the search tree
    priority_queue<Node, vector<Node>, comp> pq;

    // Create the root node and calculate its cost
    int rootCost = calculateCost(initial, final);
    pq.push(Node(initial, x, y, rootCost, 0));

    // Use a set to store visited states (to avoid revisiting)
    set<vector<int>> visited;
    visited.insert(initial);

    // Process nodes until the priority queue is empty
    while (!pq.empty()) {
        Node minNode = pq.top(); // Get the node with the least cost
        pq.pop();

        // If the current node is the goal state, return the number of moves
        if (minNode.cost == 0) {
            return minNode.level;
        }

        // Generate all possible moves (up to 4 moves)
        for (int i = 0; i < 4; i++) {
            int newX = minNode.x + row[i];
            int newY = minNode.y + col[i];

            if (isSafe(newX, newY)) {
                // Create a new state by swapping the blank tile with its neighbor
                vector<int> newMat = minNode.mat;
                swap(newMat[minNode.x * N + minNode.y], newMat[newX * N + newY]);

                // Check if this state has been visited before
                if (visited.find(newMat) == visited.end()) {
                    // Calculate the cost of the new state
                    int newCost = calculateCost(newMat, final);
                    pq.push(Node(newMat, newX, newY, newCost, minNode.level + 1));
                    visited.insert(newMat); // Mark this state as visited
                }
            }
        }
    }
    return -1; // If no solution is found
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Final state
    vector<int> final = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    // Initial state input
    vector<int> initial(N * N);
    pair<int, int> initpos;
    for (int i = 0; i < N * N; i++) {
        cin >> initial[i];
        if (initial[i] == 0) {
            initpos = {i / N, i % N}; // Record position of the blank tile
        }
    }

    // Solve the puzzle and output the number of moves
    int moves = solve(initial, initpos.first, initpos.second, final);
    cout << moves << "\n";

    return 0;
}
