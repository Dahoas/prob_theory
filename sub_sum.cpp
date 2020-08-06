#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int n;
vector<int> sums;

void print_sums(){
	ofstream myfile;
	myfile.open ("constructedSum");
	for(int i = 0; i < sums.size(); i++){
		myfile << sums[i] << "\n";
	}
	myfile.close();
}

void insert(int num, vector<int>& nums){
	for(int i = 0 ; i < nums.size();i++){
		if(num <= nums[i]){nums.insert(nums.begin()+i,num); return;}
	}
	nums.push_back(num);
}

void print_vect(){
	for(int i = 0; i < sums.size();i++){
		cout << sums[i] << " ";
	}
	cout << '\n';
}

int main(int argc, char *argv[]){
	
	string filename = argv[1];
	string line;
	ifstream myfile;
	myfile.open(filename);
	sums.push_back(0);
	while(getline(myfile,line)){
		int tmp;
		tmp = stoi(line);
		int len = sums.size();
		for(int j = 0; j < len; j++){
			//Insertion sort
			//insert(tmp+sums[j],sums);
			sums.push_back(tmp+sums[j]);
		}
	}
	myfile.close();
	sort(sums.begin(),sums.end());
	print_sums();
	return 0;
}
