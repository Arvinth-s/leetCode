//OM NAMO NARAYANA
//https://leetcode.com/problems/copy-list-with-random-pointer/submissions/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    Node* copyRandomList(Node* head) {
       if(!head)return NULL;
        unordered_map<Node*, Node*> eq;
        Node *res=new Node(head->val);
        Node *crawl = head->next, *crawl2 = res;
        eq[head]=res;
        while(crawl){
            crawl2->next = new Node(crawl->val);
            eq[crawl]=crawl2->next;
            crawl=crawl->next;
            crawl2=crawl2->next;
        }
        crawl=res;
        while(head){
            if(head->random)
                crawl->random = eq[head->random];
            else crawl->random = NULL;
            head=head->next;
            crawl=crawl->next;
        }
        return res;
    }
};