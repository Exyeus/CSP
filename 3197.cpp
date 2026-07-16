#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    cin >> N;

    vector<int> numl(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> numl[i];
    }

    int level1 = N - 1;

    int count = 0;

    for (int i = 0; i < level1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (numl[i] + numl[j] == 0) {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}