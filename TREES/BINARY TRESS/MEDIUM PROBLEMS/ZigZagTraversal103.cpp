#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
};
/*perform zigzag travesal
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

*/

/*aproach
we store nodes in queue normally like we do in BFS, but when putting the in vector,
we put them normally or reverse depending on the level and zig zag pattern
*/
//T.C O(N)  S.C O(N)
vector<vector<int>> ZigZag(TreeNode *root)
{
    queue<TreeNode *> qs;
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    int level = 0;
    qs.push(root);
    while (!qs.empty())
    {
        int size = qs.size();

        ans.push_back(vector<int>(size)); // making space to avoid run time error
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = qs.front();
            qs.pop();
            if (temp->left != NULL)
            {
                qs.push(temp->left);
            }
            if (temp->right != NULL)
            {
                qs.push(temp->right);
            }
            if (level%2!=0) // we have to insert nodes in reverse order
            {
                int index = size - i - 1; // i from revere
                ans[level][index] = temp->val;
            }
            else // left to right
            {
                ans[level][i] = temp->val;
            }
        }
        level++;
    }
    return ans;
}
