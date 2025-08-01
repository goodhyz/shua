#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    string val;
    TreeNode(string v, TreeNode *l = nullptr, TreeNode *r = nullptr)
    {
        val = v;
        left = l;
        right = r;
    }
};

void buildTree(TreeNode *root, int idx)
{
    int l = 2 * idx + 1, r = 2 * idx + 2;
}
int main()
{
    string node;
    vector<string> nodes;
    while (cin >> node)
    {
        nodes.push_back(node);
    }

    int n = nodes.size();
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    queue<int> q1;
    // 建树
    // 1 2 n 3 n n 4
    q1.push(0);
    int depth = 1, next = 1,count=0;
    while (!q1.empty())
    {
        int size = q1.size();
        while (size--)
        {
            if(depth%2){
                count++;
            }
            int front = q1.front();
            q1.pop();
            int l = next;
            int r = next + 1;
            if (l < n && nodes[l] != "N")
            {
                q1.push(l);
                next += 2;
            }
            if (r < n && nodes[r] != "N")
            {
                q1.push(r);
                next += 2;
            }
        }
        depth++;
    }
    cout<<count;
}
