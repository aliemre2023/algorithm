#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, O;
    cin >> N >> O;

    priority_queue<int> maxHeap;
    vector<int> allScores;

    for (int i = 0; i < O; ++i) {
        string operation;
        cin >> operation;

        if (operation == "add") {
            int X;
            cin >> X;

            maxHeap.push(X);

            if (maxHeap.size() > N) {
                int removedScore = maxHeap.top();
                maxHeap.pop();
            }
        } 
        else if (operation == "top") {
            int K; cin >> K;

            vector<int> arr(K,0);
            for (int j = 0; j < K; ++j) {
                arr[j] = maxHeap.top();
                cout << maxHeap.top() << " ";
                maxHeap.pop();
            }
            cout << endl;
            
            for(int j = 0; j < K; j++){
                maxHeap.push(arr[j]);
            }
        }
    }

    return 0;
}
