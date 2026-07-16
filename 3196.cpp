#include <bits/stdc++.h>

using namespace std;

typedef struct point {
    char type;
    bool reachFromS = false; 
    // 或许需要反向传播, 来压缩状态?
    // 路径是什么不重要, 知道能到达/能从某个点到达就可以.
    bool ableToGoT = false;
} point;

int main() {
    int R, C;

    cin >> R >> C;

    /**
     * 使用 BFS 来扫一遍吗?
     * 但是能移动到, 却又不能到达终点比较难以测定.
     * 注意, 可能达到目标位置之后继续走, 达到这个满足条件的点.
     * 从起点发出, 扫描一次点之后:?
     *  1. 从这些标记的点, 去够一下 T
     *  2. 从 T 反向 BST, 去够这些点
     */

    char tmp;
    vector<vector<point>> Map(R, vector<point>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> tmp;
            Map[i][j] = {tmp};
            // 只用一个参数, 应该不会有事吧?
        }
    }

    // 使用 DFS, 读到了就直接返回, 并一路标记可到达.
}