#include "../include/util.h"
#include "../include/messages.h"
#include <cmath>
#include <fstream>
double ed(struct point point){return 1;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double x,y,count,I=0;

    vector<struct point> arr(0);

    cout<<ENTER_MSG<<endl;
    cout<<REQUEST_MSG<<endl;

    while(true){
        cin>>count;
        if(cin.fail()){
            cout<<VALID_ERROR_MSG<<endl;
            cin.clear();
        }
        else{
            break;
        }
        cin.ignore(1000,'\n');
    }

    cout<<DOTS_FORMAT_MSG<<endl;

    for (size_t i = 0; i <= count; i++)
    {
        while(true){
            cin>>x>>y;
            struct point point = (struct point){.x=x,.y=y};
            if(!check_border(point)){
                cout<<BORDER_MSG<<endl;
                continue;
            }
            if(arr.size()>=2&&check_crossing_new(arr,point)){
                cout<<CROSSING_MSG<<endl;
                continue;
            }
            if(i==count&&(arr[0].x!=x||arr[0].y!=y)){
                cout<<CLOSE_MSG<<endl;
                continue;
            }
            else{
                arr.push_back(point);
                break;
            }
        }
    }
    // for (int32_t PARTITION = 50; PARTITION < 250; PARTITION++)
    // {
    // cout<<((double)73150 - calculate_integral(func,PARTITION,arr))/(double)73150<<endl;
    // }
    //int32_t PARTITION = 300;
    double S = calculate_S(PARTITION,arr);
    vector<double> pts;
    cout<<calculate_integral(func,S,100000,arr, pts)<<endl;
    /*ofstream out("/home/bakalover/repo/multiple_integration/out.txt", ios::app);  
    for (int32_t i = 10000; i < 100000000; i = i+10000)
    {
        vector<double> pts;
        double I = calculate_integral(func,S,i,arr, pts);
        double D = 0;
        double I_N = 0;
        double pt_avg = 0;
        for (size_t i = 0; i < pts.size(); i++)
        {
            pt_avg += pts[i];
        }
        pt_avg = pt_avg/pts.size();
        for (size_t i = 0; i < pts.size(); i++)
        {
            D += (pts[i] - pt_avg); 
        }
        D = abs(D/(i-1));
        out<<(S/sqrt(i)) * sqrt(D)<<endl;
        
    }
    out.close();*/
    return 0;
}

// -5 22
// -6 22
// -6 23
// -5 23
// -5 22

// -7 25
// -8 26
// -8 27
// -7 28
// -6 27
// -6 26
// -7 25