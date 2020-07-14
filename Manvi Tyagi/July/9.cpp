
class Solution
{
public:
    vector<vector<long double>> levels;
    long double mn = INT_MAX;
    long double mx = INT_MIN;
    void helper(TreeNode *root, long double hd = 1, long double level = 0)
    {
        if (!root)
            return;

        if (levels.size() <= level)
            levels.resize(level + 1);

        levels[level].push_back(hd);
        mn = min(mn, hd);
        mx = max(mx, hd);
        helper(root->left, 2 * hd, level + 1);
        helper(root->right, 2 * hd + 1, level + 1);
    }

    long double widthOfBinaryTree(TreeNode *root)
    {
        helper(root);
        long double ans = 0;
        for (auto lev : levels)
        {
            sort(lev.begin(), lev.end());
            long double curr = 0;
            if (lev.size())
                curr = lev[lev.size() - 1] - lev[0];
            ans = max(ans, curr);
        }
        return ans + 1;
    }
};
