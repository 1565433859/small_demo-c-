#pragma once
#include<vector>

using namespace std;

void heap_sort(vector<int>&nums);

void create_heap(vector<int>& nums);

void heap_adjust(vector<int>& nums, int size,int index);

void quick_sort(vector<int>& nums,int begin,int end);

int partion(vector<int>&nums, int begin, int end);

void quick_sort2(vector<int>& nums, int begin, int end);