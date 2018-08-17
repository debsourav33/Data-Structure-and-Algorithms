#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;

};

void print(node* head){
    node *t= head;

    while(t!=NULL){
        printf("%d ",t->val);
        t=t->next;
    }
    puts("");

}

node* insert_first(int x, node* head){
    node* temp= (node*) malloc(sizeof(node));

    temp->val=x;
    temp->next= head;
    head=temp;

    return head;
}

node* insert_last(int x, node* head){
    node* temp= (node*) malloc(sizeof(node));
    node* t= head;

    temp->val= x;
    temp->next= NULL;

    if(head==NULL){
        head= temp;
        return head;
    }

    while(t->next!=NULL){
        t=t->next;
    }

    t->next= temp;
    return head;

}

node* delet(int x, node* head){
    node* t= head;

    if(head==NULL)
        return head;

    if(head->val==x){
        head= head->next;
        return head;
    }

    while(t->next!=NULL && t->next->val!=x){
        t=t->next;
    }

    if(t->next==NULL){
        cout<<"No such element found to delete"<<endl;
        return head;
    }

    t->next= t->next->next;
    return head;

}

main(){
    node* head= NULL;
    int opt,x;

    while(true){
        puts("Enter 1 to insert_first, 2 to insert_last, 3 to delete, 0 to print:");
        cin>>opt;

        if(opt==1){
            cin>>x;
            head= insert_first(x,head);
        }

        if(opt==2){
            cin>>x;
            head= insert_last(x,head);
        }

        if(opt==3){
            cin>>x;
            head= delet(x,head);
        }

        if(opt==0){
            print(head);
        }


    }
}
