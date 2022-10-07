#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *pre;
};
void insert_f(Node *&head,int a)
{
    Node *newnode=new Node();
    newnode->data=a;
    newnode->pre=NULL;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
    }
    else{
        newnode->next=head;
        head->pre=newnode;
        head=newnode;
    }
}
void insert_l(Node *&head,int a)
{
    Node *newnode=new Node();
    newnode->data=a;
    newnode->next=NULL;
    if(head==NULL)
    {
        newnode->pre=NULL;
        head=newnode;
    }
    else{
        Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->pre=temp;
    }
}
void insert_m(Node *&head,int a,int p)
{
    Node *newnode=new Node();
    newnode->data=a;
    if(head==NULL && p==0)
    {
        insert_f(head,a);
    }
    else if(head==NULL && p!=0)
    {
        cout<<"invalid"<<endl;
    }
    else if(p==0)
    {
        insert_f(head,a);
    }
    else{
        int i=0;
        Node *temp=head,*xtemp=NULL;
        while(i<p-1)
        {
            if(temp->next==NULL)
            { 
                cout<<"invalid input"<<endl;
                system("pause");
                break;
            }
            temp=temp->next;
            i++;
        }
        if(temp!=NULL)
        {
        newnode->pre=temp;
        xtemp=temp->next; 
        newnode->next=xtemp;
        temp->next=newnode;
        xtemp->pre=newnode; 
        }
    }
}
void delete_f(Node *&head)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else if(head->next==NULL)
    {
        Node *temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        Node *temp=head;
        head=head->next;
        head->next=NULL;
        free(temp);
    }
}
void delete_l(Node *&head)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else if(head->next==NULL)
    {
        Node *temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        Node *temp=head,*xtemp=NULL;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        xtemp=temp->pre;
        xtemp->next=NULL;
        free(temp);
    }
}
void delete_m(Node *&head,int p)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else{
        Node *temp=head,*xtemp=NULL,*ytemp=NULL;
        int i=0;
        while(i<p-1)
        {
            temp=temp->next;
            i++;
        }
        if(temp==NULL)
        {
            cout<<"invalid input"<<endl;
        }
        else{
        xtemp=temp->next;
        if(xtemp->next==NULL)
        {
            temp->next=NULL;
            free(xtemp);
        }       
        else{
        ytemp=xtemp->next;
        temp->next=ytemp;
        ytemp->pre=temp;
        free(xtemp);
        }
        }
    }
}
void search(Node *&head,int a)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else{
        Node *temp=head;
        int count=0;
        while(temp!=NULL)
        {
            if(temp->data==a)
            {
                cout<<"found at index: "<<count<<endl;
                count++;
            }
            temp=temp->next;
        }
    }
}
void sort(Node *&head)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else{
        Node *temp=head,*xtemp=NULL;
        while(temp->next!=NULL)
        {
            xtemp=temp->next;
            while(xtemp!=NULL)
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
        cout<<"list is empty"<<endl;
    }
    else if(head->next==NULL)
    {
     cout<<"only one element"<<endl;
    }
    else{
        Node *temp=head,*xtemp=NULL;
        while(temp!=NULL)
        {
           xtemp=temp->pre;
           temp->pre=temp->next;
           temp->next=xtemp;
           temp=temp->pre;
        }
        temp=head;
        while(temp->pre!=NULL)
        {
            temp=temp->pre;
        }
        head=temp;
    }
}
void display(Node *&head)
{
   
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
         Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    }
}
int main()
{
    int n;
    Node *head=NULL;
    while(1)
    {  
        system("cls");
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
                system("pause");
            }
        }
    }
    return 0;
}