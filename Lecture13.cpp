#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Question 1: Merge two sorted linked list
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    } else if (list2 == nullptr) {
        return list1;
    }

    ListNode* head = nullptr;
    if (list1->val <= list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }

    ListNode* finalList = head;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            head->next = list1;
            list1 = list1->next;
        } else if (list1->val > list2->val) {
            head->next = list2;
            list2 = list2->next;
        }
        head = head->next;
    }

    if (list1 == nullptr) {
        head->next = list2;
    } else if (list2 == nullptr) {
        head->next = list1;
    }
    return finalList;
}

ListNode* createLinkedList(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout<<endl;
}

// Question 2: Merge k sorted linked lists
ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<pair<int, ListNode*>> v;
    int n = lists.size();
    if (n == 0) return NULL;
    if (n == 1) return lists[0];
    for (int i = 0; i < n; i++) {
        if (lists[i] == NULL) continue;
        ListNode* head = lists[i];
        while (head) {
            v.push_back({head->val, head});
            head = head->next;
        }
    }
    if (v.size() == 0) return NULL;
    sort(v.begin(), v.end());
    ListNode* head = v[0].second, *temp = v[0].second;
    for (int i = 0; i < v.size() - 1; i++) {
        temp->next = v[i + 1].second;
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

// Question 3 : Reverse a linked list
ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    ListNode* curr=head;
    ListNode* backward=NULL,*forward=NULL;
    while(curr!=NULL) {
        forward=curr->next;
        curr->next=backward;
        backward=curr;
        curr=forward;
    }
    return backward;
}

int main() {
    vector<int> arr1 = {1, 2, 4};
    vector<int> arr2= {1, 3, 4};

    ListNode* list1 = createLinkedList(arr1);
    ListNode* list2 = createLinkedList(arr2);
    cout << "List 1: ";
    printLinkedList(list1);
    cout << "List 2: ";
    printLinkedList(list2);

    ListNode* mergedList = mergeTwoLists(list1, list2);
    cout << "Merged List: ";
    printLinkedList(mergedList);
    cout<<endl;
    
    vector<int> arr4 = {1, 4, 5};
    vector<int> arr5 = {1, 3, 4};
    vector<int> arr6 = {2, 6};

    vector<ListNode*> lists;
    lists.push_back(createLinkedList(arr4));
    lists.push_back(createLinkedList(arr5));
    lists.push_back(createLinkedList(arr6));

    cout << "Input Lists:" << endl;
    for (const auto& list : lists) {
        printLinkedList(list);
    }

    ListNode* mergedList1 = mergeKLists(lists);

    cout << "Merged List: ";
    printLinkedList(mergedList1);
    cout<<endl;
    
    cout<<"Reversed Linked List: ";
    ListNode* rev = reverseList(mergedList1);
    printLinkedList(rev);

    return 0;
}
