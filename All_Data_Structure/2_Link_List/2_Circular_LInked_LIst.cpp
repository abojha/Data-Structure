#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};

void print(struct Node *head)
{
    struct Node *p;
    p = head;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p!=head);
    cout<<endl;
}
struct Node *Insertion_At_begin(struct Node *head, int data)
{
    struct Node *p;
    struct Node *q;
    p = new struct Node();
    p->data = data;
    
    while(q->next!= head)
    {
        q = q->next;
    }
    q->next = p;
    p->next = head;
    head = p;
    return head;
}
struct Node *Insertion_At_index(struct Node *head, int data, int index)
{
    struct Node *Mover;
    Mover = head;
    
    struct Node * New_Node;
    New_Node = new struct Node();
    New_Node->data = data;
   
    int i = 0;
    while(i != index-1)
    {
        Mover = Mover->next;
        i++;
    }
    New_Node->next = Mover->next;
    Mover->next = New_Node;
    return head;

}
struct Node *Insertion_At_End(struct Node *head, int data)
{
    struct Node *Mover;
    struct Node *New_Node;
    New_Node = new struct Node();
    Mover = head;
    New_Node->data = data;

    while(Mover->next != head)
    {
        Mover = Mover->next;
    }
    New_Node->next = Mover->next;
    Mover->next = New_Node;
    return head;

}
struct Node *DeletionAtBegin(struct Node *head)
{
    struct Node *helper_Node;
    struct Node *Mover;
    helper_Node = head->next;
    Mover = head;
    while(Mover->next!=head)
    {
        Mover = Mover->next;
    }
    Mover->next = helper_Node;
    head = helper_Node;
    free(Mover);
    free(helper_Node);
    return head;

}
struct Node *DeletionAtEnd(struct Node *head)
{
    struct Node *Mover1;
    struct Node *Mover2;
    Mover1 = head;
    Mover2 = head->next;

    while(Mover2->next!=head)
    {
        Mover1 = Mover1->next;
        Mover2 = Mover2->next;
    }
    Mover1->next = Mover2->next;
    free(Mover2);
    return head;
}
struct Node *DeletionAtIndex(struct Node *head,int index)
{
    struct Node *Mover1;
    struct Node *Mover2;
    Mover1 = head;
    Mover2 = head->next;
    int i = 0;
    while(i!=index-1)
    {
        Mover1 = Mover1->next;
        Mover2 = Mover2->next;
        i++;
    }
    Mover1->next = Mover2->next;
    free(Mover2);
    return head;
} 

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = new struct Node();
    second = new struct Node();
    third = new struct Node();
    fourth = new struct Node();

    head->data = 12;
    head->next = second;

    second->data = 13;
    second->next = third;

    third->data = 14;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = head;


    print(head);
    //head = Insertion_At_begin(head,100);
    //head = Insertion_At_index(head,100,2);
    //head = Insertion_At_End(head,100);
    //head = DeletionAtBegin(head);
    //head = DeletionAtEnd(head);
    head = DeletionAtIndex(head,2);
    print(head);

    return 0;
}