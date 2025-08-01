#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
  public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
  public:
    Node *help(vector<vector<int>> &grid, int x1, int y1, int x2, int y2) {
        int last = grid[x1][y1];
        bool isEqual = true;
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                if (grid[i][j] != last) {
                    isEqual = false;
                }
                if (!isEqual)
                    break;
            }
            if (!isEqual)
                break;
        }
        if (isEqual) {
            return new Node(last, true, nullptr, nullptr, nullptr, nullptr);
        } else {
            Node *topLeft = help(grid, x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
            Node *bottomLeft = help(grid, (x1 + x2) / 2, y1, x2, (y1 + y2) / 2);
            Node *topRight = help(grid, x1, (y1 + y2) / 2, (x1 + x2) / 2, y2);
            Node *bottomRight = help(grid, (x1 + x2) / 2, (y1 + y2) / 2, x2, y2);
            Node *root = new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
            return root;
        }
    }
    Node *construct(vector<vector<int>> &grid) {
        int n = grid.size();
        return help(grid, 0, 0, n, n);
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}};
    s.construct(grid);
}