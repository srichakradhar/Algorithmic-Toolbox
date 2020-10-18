#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

long long maxPairwiseProductFast(const vector<int>& numbers) {

	int n = numbers.size();
	long long prod = 0;

	int max_index1 = -1;
	for(int i=0; i < n; i++) {
		if((max_index1 == -1) || numbers[i] > numbers[max_index1]) {
			max_index1 = i;
		}
	}

	int max_index2 = -1;
	for(int i=0; i < n; i++) {

		if((i != max_index1) && ((max_index2 == -1) || numbers[i] > numbers[max_index2])) {
			max_index2 = i;
		}
	}

	if((max_index1 != -1) && (max_index2 != -1))
	prod = ((long long) numbers[max_index1]) * numbers[max_index2];

	return prod;
}

long long maxPairwiseProduct(const vector<int>& numbers) {

	int n = numbers.size();
	long long prod = 0;
	long long max = 0;

	for(int i=0; i < n; i++) {
	for(int j=i + 1; j < n; j++) {
		prod = ((long long) numbers[i]) * numbers[j];
		if(prod > max) {
			max = prod;
		}
	}
	}

	return max;

}

int main() {


	int n;

	/*
	while(true) {

		n = rand() % 10 + 2;

		cout << n << endl;
		
		vector<int> a(n);
		for(int i=0; i < n; i++) {
			a[i] = rand() % 100000;
		}

		for(int i=0; i < n; i++) {
			cout << a[i] << ' ';
		}

		long long resp1 = maxPairwiseProduct(a);
		long long resp2 = maxPairwiseProductFast(a);

		if(resp1 != resp2) {
			cout << endl << "Wrong Answer: " << resp1 << ", " << resp2 << endl;
			break;
		} else {
			cout << "OK" << endl;
		}
	
	}
	*/


	cin >> n;

	vector<int> numbers(n);

	for(int i=0; i < n; i++) {
		cin >> numbers[i];
	}

	cout << maxPairwiseProductFast(numbers) << endl;

	// stress test
	// cout << maxPairwiseProduct(vector<int>(100000, 0)) << endl;

	
	return 0;
}
