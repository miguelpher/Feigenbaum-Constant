#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long double ld;

void print_vector(vector<ld> v) {
	int n = (int)v.size();
	for (int i = 0; i < n; ++i) cout << v[i] << endl;
}

vector<ld> calculate_deltas(vector<ld> v) {
	int n = (int)v.size();
	vector<ld> delta(n-2);
	for (int i = 0; i < n-2; ++i){
		delta[i] = (v[i+1]-v[i])/(v[i+2]-v[i+1]);
	}
	return delta;
}

int main(){
	cout.precision(16);
	int n_real = 12; // numero d'iteracions
	int n = n_real + 2; //n_real mus obtingudes + 2 aproximacions inicials
	vector<ld> mu(n+1, 0);
	vector<ld> alpha(n+1, 0);
	mu[1] = 2;
	mu[2] = 1 + sqrt(5);
	ld d = 4;
	for(int k = 3; k <= n; ++k){ //exponent 2^k
		ld a = mu[k-1] + (mu[k-1] - mu[k-2])/d; // aproximacio inicial de mu
		ld res; ld der;
		for(int i = 0; i < 2; ++i) { // # iteracions Newton
			res = 0.5; der = 0;
			int n_compositions = pow(2, k-1) + 1;
			for (int j = 2;j <= n_compositions; ++j) {
				der = res*(1-res) + a*(1-2*res)*der;
				res = a*res*(1-res);
			}
			a = a - (res-0.5)/der;
		}

		mu[k] = a;
	}
	
	vector<ld> real_mu(n_real+1);
	for (int i = 0; i <= n_real; ++i) real_mu[i] = mu[i+2];
	
	cout << "mus obtingudes:" << endl << endl;
	print_vector(real_mu);
	
	vector<ld> delta((int)real_mu.size() - 2);
	delta = calculate_deltas(real_mu);
	
	cout << endl << "deltas obtingudes:" << endl << endl;
	print_vector(delta);
	
}
