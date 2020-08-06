#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> sums;

void print_sums(){
	for(int i = 0; i < sums.size(); i++){
		cout << sums[i] << " ";
	}
	cout << "\n";
}

void insert(int num, vector<int>& nums){
	for(int i = 0 ; i < nums.size();i++){
		if(num <= nums[i]){nums.insert(nums.begin()+i,num); return;}
	}
	nums.push_back(num);
}

int main(){
	
	cout << "Input seq length:\n";	
	cin >> n;
	cout << "Input seq\n";
	sums.push_back(0);
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		int len = sums.size();
		for(int j = 0; j < len; j++){
			//Insertion sort
			insert(tmp+sums[j],sums);
		}
	}

	sort(sums.begin(),sums.end());
	print_sums();
	return 0;
}