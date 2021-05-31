//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

/*
#try1 #linkedlist #100q #medium 
faster than 100%

*/


//  * Definition for singly-linked list.
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *follower = head, *leader = head;
        for (int i = 0; i < n; i++)
            leader = leader->next;

        if (!leader)
        {
            head = head->next;
            return head;
        }

        while (leader->next)
        {
            leader = leader->next;
            follower = follower->next;
        }
        follower->next = (follower->next)->next;
        return head;
    }
};