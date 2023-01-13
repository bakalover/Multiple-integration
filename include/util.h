#ifndef UTIL_HEADER
#define UTIL_HEADER
#include <iostream>
#include <vector>
using namespace std;

//Partition of each dimension
//const int32_t PARITION = 400;

//Borders of Area
const int32_t LEFT_BORDER_X = -13;
const int32_t RIGHT_BORDER_X = -5;
const int32_t LEFT_BORDER_Y = 21;
const int32_t RIGHT_BORDER_Y = 94;

//Structure describing point
struct point{
    double x,y;
};

//Calculating integral by giving function, edges of area(to validate using Jordan Theorem) and partition
double calculate_integral(double (*func)(struct point) ,int32_t PARTITION, vector<struct point>& arr);

//Just R->R function
double func(struct point point);

//Bunch of validation function
double area (struct point a, struct point b, struct point c);
bool intersect_parallel (double a, double b, double c, double d);
bool intersect (struct point a, struct point b, struct point c, struct point d);
bool check_crossing_new(vector<struct point> &arr, struct point new_point);
int32_t check_crossing_internal(vector<struct point> &arr, struct point point_1,struct point point_2);

#endif