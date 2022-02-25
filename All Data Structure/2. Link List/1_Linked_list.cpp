#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
void print_a_linked_list(struct Node *head)
{
    struct Node *p;
    p = head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
struct Node * Insertion_At_Beginning(struct Node * head, int data)
{
    struct Node * p;
    p = new struct Node();
    p->data = data;
    p->next = head;
    return p;
}
struct Node * Insertion_at_Index(struct Node * head, int data, int index)
{
    struct Node *p;
    struct Node *q;
    p = new struct Node();
    q = new struct Node();
    q->data = data;
    p = head;
    int i = 0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    q->next = p->next;
    p->next = q;
    return head;
}
struct Node * Insertion_At_End(struct Node * head, int data)
{
    struct Node *p;
    struct Node *q;
    p = head;
    q = new struct Node();
    q->data = data;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q->next = NULL;
    return head;
}
struct Node * Deletion_at_Beginning(struct Node * head)
{
    struct Node *p;
    struct Node *q;
    p = new struct Node();
    q = new struct Node ();
    q = head;
    p =  q->next;
    free(q);
    return p;

}
struct Node * Deletion_at_Index(struct Node * head, int index)
{
    struct Node *p;
    struct Node *q;
    p = new struct Node();
    q = new struct Node ();
    p = head;
    q = head->next;
    for(int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
   
    return head;

}
struct Node * Deletion_at_End(struct Node * head)
{
    struct Node *p;
    struct Node *q;
    p = new struct Node();
    q = new struct Node ();
    p = head;
    q = head->next;
    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;

}

int main()
{
  struct Node *head;
  struct Node *second;
  struct Node *third;
  head = new Node();
  second = new Node();
  third = new Node();

  head->data = 5;
  head->next = second;

  second->data = 10;
  second->next = third;

  third->data = 15;
  third->next = NULL;

  print_a_linked_list(head);
  head = Insertion_At_Beginning(head,200);
  print_a_linked_list(head);
  head = Insertion_at_Index(head,200,2);
  print_a_linked_list(head);
  head = Insertion_At_End(head,200);
  print_a_linked_list(head);
  head = Deletion_at_Beginning(head);
  print_a_linked_list(head);
  head = Deletion_at_Index(head,1);
  print_a_linked_list(head);
   head = Deletion_at_End(head);
  print_a_linked_list(head);

    return 0;
}