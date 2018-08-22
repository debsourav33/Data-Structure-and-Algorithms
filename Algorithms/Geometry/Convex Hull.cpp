#include<bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
    point(int _x, int _y){
        x=_x;
        y=_y;
    }

    void print(){
        printf("(%d,%d)\n",x,y);
    }
};

point p0(0,0);
stack <point> st;

int direction(point p1, point p2, point p3){
    return (p1.x-p3.x)*(p2.y-p3.y) - (p2.x-p3.x)*(p1.y-p3.y);
}

bool compare(point p1, point p2){
    return direction(p1,p2,p0) > 0;
}

bool turn_left(point p1, point p2, point p3){
    return direction(p3,p2,p1) <0;
}


point next_to_top(){
    point top= st.top();
    st.pop();
    point next_to_top= st.top();

    st.push(top);

    return next_to_top;
}

void get_convex_hull(vector<point> p){
    int mini_y= p[0].y, index= 0;
    p0=p[0];

    for(int i=1;i<p.size();i++){
        if(p[i].y<mini_y){
            mini_y= p[i].y;
            p0= p[i];
            index= i;
        }
    }

    p.erase(p.begin()+index);

    sort(p.begin(),p.end(),compare);

    st.push(p0);
    st.push(p[0]);
    st.push(p[1]);


    for(int i=2;i<p.size();i++){
        while(!turn_left(next_to_top(), st.top(), p[i])){
//            cout<<"Right turn for: ";
//            next_to_top().print();
//            st.top().print();
//            p[i].print();
            st.pop();
        }
        st.push(p[i]);

    }

}

void print_CH(){
    cout<<"Convex Hall in Clock-wise Order:\n"<<endl;

    while(!st.empty()){
        st.top().print();
        st.pop();
    }

}

main(){
    vector<point> v;

    v.push_back(point(5,2));
    v.push_back(point(3,5));
    v.push_back(point(0,3));
    v.push_back(point(2,4));
    v.push_back(point(2,2));
    v.push_back(point(6,3));
    v.push_back(point(1,1));
    v.push_back(point(4,3));

    get_convex_hull(v);

    print_CH();
}
