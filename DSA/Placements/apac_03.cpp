/**************************************************************************************************
Once upon a day, Mary bought a one-way ticket from somewhere to somewhere with some flight transfers.


For example: SFO->DFW DFW->JFK JFK->MIA MIA->ORD.
Obviously, transfer flights at a city twice or more doesn't make any sense. So Mary will not do that.
Unfortunately, after she received the tickets, she messed up the tickets and she forgot the order of the ticket.
Help Mary rearrange the tickets to make the tickets in correct order.

Input
The first line contains the number of test cases T, after which T cases follow.
For each case, it starts with an integer N. There are N flight tickets follow.
Each of the next 2 lines contains the source and destination of a flight ticket.

Output
For each test case, output one line containing "Case #x: itinerary", where x is the test case number (starting from 1) and itinerary is sorted list of flight tickets which represents the actual itinerary. Each flight segment in the itinerary should be outputted as pair of source-destination airport codes.

Limits
1 ≤ T ≤ 100.
For each case, the input tickets are messed up from an entire itinerary bought by Mary. In other words, it's ensured can be recovered to a valid itinerary.

Small dataset
1 ≤ N ≤ 100.

Large dataset
1 ≤ N ≤ 104.

(The segment for second case in sample can be seen as below) MIA-ORD, DFW-JFK, SFO-DFW, JFK-MIA
Sample


Input 
 	
Output 
 
2
1
SFO
DFW
4
MIA
ORD
DFW
JFK
SFO
DFW
JFK
MIA


Case #1: SFO-DFW
Case #2: SFO-DFW DFW-JFK JFK-MIA MIA-ORD


Solution
**************************************************************************************************/
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
typedef struct  {
	int left;
	int right;
}node;

typedef struct{
	string src;
	string dest;    
}ticket;

int main (){
	map<string,node> hash;
	int testCaseIterator=0, testCases;
	cin>>testCases;
	for (testCaseIterator = 1; testCaseIterator <= testCases; testCaseIterator++)     {
		cout<<"Case #"<<testCaseIterator<<": ";
		int numTickets=0,ticketIterator=0;
		cin>>numTickets;
		vector<ticket> itinerary;
		for(ticketIterator=1;ticketIterator<=numTickets;ticketIterator++){
			string src,dest;
			cin>>src;
			cin>>dest;
			ticket curr;
			curr.src=src;
			curr.dest=dest;
			itinerary.push_back(curr);
			if(hash.find(src)==hash.end()){
				node temp;
				temp.left=ticketIterator;
				temp.right=0;
				hash[src]=temp;
			}else{
				hash[src].left=ticketIterator;
			}
			if(hash.find(dest)==hash.end()){
				node temp;
				temp.left=0;
				temp.right=ticketIterator;
				hash[dest]=temp;
			}
			else{
				hash[dest].right=ticketIterator;
			}
		}
		map<string,node>::iterator it;
		string currSrc,currDest;
		int currSrcTicket;
		for (it=hash.begin(); it!=hash.end(); it++){
			if(hash[it->first].right==0) {
                    currSrc=it->first;                    //found the trip src
                }
            }
            
            while(hash[currSrc].left!=0){
            	currSrcTicket=hash[currSrc].left;
            	currDest=itinerary[currSrcTicket-1].dest;
            	cout<<currSrc<<"-"<<currDest<<" ";
            	currSrc=currDest;
            }
            cout<<endl;

            itinerary.clear();
            hash.clear();
        }
        return 1;
    }

