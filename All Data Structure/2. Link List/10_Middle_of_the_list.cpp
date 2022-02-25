#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
void display(struct Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}
struct Node *Creation(int &n)
{
    struct Node *head=NULL;
    struct Node *temp=NULL;
    struct Node *p=NULL;
    //creation of temporary Node
    for(int i = 0; i<n; i++)
    {
        cout<<"Enter the data of Node"<<i+1<<endl;;
        int x;
        cin>>x;
        temp = new struct Node();
        temp->data=x;

        if(head==NULL)
        {
            head = temp;
        }
        else{
            p = head;
            while(p->next!=NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}
struct Node *find_Middle_of_the_list(struct Node *head)
{
    struct Node *slowptr;
    struct Node *fastptr;
    slowptr = head;
    fastptr = head;
    int i = 0;
    while(fastptr->next!=NULL)
    {
        // if(i==0)
        // {
        //     fastptr=fastptr->next;
        //     i = 1;
        // }
        // if(i==1)
        // {
        //     slowptr = slowptr->next;
        //     fastptr = fastptr->next;
        //     i=0;
        // }
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
    }
    return slowptr;
}
int main()
{
    struct Node *head;
    struct Node *ptr;
    
    head = NULL;
    int N;
    cout<<"How many Nodes:\n";
    cin>>N;
    head = Creation(N);
    display(head);
    ptr = find_Middle_of_the_list(head);
    cout<<endl<<ptr->data;
    

    
    return 0;
}