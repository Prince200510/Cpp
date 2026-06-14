#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n,k,x;
        cin >> n >> k >> x;

        vector<int> a(n);

        for(int i=0;i<n;i++)
            cin >> a[i];

        for(int i=0;i<=n-k;i++) {

            vector<int> neg;

            for(int j=i;j<i+k;j++) {
                if(a[j] < 0)
                    neg.push_back(a[j]);
            }

            sort(neg.begin(), neg.end());

            if(neg.size() < x)
                cout << 0 << " ";
            else
                cout << neg[x-1] << " ";
        }

        cout << "\n";
    }
}