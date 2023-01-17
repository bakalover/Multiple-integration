#include "../include/util.h"
#include <cmath>

double func(struct point point){
    return pow(point.x,3)+pow(point.y,3) + point.x;
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
double calculate_S(int32_t PARTITION,vector<struct point>& arr){
    double S=0;
    for (int32_t i = LEFT_BORDER_X * PARTITION; i <= RIGHT_BORDER_X * PARTITION; i++)
    {
        for (int32_t j = LEFT_BORDER_Y * PARTITION; j <= RIGHT_BORDER_Y * PARTITION; j++)
        {
            struct point check_point = (struct point){.x = ((double)i/PARTITION), .y = ((double)j/PARTITION)};
            struct point inf_point = (struct point){.x = (double)1000000, .y = (double)100000000};
            if(check_crossing_internal(arr,check_point,inf_point)%2==1){
                S += 1*((double)1/(pow(PARTITION,2)));
            }
        }
    }
    return S;
}

double calculate_integral(double (*func)(struct point point),double S,int32_t N, vector<struct point>& arr,vector<double> &pts){
    double I = 0;
    double kor = 0;
    struct point inf_point = (struct point){.x = (double)1000000, .y = (double)100000000};
    for (size_t i = 0; i < N; i++)
    {
        struct point pt = (struct point){.x=(((double)rand()/(double)RAND_MAX) * (double)8)-(double)13 , .y = (((double)rand()/(double)RAND_MAX) * (double)73)+(double)21 };
        if(check_crossing_internal(arr,pt,inf_point)%2==1){
                pts.push_back(func(pt));
                I += func(pt);
                kor += 1;
        }
    }
    return ((I*S)/(double)N) * S / ((kor*S)/(double)N); // magic constants :)
}

bool check_border(struct point point){
    return point.x>=LEFT_BORDER_X && point.x<=RIGHT_BORDER_X && point.y >= LEFT_BORDER_Y && point.y <= RIGHT_BORDER_Y;
}