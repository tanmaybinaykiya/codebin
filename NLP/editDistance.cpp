#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector < vector<int> > weightMatrix;

void printMatrix(){
	cout<<endl;
	int i=0,j=0;
	for(i=0;i<weightMatrix.size();i++){
		for(j=0;j<weightMatrix[i].size();j++){
			cout<<weightMatrix[i][j]<<"\t";	
		}
		cout<<endl;
	}
}

void printMatrix(string word1, string word2){
	
	cout<<endl;
	int i=0,j=0;
	cout<<" \t \t";
	for(j=0;j<word1.size();j++){
		cout<<word1[j]<<"\t";
	}
	cout<<"\n \t";
	for(i=0;i<weightMatrix.size();i++){
		for(j=0;j<weightMatrix[i].size();j++){
			if(i>0 && j==0){
				cout<<word2[i-1]<<"\t";		
			}
			cout<<weightMatrix[i][j]<<"\t";	
		}
		cout<<endl;
	}
}

int min(int a, int b, int c){
	int min=65535;
	if(a<min) min=a;
	if(b<min) min=b;
	if(c<min) min=c;
	// cout<<"Minimum of "<<a<<","<<b<<","<<c<<" is "<<min<<endl;
	return min;
}

int recurse(string word1, string word2, int i, int j){
	cout<<"recurse i:"<<i<<" j: "<<j<<endl;
	// cout<<"weightMatrix["<<j<<"]["<<i<<"]= "<<weightMatrix[j][i]<<endl;
	if(weightMatrix[j][i] == -1){
		cout<<"\tComparing:"<<word1[i-1]<<" and "<<word2[j-1]<<endl;
		weightMatrix[j][i] = min (	recurse(word1, word2,  i-1,j  ) + 1,
									recurse(word1, word2,  i,  j-1) + 1,
									recurse(word1, word2,  i-1,j-1) + ((word1[i-1]==word2[j-1])?0:2)
								 );

		// int insertionCost 	= recurse(word1, word2,  i-1,j  ) + 1;
		// int deletionCost  	= recurse(word1, word2,  i,  j-1) + 1;
		// int substitutionCost= recurse(word1, word2,  i-1,j-1) + ((word1[i-1]==word2[j-1])?0:2);

		// cout<<"insertionCost: "<<insertionCost<<"\t"
		// 	<<"deletionCost: "<<deletionCost<<"\t"
		// 	<<"substitutionCost: "<<substitutionCost<<endl;
		// weightMatrix[j][i] 	= min(insertionCost,deletionCost,substitutionCost);
	}
	cout<<"weightMatrix["<<j<<"]["<<i<<"]= "<<weightMatrix[j][i]<<endl;
	return weightMatrix[j][i];
}

void initialize(string word1,string word2){
	
	for(int i=0; i<weightMatrix.size(); i++){
		weightMatrix[i][0]=i;
	}
	
	for(int i=0;i<weightMatrix[0].size(); i++){
		weightMatrix[0][i]=i;
	}
	
}

int editDistance(string word1, string word2){
	recurse(word1,word2,word1.length(),word2.length());
}


int main(){

	//given two words, find the edit distance
	string word1, word2;
	cin>>word1;
	cin>>word2;

	// cout<<word1<<endl;
	// cout<<word2<<endl;

	
	for(int i=0;i<=word2.length();i++){
		vector<int> temp (word1.length()+1,-1);
		weightMatrix.push_back(temp);
	}
	initialize(word1,word2);
	printMatrix();
	editDistance(word1,word2);
	printMatrix(word1,word2);
	// printMatrix();
	return 0;
}