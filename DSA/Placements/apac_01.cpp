/*
 *Vincenzo decides to make cube IV but only has the budget to make a square maze. Its a perfect maze, every room is in the form of a square and there are 4 doors (1 on each side of the room). There is a big number written in the room. A person can only move from one room to another if the number in the next room is larger than the number in his current room by 1. Now, Vincenzo assigns unique numbers to all the rooms (1, 2, 3, .... S2) and then places S2 people in the maze, 1 in each room where S is the side length of the maze. The person who can move maximum number of times will win. Figure out who will emerge as the winner and the number of rooms he will be able to move.

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of S which is the side length of the square maze. Then S2 numbers follow like a maze to give the numbers that have been assigned to the rooms.



1 2 9 
5 3 8 
4 6 7 

Output

For each test case, output one line containing "Case #x: r d", where x is the test case number (starting from 1), r is the room number of the person who will win and d is the number of rooms he could move. In case there are multiple such people, the person who is in the smallest room will win.

Limits

1 ≤ T ≤ 100.

Small dataset
1 ≤ S ≤ 10

Large dataset
1 ≤ S ≤ 103. 

Sample


Input 
 	
Output 
 
2
2
3 4
1 2 


3
1 2 9 
5 3 8 
4 6 7 

Case #1: 1 2
Case #2: 6 4



*/


#include<iostream>
#include<vector>
using namespace std;

int main(){
     int cases;
     int i=0,j=0;
     cin>>cases;
     for(j=0;j<cases;j++){
          int n;
          cin>>n;
          int nSquare=n*n;
          vector<int> whatIsIn (nSquare+1,-1);               
          vector<int> whereIs (nSquare+1,-1);              
          vector<int> record (nSquare+1,1);
         
          for(i=1;i<=nSquare;i++){
               int temp;
               cin>>temp;
               whatIsIn[i]=temp;
               whereIs[temp]=i;
          }    
          for(i=nSquare;i>0;i--){
               int nextI=i+1;

               if(  ((whereIs[i]+n)<=nSquare) && (whatIsIn[whereIs[i]+n]==nextI) ){     //nextLine
                    record[i]=record[i+1]+1;
               }
               else if(  ((whereIs[i]-n)>0) && (whatIsIn[whereIs[i]-n]==nextI) ){          //prevLine
                    record[i]=record[i+1]+1;
               }
               else if( ((whereIs[i])%n!=0) && ((whereIs[i]+1)<=nSquare) && (whatIsIn[whereIs[i]+1]==nextI) ){          //next column
                    record[i]=record[i+1]+1;
               }
               else if( ((whereIs[i])%n!=1) && ((whereIs[i]-1)<=nSquare) && (whatIsIn[whereIs[i]-1]==nextI) ){          //prevColumn
                    record[i]=record[i+1]+1;
               }              
          }
    
          int maxPointer=1;
          // cout<<"Record: ";
          for(i=1;i<=nSquare;i++){
               maxPointer=(record[maxPointer]<record[i])?i:maxPointer;
               // cout<<"{"<<i<<","<<record[i]<<"}";
          }
    
          cout<<"Case #"<<j+1<<": "<<maxPointer<<" "<<record[maxPointer]<<endl;
    
     }
     return 1;
}
