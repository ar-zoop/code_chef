//SC: O(1)
//TC: O(n+m)
class Solution
{
public:
    int mid_pos;

    double merge(vector<int> &array1, vector<int> &array2, int n, int m, int mid)
    {
        int left = 0, right = 0, k = -1;
        int mid_prev = -1, mid_main = -1;
        while (k < mid && left < n && right < m)
        {
            if (array2[right] < array1[left])
            {
                mid_prev = mid_main;
                mid_main = array2[right];
                k++;
                right++;
            }
            else
            {
                mid_prev = mid_main;
                mid_main = array1[left];
                k++;
                left++;
            }
        }
        while (k < mid && left < n)
        {
            mid_prev = mid_main;
            mid_main = array1[left];
            k++;
            left++;
        }
        while (k < mid && right < m)
        {
            mid_prev = mid_main;
            mid_main = array2[right];
            k++;
            right++;
        }
        if ((n + m) % 2 == 0)
        {
            return (mid_main + mid_prev) / 2.0;
        }
        return mid_main;
    }

    double MedianOfArrays(vector<int> &array1, vector<int> &array2)
    {
        // Your code goes here
        int n = array1.size();
        int m = array2.size();
        mid_pos = (n + m) / 2;
        return merge(array1, array2, n, m, mid_pos);
    }
};