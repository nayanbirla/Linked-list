#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
    public:
    int data;
    Node *pre;
    Node *next;
};
void insert_f(Node *&head,int a)
{
    Node *newnode=new Node();
    newnode->data=a;
    if(head==NULL)
    {
        head=newnode;
        head->next=head;
        head->pre=head;
    }
    else{
        newnode->next=head;
        head->pre=newnode;
        Node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->pre=temp;
        head=newnode;
    }
}
void insert_l(Node *&head,int a)
{
    if(head==NULL)
    {
        insert_f(head,a);
    }
    else{
        Node *newnode=new Node();
        newnode->data=a;
        head->pre=newnode;
        Node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->pre=temp;
        
        newnode->next=head;
      temp->next=newnode;
    }
}
void insert_m(Node *&head,int a,int p)
{ 
    if(head==NULL && p==0)
    {
        insert_f(head,a);
      //  count=1;
    }
    else if(head==NULL && p!=0)
    {
        cout<<"invalid"<<endl;
        system("pause");
     //   count=1;
    }
    else if(p==0)
    {
     //   count=1;
        insert_f(head,a);
        
    }
    else{
        int i=1;
         int count=0;
    Node *temp=head->next;
   
        while(i<p-1)
        {
            if(temp==head)
            {
                cout<<"invalid input"<<endl;
                system("pause");
                count=1;
                break;
            }
            temp=temp->next;
        }        
    if(count==1)
    {
         
    }
    else
    {
        Node *newnode=new Node();
        newnode->data=a;
        newnode->pre=temp;
        Node *xtemp=temp->next;
        temp->next=newnode;
        newnode->next=xtemp; 
    }
    }
}
void delete_f(Node *&head)
{
    if(head==NULL)
    {
        cout<<"empty list"<<endl;
    }
    else if(head==head->next)
    {
        Node *temp=head;
        head=NULL;
        free(temp);
    }
    else{
        Node *temp=head->next;
        temp->pre=head->pre;
        Node *xtemp=temp->pre;
        xtemp->next=temp;
        head=temp;
    }
}
void delete_l(Node *&head)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else if(head==head->next)
    {
        Node *temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        Node *temp=head;
        Node *xtemp=NULL;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        xtemp=temp->pre;
        free(temp);
        xtemp->next=head;
        head->pre=xtemp;
    }
}
void delete_m(Node *&head,int p)
{ 
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else if(head==head->next && p==0) 
    {
           delete_f(head);
    }
    else if(p==0)
    {
        delete_f(head);
    }
    else{
        Node *temp=head,*xtemp;
        int i=0,count=0;
        while(i<p-1)
        {
            i++;
            temp=temp->next;
            if(temp==head)
            {
                count=1;
                break;
            }
        }
        if(count==1)
        {
            cout<<"invalid"<<endl;
        }
        else{
                xtemp=temp->next;
                temp->next=xtemp->next;
                free(xtemp);
        }
    }
    
}
void search(Node *&head,int a)
{  int count=0;
    Node *temp=head;
    while(temp->next!=head)
    {
        if(a==temp->data)
        {
            cout<<"founded at index: "<<count<<endl;
            count++;
        }
        else{
        count++;
        }

        temp=temp->next;
    }
    if(temp->data==a)
    {
        cout<<"founded at index: "<<count<<endl;
        count++;
        
    }

}
void sort(Node *head)
{
   if(head==NULL)
   {
    cout<<"list is empty"<<endl;
   }
   else{
    Node *temp=head,*xtemp=NULL;
    while(temp->next!=head)
    {
        xtemp=temp->next;
        while(xtemp!=head)
        {
            if(temp->data>xtemp->data)
            {
                int a=temp->data;
                temp->data=xtemp->data;
                xtemp->data=a;
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
        cout<<"list is empty";
     }
     else if(head==head->next)
     {

     }
     else{
    Node *temp=head,*xtemp;
    while(temp->next!=head)
    {
        xtemp=temp->pre;
        temp->pre=temp->next;
        temp->next=xtemp;
        temp=temp->pre;
    }
    xtemp=temp->pre;
    temp->pre=temp->next;
    temp->next=xtemp;
    head=temp;
     }
}

void display(Node *&head)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else{ 
    Node *temp=head;
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