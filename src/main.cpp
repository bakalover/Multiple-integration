#include "../include/util.h"
#include "../include/messages.h"
#include <cmath>
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
            if(arr.size()>=2&&check_crossing_new(arr,(struct point){.x=x,.y=y})){
                cout<<CROSSING_MSG<<endl;
                continue;
            }
            if(i==count&&(arr[0].x!=x||arr[0].y!=y)){
                cout<<CLOSE_MSG<<endl;
                continue;
            }
            else{
                arr.push_back((struct point){.x=x,.y=y});
                break;
            }
        }
    }
    for (int32_t PARTITION = 1; PARTITION < 400; PARTITION++)
    {
    cout<<((double)11223 - calculate_integral(func,PARTITION,arr))/(double)11223<<endl;
    }
    return 0;
}
// -5 22
// -6 22
// -6 23
// -5 23
// -5 22