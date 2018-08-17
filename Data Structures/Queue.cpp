#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;

};

struct Queue{
    node* head=NULL;
    node* tail=NULL;

    void enqueue(int x){
        node* tmp= (node*) malloc(sizeof(node));

        tmp->val= x;
        tmp->next= NULL;

        if(tail==NULL){
            head=tail=tmp;
            return;
        }

        tail->next= tmp;
        tail= tmp;

    }

    void dequeue(){
        if(head==NULL)
            return;

        node *tmp= head;
        head= head->next;

        if(head==NULL)
            tail=NULL;
    }

    int get_front(){
        if(head==NULL)
            return -1;

        return head->val;
    }

    void print(){
        node* t= head;

        while(t!=NULL){
            printf("%d ",t->val);
            t=t->next;
        }
        puts("");
    }
};
main(){
    int opt,x;
    Queue q;

    while(true){
        puts("Enter 1 to enqueue, 2 to dequeue, 3 to get front, 0 to print:");
        cin>>opt;

        if(opt==1){
            cin>>x;
            q.enqueue(x);
        }

        if(opt==2){
            q.dequeue();
        }

        if(opt==3){
            int fronts= q.get_front();
            cout<<fronts<<endl;
        }

        if(opt==0){
            q.print();
        }


    }
}




