#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
};
//T.C NlogN  S.C O(N)
vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> mp;       // mp[HorizontalDistance][level].insert(value);
    queue<pair<TreeNode *, pair<int, int>>> qs; // pair( NodeAdress,pair(HD,lvl) );
    vector<vector<int>> ans;
    
    if (root == NULL)
    {

        return ans;
    }

    qs.push({root, {0, 0}}); // root as HD and level of 0

    while (!qs.empty())
        
    {
        auto CurrentQs = qs.front();
        qs.pop();
        // pushing value in map
        int lvl = CurrentQs.second.second;
        int Hd = CurrentQs.second.first;
        mp[Hd][lvl].insert(CurrentQs.first->val);
        // pushing left and right nodes

        if (CurrentQs.first->left != NULL)
        {
            qs.push({CurrentQs.first->left, {Hd - 1, lvl + 1}});
        }
        if (CurrentQs.first->right != NULL)
        {
            qs.push({CurrentQs.first->right, {Hd + 1, lvl + 1}});
        }
    }
    // Extracting answer from MAP

    for (auto i : mp)
    {
        vector<int> col;
        for (auto j : i.second)
        {
            col.insert(col.end(), j.second.begin(), j.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
