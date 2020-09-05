#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
// struct Node* head;

void Insert(struct Node* head,int x)
{
    struct Node temp;
    temp.data = x;
    temp.next=head;
    head=&temp;
    // struct Node* temp=(Node*)malloc(sizeof(struct Node));
    // struct Node temp;
    // temp.data = x;
    // if(head!=NULL)
    //     temp.next = head;
    // else
    //     temp.next=NULL;
    // head = &temp;
    // return head;
}//;

void print(struct Node head)
{
    // struct Node* temp = head;
    printf("List is: ");
    // head = *head
    while(head.next!= NULL)
    {
        printf("%d -> ",head.data);
        head = *head.next;
    };
    printf("\n");
}//;

int main()
{
    struct Node* head=NULL;
    printf("How many numbers?  ");
    int x,i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the number  ");
        scanf("%d",&x);
        Insert(head,x);
        // print(head);
    }
    print(*head);
    return 0;
}



