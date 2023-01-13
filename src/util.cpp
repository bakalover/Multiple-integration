#include "../include/util.h"

double func(struct point point){
    return point.x*point.x*point.x+point.y*point.y*point.y+point.x;
}

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
