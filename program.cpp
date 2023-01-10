#include <iostream>
#include <vector>
using namespace std;

struct point{
    double x,y;
};
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
		&& area(a,b,c) * area(a,b,d) <= 0
		&& area(c,d,a) * area(c,d,b) <= 0;
}

bool check_crossing(vector<struct point> &arr, struct point new_point){
    for (size_t i = 1; i < arr.size(); i++)
    {
        if(intersect(arr[i-1],arr[i],arr[arr.size()-1],new_point)){
            return true;
        }
    }
    return false;
}

int main()
{
    double x,y,count;
    vector<struct point> arr(0);
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
    for (size_t i = 0; i < count; i++)
    {
        while(true){
            cin>>x>>y;
            if(check_crossing(arr,(struct point){.x=x,.y=y})&&arr.size()>=2){
                cout<<"Crossing! Repeat point:"<<endl;
                continue;
            }
            else{
                arr.push_back((struct point){.x=x,.y=y});
                break;
            }
        }
    }
    
    return 0;
}