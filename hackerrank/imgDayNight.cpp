#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <istream>
#include <algorithm>
using namespace std;

class pixel{
    public:
    int r,g,b;
    pixel(int x, int y, int z){
        r=x;
        g=y;
        b=z;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int RAvg=0,GAvg=0,BAvg=0;
    int count2=0;
    char waste;
    do{
        int R,G,B;
        int count=0, RTot=0, GTot=0, BTot=0;
        scanf("%d,%d,%d",&R,&G,&B);
        RTot+=R;
        GTot+=G;
        BTot+=B;
        count++;
        //pixel temp= pixel(R,G,B);
        cout<<R<<G<<B<<endl;
        // cin>>waste;
        // if(waste == '\n'){
        //     RAvg+=(RTot/count);
        //     GAvg+=(GTot/count);
        //     BAvg+=(BTot/count);
        //     count2++;
        //     count=0;
        //     RTot=0;
        //     GTot=0;
        //     BTot=0;
        // }
        int c = file.peek();
    }
    while(c!=EOF);
    // RAvg/=count2;
    // GAvg/=count2;
    // BAvg/=count2;
    
    // if( ((RAvg+GAvg+BAvg)/3) < 127 ){
    //     cout<<"night"<<endl;
    // }
    // else{
    //     cout<<"day"<<endl;
    // }
    
    return 0;
}
