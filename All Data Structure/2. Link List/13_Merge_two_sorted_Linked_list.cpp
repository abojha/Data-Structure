#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
struct Node  *Create_a_Linked_list(int &n)
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *p = NULL;

    for(int i = 0; i < n; i++)
    {
        int x;
        cout<<"Enter the data";
        cin>>x;
        temp = new struct Node();
        temp->data = x;
        temp->next = NULL;
        
        if(head == NULL){
            head = temp;
        }
        else{
            p = head;
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
           

        }
        
    }
    return head;
}
void Print(struct Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        cout<<"\n";
        head = head->next;
    }
}
struct Node *Merge_two_sorted_Linked_list(struct Node *a, struct Node *b)
{
    struct Node *result = NULL;
    if(a==NULL)
    return b;
    if(b==NULL)
    return a;
   
    if(a->data<=b->data)
    {
        result = a;
        result->next = Merge_two_sorted_Linked_list(a->next,b);
    }
    else{
        result = b;
        result->next = Merge_two_sorted_Linked_list(b->next,a);
    }
    return result;
}
struct Node *Merge_two_sorted_Linked_list_without_recursion(struct Node *a, struct Node *b)
{
    struct Node *NewNode;
    NewNode = new struct Node();
    struct Node * temp;
   
    NewNode->next = NULL;
     temp = NewNode;
    while(a!=NULL&&b!=NULL)
    {
        if(a->data<=b->data)
        {
            temp->next = a;
            temp = temp->next;
            a = a->next;
        }
        else
        {
            temp->next = b;
            temp = temp->next;
            b = b->next;
        }
  }
  while(a!=NULL)
  {
      temp->next = a;
  }
  while(b!=NULL)
  {
      temp->next = b;
  }
  temp = NewNode->next;
  free(NewNode);
  return temp;
}
int main()
{
    int n,m;
    struct Node *head1;
    struct Node *head2;
    struct Node *merge;
    cout<<"Enter the size of linked list\n";
    cin>>n;
    cin>>m;
    head1 = Create_a_Linked_list(n);
    head2 = Create_a_Linked_list(m);
    //merge = Merge_two_sorted_Linked_list(head1,head2);
    merge = Merge_two_sorted_Linked_list_without_recursion(head1, head2);
    Print(merge);
    
    
    return 0;
}