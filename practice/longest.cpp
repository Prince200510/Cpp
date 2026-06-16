#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> num_set(arr.begin(), arr.end());
    int count = 0;

    for(int num : num_set) {
        if(num_set.find(num - 1) == num_set.end()) {
            int current_num = num;
            int current_streak = 1;

            while(num_set.find(current_num + 1) != num_set.end()) {
                current_num++;
                current_streak++;
            }

            count = max(count, current_streak);
        }
    }
    cout << count << endl;
}