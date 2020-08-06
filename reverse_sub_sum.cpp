#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> sums;
vector<int> seq;

bool remove(int tg, vector<int>& nums){
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] == tg){
			nums.erase(nums.begin()+i);
			return true;
		}
	}
	return false;
}

void move(int ele){
	//Should have already been deleted in clear
	seq.push_back(ele);
}

bool clear(int ele, int indx, int sum){
	if(indx == seq.size()){
		sum = sum+ele;
		return remove(sum,sums);
	}
	else{
		return clear(ele,indx+1,sum+seq[indx]) && 
					clear(ele,indx+1,sum);
	}
}

void print_seq(){
	for(int i = 0; i < seq.size(); i++){
		cout << seq[i] << " ";
	}
	cout << "\n";
}

int main(){
	
	cout << "Input seq length:(Power of 2)\n";	
	cin >> n;

	cout << "Input seq\n";
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		sums.push_back(tmp);
	}
	sort(sums.begin(),sums.end());

	if(sums[0] != 0){
		cout << "0  not first ele\n";
		return 0;
	}
	sums.erase(sums.begin());

	while(sums.size()>0){
		int ele = sums[0];
		vector<int> nums;
		if(!clear(ele,0,0)){cout << "Not subset sum\n"; return 0;}
		move(ele);
	}

	print_seq();
	return 0;
}