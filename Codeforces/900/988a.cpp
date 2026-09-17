#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    bool visited[105] = {false}; 
    int team_indices[105];       
    int unique_count = 0;        

    for (int i = 0; i < n; ++i) {
        int rating;
        cin >> rating;

        if (!visited[rating]) {
            visited[rating] = true;
            team_indices[unique_count] = i + 1; 
            unique_count++;                     
        }
    }

    if (unique_count < k) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < k; ++i) {
            cout << team_indices[i] << (i == k - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
