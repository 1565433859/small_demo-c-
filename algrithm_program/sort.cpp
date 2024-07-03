#include "sort.h"
#include<stack>
void heap_sort(vector<int>& nums)
{
    create_heap(nums);
    for (int i = 0; i < nums.size() - 1; i++) {
        swap(nums[0], nums[nums.size() - 1 - i]);
        heap_adjust(nums, 0, nums.size() - i - 1);
    }
}

void create_heap(vector<int>& input)
{
    for (int i = (input.size() / 2 - 1); i >= 0; i--) {
        heap_adjust(input, i, input.size());
    }
}

void heap_adjust(vector<int>& nums, int index,int size)
{
    int tmp = nums[index];
    int flag = index;
    int child = index * 2 + 1;
    while (child<size) {
        if ((child + 1) < size && nums[child + 1] > nums[child])child++;
        if (tmp < nums[child])nums[flag]=nums[child];
        else {
            break;
        }
        flag = child;
        child = child * 2 + 1;
    }
    nums[flag] = tmp;
}

void quick_sort(vector<int>& nums, int begin, int end)
{
    if (begin < end) {
        int pivot = partion(nums, begin, end);
        quick_sort(nums, begin, pivot - 1);
        quick_sort(nums, pivot+1, end);
    }
}

int partion(vector<int> &nums, int begin, int end)
{
    int tmp = nums[begin];
    while (end > begin) {
        while (end > begin && nums[end] >= tmp)end--;
        swap(nums[begin], nums[end]);
        while (end > begin && nums[begin] <= tmp)begin++;
        swap(nums[begin], nums[end]);
    }
    nums[begin] = tmp;
    return begin;
}

void quick_sort2(vector<int>& nums, int begin, int end)
{
    stack<int>st;
    st.push(end);
    st.push(begin);
    while (!st.empty()) {
        int left = st.top();
        st.pop();
        int right = st.top();
        st.pop();

        int pivot = partion(nums, left, right);
        if (right - pivot > 1) {
            st.push(right);
            st.push(pivot+1);
        }
        if (pivot - left > 1) {
            st.push(pivot-1);
            st.push(left);
        }
    }
}


