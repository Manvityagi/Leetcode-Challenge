class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        unordered_set<string> st;
        for (int i = 0; i < n; i++)
        {
            if (i && arr[i] == arr[i - 1])
                continue;

            int target = -1 * arr[i];
            int low = i + 1, high = n - 1;
            while (low < high)
            {
                if (arr[low] + arr[high] == target)
                {
                    string temp = to_string(arr[i]) + "-" + to_string(arr[low]) + "-" + to_string(arr[high]);
                    if (st.find(temp) == st.end())
                    {
                        st.insert(temp);
                        ans.push_back({arr[i], arr[low], arr[high]});
                    }
                    low++;
                    high--;
                }
                else if (arr[low] + arr[high] < target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        return ans;
    }
};