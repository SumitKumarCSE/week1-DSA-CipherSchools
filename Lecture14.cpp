#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
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
        cout << head->val;
        if (head->next) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

// Question 1: Merge two sorted linked list
ListNode* reverseKGroup(ListNode* head, int k) {
    int count=0;
    ListNode *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    ListNode *ans=head;
    if(count>=k){
        ListNode *curr=head,*prev=NULL,*next=head;
        int i=0;
        while(curr!=NULL && i<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        if(next!=NULL){
            ListNode *res=reverseKGroup(next,k);
            head->next=res;
        }
          ans=prev;
    }
    return ans;       
}

// Question 2: Find and remove loop
void removeLoop(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return;
    }
       
    ListNode *slow=head, *fast=head;
    ListNode *ptr1=head, *ptr2=NULL;
       
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            ptr2=slow;
            break;
        }
    }
    if(ptr2==NULL){
        return;
    }
       
    while(ptr1!=ptr2){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
       
    ListNode *temp=ptr1;
    while(temp->next!=ptr1){
        temp=temp->next;
    }
    temp->next=NULL;
}

// Question 3 : Intersection of 2 linked list
ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a = headA,*b = headB;
    while(a != b) {
        if(a == NULL) {
            a = headB;
        } else {
            a = a->next;
        }
        if(b == NULL) {
            b = headA;
        } else {
            b = b->next;
        }
    }
    return a;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    ListNode* list = createLinkedList(arr);
    cout << "List : ";
    printLinkedList(list);
    cout<<"Reverse List in K group: ";
    ListNode* revList = reverseKGroup(list, 3);
    printLinkedList(revList);
    cout<<endl;
    
    ListNode* start = list;
    while(start->next != NULL) {
        start = start->next;
    }
    start->next = list->next->next;
    cout<<"After remove loop: ";
    removeLoop(list);
    printLinkedList(list);
    cout<<endl;
    
    vector<int> arr1 = {1,2,3,4,5,6};
    ListNode* list1 = createLinkedList(arr1);
    ListNode* tmp = list1;
    while(tmp->val != 3) {
        tmp = tmp->next;
    }
    vector<int> arr2 = {1,2,3};
    ListNode* list2 = createLinkedList(arr2);
    ListNode* tmp1 = list2;
    while(tmp1->next != NULL) {
        tmp1 = tmp1->next;
    }
    tmp1->next = tmp;
    
    tmp = getIntersectionNode(list1, list2);
    cout<<"Intersection of linked list: ";
    printLinkedList(tmp);
    cout<<endl;
    
    return 0;
}
