#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool atm_backtracking(vector<int>& t, int s, int current_sum, vector<int>& current_solution, int index) {
    if (current_sum == s) {
        for (int i = 0; i < current_solution.size(); ++i) {
            cout << current_solution[i] << " ";
        }
        cout << endl;
        return true;
    }
    if (current_sum > s || index == t.size()) {
        return false;
    }
    
    // Thử chọn tờ tiền ở vị trí index
    current_solution.push_back(t[index]);
    if (atm_backtracking(t, s, current_sum + t[index], current_solution, index + 1)) {
        return true;
    }
    current_solution.pop_back(); // Quay lui
    
    // Không chọn tờ tiền ở vị trí index
    return atm_backtracking(t, s, current_sum, current_solution, index + 1);
}

void atm(int n, int s, vector<int>& t) {
    sort(t.rbegin(), t.rend()); // Sắp xếp giảm dần
    vector<int> current_solution;
    if (!atm_backtracking(t, s, 0, current_solution, 0)) {
        cout << "-1" << endl;
    }
}

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    atm(n, s, t);
    return 0;
}
