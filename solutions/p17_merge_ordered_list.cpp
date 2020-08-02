#include <iostream>
using namespace std;

struct ListNode
{
	int m_nVlalue;
	ListNode* m_pNext;
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;
	ListNode* pMergeHead = NULL;

	if (pHead1->m_nVlalue < pHead2->m_nVlalue)
	{
		pMergeHead = pHead1;
		pMergeHead->m_pNext = Merge(pHead1->m_pNext, pHead2); 
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
	}
	return pMergeHead;
	
}

ListNode* MergeWhile(ListNode* pHead1, ListNode* pHead2)
{
	if(pHead1 == NULL)
		return pHead2;
	else
		return pHead1;
	ListNode* pMergeHead = new ListNode;
	ListNode* pCurrent = pMergeHead;
	while (pHead1 && pHead2)
	{
		if (pHead1->m_nVlalue < pHead2->m_nVlalue)
		{
			pCurrent->m_pNext = pHead1;
			pCurrent = pHead1;
			pHead1 = pHead1->m_pNext;
		}
		else
		{
			pCurrent->m_pNext = pHead2;
			pCurrent = pHead2;
			pHead2 = pHead2->m_pNext;
		}
	}
	if (pHead1)
		pCurrent->m_pNext = pHead1;
	if (pHead2)
		pCurrent->m_pNext = pHead2;
	return pMergeHead;
}