#include <iostream>
#include<stdlib.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
void insert_f(Node *&head,int a)
{   Node *newnode=new Node();
    newnode->next=head;
    newnode->data=a;
    if(head==NULL)
    {
        head=newnode;
        head->next=head;   
    }
    else{
        Node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        head=newnode;
    }
}
void insert_l(Node *&head,int a)
{
    Node *newnode=new Node();
    newnode->next=head;
    newnode->data=a;
    if(head==NULL)
    {
        head=newnode;
        head->next=head;
    }
    else{
        Node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;     
    }
}
void insert_m(Node *head,int a,int p){
int count=0;
Node *newnode=new Node();
newnode->data=a;
Node *temp=head,*xtemp;
if(head==NULL)
{
    insert_l(head,a);
}
else if(p==0)
{
insert_f(head,a);
}
else{
while(count<p-1)
{
    if(temp->next==head)
    {
        break;
    }
temp=temp->next;
count++;
}
xtemp=temp->next;
temp->next=newnode;
newnode->next=xtemp;
}
}
void delete_f(Node *&head)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else if(head==head->next)
    {
        free(head);
    }
    else{
        Node *temp=head;
        
        while(temp->next!=head)
        {
            temp=temp->next;
        }       
        temp->next=head->next;
         temp=head;
        head=head->next;
        
        free(temp);
        
    }
}
void delete_l(Node *&head)
{
     if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else if(head==head->next)
    {  Node *temp=head;
        head=NULL;
        free(temp);
    }
    else{
    Node *temp=head,*xtemp;
    while(temp->next!=head)
    {
         xtemp=temp;
         temp=temp->next;  
    }
    xtemp->next=head;
    free(temp);
    }
}
void delete_m(Node *head,int p)
{
   if(head==NULL)
   {
    cout<<"List is empty"<<endl;
   } 
   else if(head== head->next)
   {
    Node *temp=head;
    head=NULL;
    free(temp);
   }
   else
   {
    Node *xtemp,*temp=head;
    for(int i=0;i<p;i++)
    {
        xtemp=temp;
        temp=temp->next;
        if(xtemp->next==head)
        {
            cout<<"invalid position"<<endl;
            break;
        }
    }
    xtemp->next=temp->next;
    free(temp);
   }
}
void search(Node *head,int a)
{
    Node *temp=head;
    int count=0,b=0;
   if(head==NULL)
   {
    cout<<"no element";
   }
    while(temp->next!=head)
    {
        if(temp->data==a)
        {
            cout<<"found at index: "<<b<<endl;
            count++;
        }
        temp=temp->next;
        b++;
    }
    if(temp->data==a)
    { 
        cout<<"found at index "<<b<<endl;
        count++;
    }
    if(count==0)
    {
        cout<<"not founded"<<endl;
    }
    
}
void sort(Node *&head)
{
    int count=1;
    if(head==NULL)
    {
        cout<<"no element in the list"<<endl;
    }
    else if(head==head->next)
    {
        cout<<head->data<<endl;
    }
    else
    {
        Node *temp=head,*xtemp;
        while(temp->next!=head)
        {
            count++;
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<count;i++)
        {   xtemp=temp->next;
            for(int j=i+1;j<count;j++)
            {
                if(temp->data>xtemp->data)
                {
                    int a=xtemp->data;
                    xtemp->data=temp->data;
                    temp->data=a;
                }
                xtemp=xtemp->next;
            }
            temp=temp->next;
        }
    }
}
void reverse(Node *&head)
{
    if(head==NULL)
    {
        cout<<"no element in the list"<<endl;
    }
    else if(head==head->next)
    {
        cout<<head->data<<endl;
    }
    else
    {
        Node *temp=head,*xtemp;
        int count=1;
        while(temp->next!=head)
        {
            count++;
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<count/2;i++)
        {
            xtemp=head;
            for(int j=0;j<count-i-1;j++)
            {
                xtemp=xtemp->next;
            }
            int a=temp->data;
            temp->data=xtemp->data;
            xtemp->data=a;
            temp=temp->next;
        }
    }
}
void display(Node *&head)
{
    Node *temp=head;
      if(head==NULL)
      {
        cout<<"no element in list"<<endl;

      }
      else{
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
      }
}
int main()
{
    int n;
    Node *head=NULL;
    while(1)
    {   system("cls");
        cout<<"1: enter element from front"<<endl;
        cout<<"2: enter element from last"<<endl;
        cout<<"3: enter element from mid"<<endl;
        cout<<"4: delete from front"<<endl;
        cout<<"5: delete from last"<<endl;
        cout<<"6: delete from mid"<<endl;
        cout<<"7: searching"<<endl;
        cout<<"8: sort"<<endl;
        cout<<"9: reverse"<<endl;
        cout<<"10: Display"<<endl;
        cout<<"11: exit"<<endl;
        
        cout<<"Enter your choice: ";
        cin>>n;

        switch(n)
        {
            case 1:
            {
                int a;
                cout<<"enter the value: ";
                cin>>a;
                insert_f(head,a);
                break;
            }
            case 2:
            {
                int a;
                cout<<"enter the value: ";
                cin>>a;
                insert_l(head,a);
                break;
            }
            case 3:
            {
                int a,p;
                cout<<"enter the value: ";
                cin>>a;
                cout<<"enter the position begin from 0: ";
                cin>>p;
                insert_m(head,a,p);
                break;
            }
            case 4:
            {
                delete_f(head);
                system("pause");
                break;
            }
            case 5:
            {
                delete_l(head);
                system("pause");
                break;
            }
            case 6:
            { 
                int p;
                cout<<"enter the position begin from 0";
                cin>>p;
                delete_m(head,p);
                system("pause");
                break;
            }
            case 7:
            {
                int a;
                cout<<"enter the element to search: ";
                cin>>a;
                search(head,a);
                system("pause");
                break;
            }
            case 8:
            {
                sort(head);
                system("pause");
                break;
            }
            case 9:
            {
                reverse(head);
                system("pause");
                break;
            }
            case 10:
            {
                display(head);
                system("pause");
                break;
            }
            case 11:
            {
                exit(1);
            }
           default:
            {
                cout<<"invalid input"<<endl;
            }
        }
    }
    return 0;
}