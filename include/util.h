#ifndef UTIL_HEADER
#define UTIL_HEADER
#include <iostream>
#include <vector>
using namespace std;

struct point{
    double x,y;
};

double func(struct point point);

double area (struct point a, struct point b, struct point c);
bool intersect_parallel (double a, double b, double c, double d);
bool intersect (struct point a, struct point b, struct point c, struct point d);
bool check_crossing_new(vector<struct point> &arr, struct point new_point);
int32_t check_crossing_internal(vector<struct point> &arr, struct point point_1,struct point point_2);
#endif