#include <iostream>
#include <vector>

 int removeDuplicates(std::vector<int>& nums,int n) {
        if (n == 0 || n == 1)
            return n;
        std::vector<int> temp;
        temp.resize(n);
        int j = 0;
        for (int i = 0; i < n - 1; i++)
            if (nums[i] != nums[i + 1])
                temp[j++] = nums[i];
        temp[j++] = nums[n - 1];
        return j;
};

int main()
{
    std::vector<int> arr{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = arr.size();
    std::cout<< removeDuplicates(arr, n);
    return 0;
}
