#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;

};

struct Stack{
    node* head= NULL;

    void push(int x){
        node* tmp= (node*) malloc(sizeof(node));

        tmp->val= x;
        tmp->next= head;
        head= tmp;

    }

    void pop(){
        if(head==NULL)
            return;

        node *tmp= head;
        head= head->next;
    }

    int get_top(){
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
    Stack st;

    while(true){
        puts("Enter 1 to push, 2 to pop, 3 to get top, 0 to print:");
        cin>>opt;

        if(opt==1){
            cin>>x;
            st.push(x);
        }

        if(opt==2){
            st.pop();
        }

        if(opt==3){
            int top= st.get_top();
            cout<<top<<endl;
        }

        if(opt==0){
            st.print();
        }


    }
}




