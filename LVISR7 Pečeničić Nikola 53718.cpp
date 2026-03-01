#include <cmath>
#include <cstdlib>
#include<ctime>
#include <iostream>
using namespace std;
//Izračunavanje teoretskih vrednosti
void Binomna_Raspodela(int n, double p) {
	int n_nad_k = 1;
	double* vektor = new double[n + 1];
	//Po formuli zakona Binomne raspodele
	cout << "Teoretske vrednosti binomne raspodele su:\n";
	cout << "[";
	for (int k = 0; k <= n; k++) {
		vektor[k] = n_nad_k * pow(p, k) * pow(1 - p, n - k);
		n_nad_k = n_nad_k * (n - k) / (k + 1);
		cout << vektor[k] << ",   ";
	}
	cout << "]";
}
//Glavni program
int main() {
	srand(time(0));
	int n, N;
	double p;
	cout << "Unesite broj eksperimenata n=";
	cin >> n; cout << endl;
	double* vek = new double[n + 1];
	cout << "Unesite verovatnocu uspeha eksperimenta p=";
	cin >> p; cout << endl;
	cout << "Unesite broj iteracija N=";
	cin >> N; cout << endl;
	//Prebrojavanje uspeha kroz N iteracija od po n eksperimenata
	for (int i = 0; i < (n + 1); i++)vek[i] = 0;
	for (int i = 1; i <= N; i++) {
		int s = 0;
		for (int j = 1; j <= n; j++) {
			double x = (double)rand() / RAND_MAX;
			if (x < p) s = s + 1;
		}
		vek[s]++;
	}
	//Poziv funkcije 
	Binomna_Raspodela(n, p);
	//Izračunavanje relativnih frekvencija uspeha
	cout << "\n\n";
	cout << "Relativne frekvencije uspeha su:\n";
	cout << "[";
	int i;
	for (i = 0; i <= n; i++) {
		vek[i] = vek[i] / N;
		cout << vek[i] << ",	";
	}
	cout << "]";

	cin >> N;

}
