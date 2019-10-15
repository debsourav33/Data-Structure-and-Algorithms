#include<bits/stdc++.h>
using namespace std;

#define null NULL

struct node{
    int val;
    node* left;
    node* right;
};

node* root= null;

void print_tree(node* t, string spacing){
    /*World's most elegent tree printing function*/
    if(t==null){
        cout<<spacing<<"xxx"<<endl;
        return;
    }

    cout<<spacing<<t->val<<endl;

    cout<<spacing<<"-->Left:"<<endl;
    print_tree(t->left,spacing+"  ");

    cout<<spacing<<"-->Right:"<<endl;
    print_tree(t->right,spacing+"  ");

}

void insert(int x){
    node* t= (node*) malloc(sizeof(node));
    node* temp= root;

    t->val= x;
    t->left= null;
    t->right= null;

    if(root==null){
        root= t;
        return;
    }

    while(1){
        if(x < temp->val){
            if(temp->left== null){
                temp->left= t;
                return;
            }

            temp= temp->left;
        }

        else{
            if(temp->right== null){
                temp->right= t;
                return;
            }

            temp= temp->right;
        }


    }


}

void delete(int x){
    if(root==null){
        return;
    }

    if(root->val==x){
        root=null;
    }

    node* t= root;

    while(1){
        if(x < t->val){
            if(t->left->val==x){
                t->left= t->left->left;
                return;
            }

            t=t->left;
        }

        else{
            if(t->right->val==x){
                t->left= t->left->left;
                return;
            }

            t=t->left;
        }

    }


}


main(){
    int opt,x;

    while(1){
        puts("Enter 1 to insert, 0 to print tree");
        cin>>opt;

        if(opt==1){
            cin>>x;
            insert(x);
        }

        if(opt==0){
            puts("");
            print_tree(root,"");
            puts("");
        }


    }


}

