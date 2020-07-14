class Solution
{
public:
    vector<int> plusOne(vector<int> &arr)
    {
        vector<int> ans;

        int n = arr.size();
        int carry = 0, i = n - 1;

        while (i >= 0)
        {
            int val = arr[i] + carry;
            if (i == n - 1)
                val += 1;
            carry = val / 10;
            val = val % 10;
            ans.push_back(val);
            i--;
        }
        if (carry)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};