#include <iostream>
#include <vector>
using namespace std;
int main(){
	int testCases=0;
	cin>>testCases;
	for(int i=1;i<=testCases;i++){
		int max=0;
		cin>>max;
		vector<int> arr(max+1,0);
		int totReq=0,req=0;
		int sum=0;

		for(int j=0;j<=max;j++){
			req=0;
			char temp='a';
			cin>>temp;
			arr[j]=temp-'0';
			if(j>0 && arr[j]>0)
				if((sum+totReq)<j){
					req=j-sum;
					// cout<<"req: "<<req<<endl;
					totReq+=req;
				}
			sum+=temp-'0';
			// cout<<"sum["<< j<<"]: "<<sum<<endl;
			
		}
		cout<<"Case #"<<i<<": "<<totReq<<endl;
	}
}