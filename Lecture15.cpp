#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

// Question 1: Remove duplicates from sorted linked list
ListNode* deleteDuplicates(ListNode* head) {
    if(!head) {
        return head;
    }
    ListNode* temp = head;
    if(temp->next==NULL) {
        return head;
    }
    while(temp->next) {
        if(temp->val == temp->next->val) {
            temp->next=temp->next->next;
        } else {
            temp=temp->next;
        }
    }
    return head;
}

// Question 2: Remove duplicates from unsorted linked list
ListNode * removeDuplicates(ListNode *head) {
    unordered_set<int> s;
    ListNode *temp = head;
    ListNode *post = head->next;
    s.insert(temp->val);
    while(post != NULL) {
        if(s.count(post->val)) {
            temp->next = post->next;
            post = post->next;
            continue;
        }
        s.insert(post->val);
        temp = temp->next;
        post = post->next;
    }
    return head;
}

// Question 3: Rotate linked list
ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL) return NULL;
    ListNode* temp = head;
    int cnt=0;
    while(temp!=NULL) {
        temp = temp->next; cnt++;
    }
    temp = head;
    k %= cnt;
    while(k--) {
        temp = temp->next;
    }
    ListNode* curr = head;
    while(temp->next!=NULL) {
        curr=curr->next;
        temp=temp->next;
    }
    temp->next=head;
    head = curr->next;
    curr->next=NULL;
    return head;
}

// Question 4: Add two numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy=new ListNode();
    ListNode* temp=dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry){
        int sum=0;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        ListNode* newnode=new ListNode(sum%10);
        temp->next=newnode;
        temp=temp->next;
    }
    return dummy->next;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 5};

    ListNode* list = createLinkedList(arr);
    cout << "List : ";
    printLinkedList(list);
    cout<<"Remove Linked List from sorted list: ";
    ListNode* res = deleteDuplicates(list);
    printLinkedList(res);
    
    arr = {1,2,4,5,1,2,6,5,3,2,4,1,5,2,1,3};
    list = createLinkedList(arr);
    cout<<"Remove Duplicates from unsorted list: ";
    res = removeDuplicates(list);
    printLinkedList(res);
    
    arr = {1,2,3,4,5,6,7,8,9};
    list = createLinkedList(arr);
    res = rotateRight(list, 3);
    cout<<"Rotated linked list: ";
    printLinkedList(res);
    
    arr = {1,2,3};
    list = createLinkedList(arr);
    vector<int> arr1 = {9,9,9};
    ListNode* list1 = createLinkedList(arr1);
    cout<<"Add two numbers: ";
    res = addTwoNumbers(list, list1);
    printLinkedList(res);
    
    return 0;
}
