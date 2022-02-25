#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *prevNode;
    struct Node *nextNode;
};

void printing(struct Node *head)
{
    struct Node *p;
    p = head;
    do{
        cout<<p->data<<" ";
        p = p->nextNode;
    }while(p->nextNode!=NULL);
    cout<<p->data;
    cout<<endl;
    do{
        
        cout<<p->data<<" ";
        p = p->prevNode;
    }while(p!=NULL);
    cout<<endl;
}

struct Node *InsertionAtBegin(struct Node *head, int data)
{
    struct Node *helper_Node;
    helper_Node->data = data;
    helper_Node = new struct Node();
    head->prevNode = helper_Node;
    helper_Node->nextNode = head;
    helper_Node->prevNode = NULL;
    head = helper_Node;
    return head;
}
struct Node *InsertionAtEnd(struct Node *head, int data)
{
    struct Node *helper_Node;
    helper_Node = new struct Node();
    struct Node *Mover;
    helper_Node->data = data;
    Mover = head;

    while(Mover->nextNode!=NULL)
    {
        Mover = Mover->nextNode;
    }
    helper_Node->nextNode = Mover->nextNode;
    Mover->nextNode = helper_Node;
    helper_Node->prevNode = Mover;
   
    return head;
}
struct Node *InsertionAtIndex(struct Node *head, int data, int index)
{
    struct Node *helper_Node;
    struct Node *Mover1,*Mover2;
    helper_Node = new struct Node();
    helper_Node->data = data;
    Mover1 = head;
    Mover2 = head->nextNode;
    int i = 0;
    while(i!=index-1)
    {
        Mover1 = Mover1->nextNode;
        Mover2 = Mover2->nextNode;
        i++;
    }
    helper_Node->nextNode = Mover1->nextNode;
    Mover1->nextNode = helper_Node;
    Mover2->prevNode = helper_Node;
    helper_Node->prevNode = Mover1;
    return head;

}
struct Node *InsertAfterNode(struct Node *head,int data,struct Node *p)
{
    struct Node *helper_Node;
    struct Node *auxillary_Node;
    auxillary_Node = new struct Node();
    auxillary_Node->data = data;
    helper_Node = p->nextNode;
    
    auxillary_Node->nextNode = p->nextNode;
    p->nextNode = auxillary_Node;
    auxillary_Node->prevNode = p;
    helper_Node->prevNode = auxillary_Node;
    return head;
}
struct Node *InsertAtThisNode(struct Node *head, int data, struct Node *p)
{
    struct Node *auxillary_Node;
    struct Node *helper_Node1;
    struct Node *helper_Node2;
    struct Node *helper_Node3;
    auxillary_Node = new struct Node();
    auxillary_Node->data = data;
    helper_Node1 = p;
    helper_Node2 = p->nextNode; 
    helper_Node3 = p->prevNode;

    helper_Node3->nextNode = auxillary_Node;
    auxillary_Node->nextNode = helper_Node1;
    helper_Node1->prevNode = auxillary_Node;
    auxillary_Node->prevNode = helper_Node3;
    return head;
}
struct Node *Delete_At_Begin(struct Node *head)
{
    struct Node *helper;
    struct Node *auxillary_Node;
    auxillary_Node = (struct Node *)malloc(sizeof(struct Node));
    helper = head;
    auxillary_Node = head->nextNode;
    auxillary_Node->prevNode = NULL;
    free(helper);
    head = auxillary_Node;
    return head;
}
struct Node *Delete_At_End(struct Node *head)
{
    struct Node *Mover1;
    struct Node *Mover2;
    Mover1 = head;
    Mover2 = head->nextNode;
    while(Mover2->nextNode != NULL)
    {
        Mover1 = Mover1->nextNode;
        Mover2 = Mover2->nextNode;
    }
    Mover1->nextNode = NULL;
    free(Mover2);
    return head;
}
struct Node *Delete_At_Index(struct Node *head, int index)
{
    struct Node *helper_Node1;
    struct Node *helper_Node2;
    struct Node *helper_Node3;
    helper_Node1 = head;
    helper_Node2 = head->nextNode;
    helper_Node3 = helper_Node2->nextNode;
    int i = 1;
    while(i != index-1)
    {
        helper_Node1 = helper_Node1->nextNode;
        helper_Node2 = helper_Node2->nextNode;
        helper_Node3 = helper_Node3->nextNode;
        i++;
    }
    helper_Node1->nextNode = helper_Node2->nextNode;
    helper_Node3->prevNode = helper_Node1;
    free(helper_Node2);
    return head;
}
struct Node *Delete_After_Node(struct Node *head, struct Node *p)
{
    struct Node *helper_Node1;
    struct Node *helper_Node2;
    helper_Node1 = p->nextNode;
    helper_Node2 = helper_Node1->nextNode;
    p->nextNode = helper_Node2;
    helper_Node2->prevNode = p;
    free(helper_Node1);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;

    head = new struct Node();
    second = new struct Node();
    third = new struct Node();
    fourth = new struct Node();
    fifth = new struct Node();
    sixth = new struct Node();

    head->data = 100;
    head->prevNode = NULL;
    head->nextNode = second;

    second->data = 200;
    second->prevNode = head;
    second->nextNode = third;

    third->data = 300;
    third->prevNode = second;
    third->nextNode = fourth;

    fourth->data = 400;
    fourth->prevNode = third;
    fourth->nextNode = fifth;

    fifth->data = 500;
    fifth->prevNode = fourth;
    fifth->nextNode = sixth;

    sixth->data = 600;
    sixth->prevNode = fifth;
    sixth->nextNode = NULL;

    printing(head);
    //head = InsertionAtBegin(head,99);
    //head = InsertionAtEnd(head,601);
    //head = InsertionAtIndex(head,302,2);
    //head = InsertAfterNode(head,5000,fifth);
    //head = InsertAtThisNode(head,2000,second);
    //head = Delete_At_Begin(head);
    //head  = Delete_At_End(head);
    //head = Delete_At_Index(head,2);
    head = Delete_After_Node(head,second);
    printing(head);
    return 0;
}