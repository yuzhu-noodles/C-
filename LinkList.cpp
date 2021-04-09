#include<iostream>
using namespace std;

typedef struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int _val):val(_val),next(NULL){}
}LinkList;

LinkList* Merge(LinkList* l1,LinkList* l2)
{
	if(!l1)
		return l2;
	if(!l2)
		return l1;
	LinkList* ret = new LinkList(0);
	LinkList* p = ret;
	while(l1 != NULL && l2 != NULL)
	{
		if(l1->val < l2->val)
		{
			p->next = l1;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
		if(!l1)
			p->next = l2;
		if(!l2)
			p->next = l1;
	}
	return ret->next;
}

//链表反转
LinkList* Reverse(LinkList* L)
{
	if(!L)
		return NULL;
	LinkList* pre = new LinkList(0);
	LinkList* cur = new LinkList(0);
	pre = L;
	cur = L->next;
	pre->next = NULL;
	LinkList* temp = new LinkList(0);
	while(cur != NULL)
	{
		temp = cur;
		cur = cur->next;
		temp->next = pre;
		pre = temp;
	}
	return pre;
}

int main()
{
	LinkList* node1 = new LinkList(1);
	LinkList* node2 = new LinkList(2);
	LinkList* node3 = new LinkList(4);
	LinkList* node4 = new LinkList(6);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	LinkList* node5 = new LinkList(3);
	LinkList* node6 = new LinkList(5);
	node5->next = node6;
	node6->next = NULL;
    LinkList* ret = Merge(node1,node5);
	while(ret != NULL)
	{
		cout<<ret->val<<"->";
		ret =ret->next;
	}
	cout<<endl;
	//反转链表
	cout<<"反转链表"<<endl;
	LinkList* ret1 = Reverse(ret);
	while(ret1 != NULL)
	{
		cout<<ret1->val<<"->";
		ret1 = ret1->next;
	}
	cout<<endl;
	return 0;
}



