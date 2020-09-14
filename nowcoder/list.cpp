#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int val):val(val), next(nullptr){}
};

ListNode* find(ListNode* head, int x) {
    auto p = head;
    while (p) {
        if (p->val == x) break;
        p = p->next;
    }
    return p;
}

ListNode* remove(ListNode* head, int val) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    auto cur = head, pre = dummy;
    while (cur) {
        if (cur->val == val) {
            pre->next = cur->next;
            cur = pre->next;
        } else pre = cur, cur = cur->next;
    }
    return dummy->next;
}

int main() {
    int n, val;
    cin >> n >> val;
    ListNode *head = new ListNode(val);
    
    int t = n;
    while (--t) {
        int a, b;
        cin >> a >> b; // b->a
        auto p = find(head, b), q = p->next;
        p->next = new ListNode(a);
        p->next->next = q;
    } 
    
    //for (auto p = head; p; p=p->next) cout << p->val << ' ';
    //cout << endl;
    
    while(cin >> val) head = remove(head, val);
    while (head) cout << head->val << ' ', head = head->next;
    return 0;
}