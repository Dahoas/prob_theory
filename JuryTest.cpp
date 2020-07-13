#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;

void jury_test(vector<double> v, double d){
	int i;

	double scale = 1+d;
	for(int j = 0; j < v.size();j++){
		v[j] = pow(scale,n-j)*v[j];
	}

	//Jury Test Code
	vector<vector<double>> vvd;
	vvd.push_back(v);
	reverse(v.begin(),v.end());
	vvd.push_back(v);

	for(i = 2;;i+=2){
		v.clear();
		double mult = vvd[i-2][vvd[i-2].size()-1]/vvd[i-2][0];

		for(int j = 0; j < vvd[i-2].size()-1;j++){
			v.push_back(vvd[i-2][j] - vvd[i-1][j]*mult);

		}

		vvd.push_back(v);
		reverse(v.begin(),v.end());
		vvd.push_back(v);
		if(v.size() == 1) break;
	}

	int cnt = 0;
	for(i = 0; i < vvd.size(); i+=2){
		//cout << i << "th row ";
		//cout << vvd[i][0] << '\n';
		//Why was this originally checking for non positivity?
		//Might be getting degeneracies because roots excatly on circle?(the test assumes this not true)
		if (vvd[i][0] < 0) break;
	}

	cout << "Number of roots in disc: " << cnt << '\n';
	cout << "Number of roots out of disc " << n-cnt << '\n';
}

int main(){

	vector<double> v;
	//Note highest order coefficient is first element of array
	cout << "Input poly degree and then coeffcients from highest deg coef to lowest\n";
	cin >> n;
	vector<double> temp;
	for(int i = 0; i <= n; i++){
		double temp;
		cin >> temp;
		v.push_back(temp);
	}
	temp = v;
	double delta = 0.01;
	cout << delta << " approximation\n";
	jury_test(temp,delta);

	reverse(v.begin(),v.end());

	jury_test(temp,delta);

	return 0;
}