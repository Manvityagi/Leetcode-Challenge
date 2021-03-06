class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> ugly{0, 1};
        int m1 = 1, m2 = 1, m3 = 1;
        int next = 0;
        for (int i = 2; i <= n; i++)
        {

            next = min(ugly[m1] * 2, min(ugly[m2] * 3, ugly[m3] * 5));
            ugly.push_back(next);

            if (ugly[m1] * 2 == next)
                ++m1;

            if (ugly[m2] * 3 == next)
                ++m2;

            if (ugly[m3] * 5 == next)
                ++m3;
        }
        return ugly[n];
    }
};