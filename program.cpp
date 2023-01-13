#include <iostream>
#include <vector>
using namespace std;

struct point{
    double x,y;
};

double func(struct point point){
    return point.x*point.x*point.x+point.y*point.y*point.y+point.x;
}

//------------------------------------VALIDATING-CHAIN----------------------------------------------
double area (struct point a, struct point b, struct point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
bool intersect_parallel (double a, double b, double c, double d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool intersect (struct point a, struct point b, struct point c, struct point d) {
	return intersect_parallel (a.x, b.x, c.x, d.x)
		&& intersect_parallel (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * area(a,b,d) < 0
		&& area(c,d,a) * area(c,d,b) < 0;
}

bool check_crossing_new(vector<struct point> &arr, struct point new_point){
    for (size_t i = 1; i < arr.size()-1; i++)
    {
        if(intersect(arr[i-1],arr[i],arr[arr.size()-1],new_point)){
            return true;
        }
    }
    return false;
}

int32_t check_crossing_internal(vector<struct point> &arr, struct point point_1,struct point point_2){
    int32_t count = 0;
    for (size_t i = 1; i <= arr.size()-1; i++)
    {
        if(intersect(arr[i-1],arr[i],point_1,point_2)){
            ++count;
        }
    }
    return count;
}

//------------------------------------VALIDATING-CHAIN----------------------------------------------

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double x,y,count;

    vector<struct point> arr(0);
    cout<<"Please, draw a polygon by entering point coordinats. Be sure that first and last point - same"<<endl;
    cout<<"Enter number of points: "<<endl;
    while(true){
        cin>>count;
        if(cin.fail()){
            cout<<"Please, enter a valid number!"<<endl;
            cin.clear();
        }
        else{
            break;
        }
        cin.ignore(1000,'\n');
    }
    cout<<"\nEnter points in format: \nx1 y1\nx2 y2\n.\n.\n.\n------------------------"<<endl;
    for (size_t i = 0; i <= count; i++)
    {
        while(true){
            cin>>x>>y;
            if(arr.size()>=2&&check_crossing_new(arr,(struct point){.x=x,.y=y})){
                cout<<"Crossing! Repeat point:"<<endl;
                continue;
            }
            if(i==count&&(arr[0].x!=x||arr[0].y!=y)){
                cout<<"Polygonal chain is not closed! Repeat point:"<<endl;
                continue;
            }
            else{
                arr.push_back((struct point){.x=x,.y=y});
                break;
            }
        }
    }
    
    double I = 0;
    for (int32_t i = -1300*2; i <= -500*2; i++)
    {
        for (int32_t j = 2100*2; j <= 9400*2; j++)
        {
            struct point check_point = (struct point){.x = (i/200), .y = (j/200)};
            struct point inf_point = (struct point){.x = 100, .y = 50};
            if(check_crossing_internal(arr,check_point,inf_point)%2==1){
                // I += func(check_point)*(0.000012);
                I += 1*(0.000025);
            }
        }
        
    }
    cout<<"Integral value: "<<I<<endl;

    return 0;
}
// -5 22
// -6 22
// -6 23
// -5 23
// -5 22