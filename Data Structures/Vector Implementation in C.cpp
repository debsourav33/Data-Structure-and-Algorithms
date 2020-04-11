#include<stdio.h>
#include<malloc.h>

#define null NULL
#define outi(a) printf("%d\n",a)
#define si(a) scanf("%d",&a)

#define fr(n) for(int i=0;i<n;i++)

struct vectors{
    int *a;
    int cur_size= 1, len= 0;

    vectors(){
        a= (int*) malloc(sizeof(int));
        cur_size= 1;
        len= 0;
    }

    void push_back(int val){
        if(len>=cur_size){
            cur_size*= 2;
            int *b= (int*) malloc(sizeof(int) * cur_size);

            for(int i=0;i<len;i++){
                b[i]= a[i];
            }

            a= b;
        }

        a[len++]= val;
    }

    int get(int i){
        return a[i];
    }

    int size(){
        return len;
    }

    void pop_back(){
        len--;
    }
};

vectors v;

main(){
    int a, n;

    //v= vectors();

    scanf("%d",&n);

    fr(n){
        scanf("%d",&a);
        v.push_back(a);
    }

    fr(v.size()){
        outi(v.get(i));
    }

}
