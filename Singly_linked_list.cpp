#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
void insert_front(Node *&head,int a)
{
   Node *newnode= new Node();
   newnode->data=a;
   newnode->next=head;
   head=newnode;
}
void insert_last(Node *&head,int a)
{
    Node *newnode=new Node();
    newnode->data=a;
    newnode->next=NULL;
    
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
     Node *temp=head;
     while(temp->next!=NULL)
     {
       
        temp=temp->next; 
     }
     temp->next=newnode;   
    }
}
void insert_mid(Node *&head,int pos,int val)
{
    Node *temp=head;
    Node *pre;
    Node *newnode= new Node();
    newnode->data=val;
    int count=0;
    while(count<(pos-1))
    {
        temp=temp->next;
        count++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void delete_f(Node *&head)
{
    if(head==NULL)
    {
        cout<<"no element to delete from list"<<endl;
    }
    else
    {
        Node *temp;
        temp=head;
        head=temp->next;
        free(temp);
    }
}
void delete_l(Node *&head)
{
    Node *temp,*xtemp;
    if(head==NULL)
    {
        cout<<"no element to delete"<<endl;
    }
    else{
    temp=head;
    while(temp->next!=NULL)
    {   xtemp=temp;
        temp=temp->next;
    }
    xtemp->next=NULL;
    free(temp);
    }
}
void delete_mid(Node *&head,int pos)
{ 
    int count=0;
    Node *temp,*xtemp;
    temp=head;
    while(count<(pos-1))
    {
        temp=temp->next;
    }
    xtemp=temp->next;
    temp->next=xtemp->next;
    free(xtemp);
}
void search(Node *&head,int pos)
{
    int count=0;
    if(head==NULL)
    {
        cout<<"no value in your list"<<endl;
    }
    else
    {
        
        Node *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            if(pos==temp->data)
            {
                count++;
                cout<<"found"<<endl;
            
            }
            temp=temp->next;
        }
        if(count==0)
        {
            cout<<"value not found"<<endl;
        }
    }
}
void Display(Node *&head)
{  Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void sort(Node *&head)
{
    int a,count=0;
    Node *temp,*xtemp;
    temp=head;
    xtemp=head->next;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    temp=head;
    for(int i=0;i<count-1;i++)
    {
        for(int j=i+1;j<count;j++)
        {
            if(temp->data>xtemp->data)
            {
                a=temp->data;
                temp->data=xtemp->data;
                xtemp->data=a;
                xtemp=xtemp->next;
            }
        }
        temp=temp->next;
        xtemp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void reverse(Node *&head)
{
Node *current,*prev,*nex;
current=head;
nex=head;
prev=NULL;
try{
while(current !=NULL)
{
    nex=nex->next;
    current->next=prev;
    prev=current;
    current=nex;
    
   
}
}catch(exception ee)
{
    cout<<"exception occur";
}
head=prev;
Node *temp=head;
while(temp!=NULL)
{
    cout<<temp->data<<" ";
    temp=temp->next;
}
cout<<endl;
}n
int main()
{
    int n,a;
    Node *head=NULL;
    while(1)
    {
    system("cls");
    cout<<"1:insert from front"<<endl;
    cout<<"2:insert from last"<<endl;
    cout<<"3:insert from mid"<<endl;
    cout<<"4:Delete from front"<<endl;
    cout<<"5:Delete from last"<<endl;
    cout<<"6:Delete from mid"<<endl;
    cout<<"7:Display"<<endl;
    cout<<"8:search a number"<<endl;
    cout<<"9:sort list"<<endl;
    cout<<"10:reverse list"<<endl;
    cout<<"11:exit"<<endl;
    cout<<"enter the choice: ";
    cin>>n;
    int pos;
    switch(n)
    {
        case 1:
        {
           cout<<"enter the value: ";
           cin>>a;
           insert_front(head,a);
          // system("pause");
           break; 
        }
        case 2:
        {
            cout<<"enter the value: ";
            cin>>a;
            insert_last(head,a);
        //    system("pause");
            break;
        }
        case 3:
        {
            cout<<"enter the value: ";
            cin>>a;
            cout<<"enter the position begins from 0: ";
            cin>>pos;
            insert_mid(head,pos,a);
         //   system("pause");
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
            cout<<"enter the postition begins from 0: ";
            cin>>pos;
            delete_mid(head,pos);
            system("pause");
            break;
        }
        case 7:
        {
           system("cls");
            cout<<"Elements are:"<<endl;
            Display(head);
            system("pause");
            break;
        }
        case 8:
        {   cout<<"enter the value to search: ";
            cin>>pos;
            search(head,pos);
            system("pause");
            break;
        }
        case 9:
        {
            sort(head);
            system("pause");
            break;
        }
        case 10:
        {
            reverse(head);
            system("pause");
            break;
        }
        case 11:
        {   
            exit(1);
        }
       }
      }
    return 0;
}

