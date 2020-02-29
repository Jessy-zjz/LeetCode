/*
删除链表的倒数第N个节点

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表 : 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：

给定的 n 保证是有效的。#include<iostream>

// Definition for singly-linked list.
 struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* p = head;
		ListNode* q = head;

		while (n != 1)
		{
			p = p->next;
			--n;
		}
		if (p->next == nullptr)
		{
			ListNode* newHead = head->next;
			delete head;
			return newHead;
		}
		else
		{
			ListNode* pre = head;
			while (p->next != NULL)
			{
				pre = q;
				q = q->next;
				p = p->next;
			}
			pre->next = q->next;
			return head;
		}
	}
};
int main()
{
	ListNode* L = new ListNode(1);
	L->next = new ListNode(2);
	L->next->next = new ListNode(3);
	L->next->next->next = new ListNode(4);
	L->next->next->next->next = new ListNode(5);
	ListNode*head = Solution().removeNthFromEnd(L, 1);

	for (ListNode* it = head; it != nullptr; it = it->next)
		printf(" %d ->", it->val);
}*/
#include<iostream>
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* l3 = nullptr;
		if (l1 == nullptr && l2 == nullptr)
			return nullptr;
		else if (l1 == nullptr && l2 != nullptr)
		{
			return l2;
		}
		else if (l1 != nullptr && l2 == nullptr)
		{
			return l1;
		}
		else if (l1->val > l2->val)
		{
			l3 = l2;
			l2 = l2->next;
		}
		else
		{
			l3 = l1;
			l1 = l1->next;
		}

		ListNode* r = l3;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val < l2->val)
			{
				r->next = l1;
				r = r->next;
				l1 = l1->next;
			}
			else
			{
				r->next = l2;
				r = r->next;
				l2 = l2->next;
			}
		}
		if (l1 != nullptr)  r->next = l1;
		if (l2 != nullptr)  r->next = l2;
		return l3;
	}
};
//135
//2469
//12345 69

int main()
{
	Solution a;
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);
	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	ListNode* res = a.mergeTwoLists(l1, l2);
	while (res != nullptr)
	{
		std::cout << res->val;
		res = res->next;
	}
	return 0;
}