#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}    
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* t1 = l1, * t2 = l2, * head = nullptr, * prev = nullptr;
    int num = 0;
    while (t1 || t2 || num) {
        num += (t1 ? t1->val : 0);
        num += (t2 ? t2->val : 0);

        ListNode* cur = new ListNode(num % 10);
        num /= 10;

        if (!head) head = cur;
        if (prev) prev->next = cur;
        prev = cur;

        if (t1) t1 = t1->next;
        if (t2) t2 = t2->next;
    }
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

//    ListNode a(2);
    ListNode c(3);
    ListNode b(4, &c);
//    ListNode d(5);
    ListNode f(4);
    ListNode e(6, &f);

    ListNode a(2, &b);
    ListNode d(5, &e);

    ListNode* answer = addTwoNumbers(&a, &d);

    return 0;
}
