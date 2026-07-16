/**
 * 注意引用与复制的使用场景!
 * 小数据, 干就完了!
 */

#include <bits/stdc++.h>

using namespace std;

typedef struct Window {
    int x1;
    int y1;
    int x2;
    int y2;
    int id;
    int level;
} Window;

struct Compare {
    bool operator()(const Window& a, const Window& b) {
        return a.level > b.level;
        // level 小的优先.
    }
};

int main() {
    int N, M;

    cin >> N >> M;

    vector<Window> Windows(N);

    priority_queue<Window, vector<Window>, Compare> tmpWindows;

    int x1, y1, x2, y2;

    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        Windows[i] = {x1, y1, x2, y2, i + 1, N - i};
        // 编号: ok
        // 层数: N -> 1
    }

    int opx, opy;
    for (int j = 0; j < M; j++) {
        cin >> opx >> opy;
        for (auto wd : Windows) {
            
            if (opx >= wd.x1 && opx <= wd.x2
                && opy >= wd.y1 && opy <= wd.y2) {
                tmpWindows.push(wd);
            }
        } // 读取所有分布在这个点上面的窗口, 结束.

        if (tmpWindows.empty()) {
            cout << "IGNORED\n"; 

        } else {
            // 给出最上方那个窗口
            Window frontWindow = tmpWindows.top();
            // 开始更新那些 level 比它更高的!
            int curr_level = frontWindow.level;

            cout << frontWindow.id << "\n";

            for (auto& wd : Windows) {
                if (wd.level > curr_level) {
                    continue;
                } else if (wd.level == curr_level) {
                    wd.level = 1;
                } else {
                    wd.level++;
                    // 本来更上的, 全部往下移动一层!
                }
            }
        }
        while (!tmpWindows.empty()) {
            tmpWindows.pop();
        }
    }

    return 0;
}