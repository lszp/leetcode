/*
p23 合并K个有序链表

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

思路：

使用归并+递归实现，时间复杂度降低不少
*/

#include <iostream>
#include <vector>

using namespace std;


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() < 1) return nullptr;
		return merge2List(lists, 0, lists.size() - 1);
    }

	ListNode* merge2List(vector<ListNode*>& lists, int start, int end)
	{
		if (start == end) return lists[start];
		ListNode* l1 = merge2List(lists, start, (start + end) / 2);
		ListNode* l2 = merge2List(lists, (start + end) / 2 + 1, end);
		return merge(l1, l2);
	}

	ListNode* merge(ListNode* l1, ListNode* l2)
	{
		if (!l1) return l2;
		if (!l2) return l1;
		if(l1->val <= l2->val)
		{
			l1->next = merge(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = merge(l1, l2->next);
			return l2;
		}
		
	}
};

int main()
{

}