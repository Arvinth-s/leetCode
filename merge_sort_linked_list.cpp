//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

/*
faster than 13%
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *find_mid(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *slow = head, *fast = head;
        while (fast->next && (fast->next)->next)
        {
            slow = slow->next;
            fast = (fast->next)->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *a, ListNode *b)
    {
        ListNode *head;
        if (!a || !b)
        {
            if (!a)
                return b;
            else
                return a;
        }
        if (a->val > b->val)
        {
            head = b;
            b = b->next;
        }
        else
        {
            head = a;
            a = a->next;
        }
        ListNode *buf = head;
        while (a && b)
        {
            if (a->val < b->val)
            {
                buf->next = a;
                buf = a;
                a = a->next;
            }
            else
            {
                buf->next = b;
                buf = b;
                b = b->next;
            }
        }

        while (a)
        {
            buf->next = a;
            buf = a;
            a = a->next;
        }

        while (b)
        {
            buf->next = b;
            buf = b;
            b = b->next;
        }

        return head;
    }

    ListNode *sort(ListNode *head)
    {
        if (!head)
            return NULL;
        if (!head->next)
            return head;

        ListNode *mid = find_mid(head);
        ListNode *a = head, *b = mid->next;

        mid->next = NULL;
        a = sort(a);
        b = sort(b);

        return merge(a, b);
    }

    ListNode *sortList(ListNode *head)
    {
        return sort(head);
    }
};