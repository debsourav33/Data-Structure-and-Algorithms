#include<bits/stdc++.h>
using namespace std;

struct point{
    int x,y;

    point(int _x, int _y){
        x=_x;
        y=_y;
    }

};

int direction(point Pi,point Pj,point Pk){
    return (Pi.x-Pk.x)*(Pj.y-Pk.y) - (Pj.x-Pk.x)*(Pi.y-Pk.y);
}

bool onsegment(point p1,point p2,point p3){
    return (p3.x>= min(p1.x,p2.x) && p3.x<= max(p1.x,p2.x)) &&
           (p3.y>= min(p1.y,p2.y) && p3.y<= max(p1.y,p2.y));
}

bool turn(point p1,point p2,point p3){
    if(direction(p3,p2,p1)>0)
        cout<<"Turns Right(clockwise)"<<endl;
    else
        cout<<"Turns left(anti-clockwise)"<<endl;

}

bool segment_intersect(point p1,point p2,point p3, point p4){
    int d1,d2,d3,d4;

    d1= direction(p1,p4,p3);
    d2= direction(p2,p4,p3);
    d3= direction(p3,p2,p1);
    d4= direction(p4,p2,p1);

    /*if p1 and p2 are in opposite side of p3p4 and p3 and p4 are in opposite side of p1p2*/
    if(d1*d2<0 && d3*d4<0)
        return true;

    /*boundary cases*/
    else if(d1==0 && onsegment(p3,p4,p1))
        return true;

    else if(d2==0 && onsegment(p3,p4,p2))
        return true;

    else if(d3==0 && onsegment(p1,p2,p3))
        return true;

    else if(d4==0 && onsegment(p1,p2,p4))
        return true;

    else
        return false;


}




main(){
    cout<<segment_intersect(point(2,3),point(3,0),point(0,0),point(4,2))<<endl;
}
