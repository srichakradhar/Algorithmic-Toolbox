#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

	// sort by value / weight
	int n = weights.size();
	double unit_values[n];
	for(int i=0; i < n; i++) {
		unit_values[i] = (double) values[i] / weights[i];
	}
	const int N = sizeof(unit_values) / sizeof(double);
	int maxi;
	int wi;
	int vi;
	double amount;
	double add_value;
	
	while(capacity > 0){
		maxi = distance(unit_values, max_element(unit_values, unit_values + N));
		cout << "wi = " << weights[maxi] << ", vi = " << values[maxi] << endl;
		wi = weights[maxi];
		vi = values[maxi];
		amount = min(wi, capacity);
		add_value = amount * unit_values[maxi];
		value += add_value;
		capacity -= amount;
		weights[maxi] -= amount;
		unit_values[maxi] = 0;
	}

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  cout << fixed;
  std::cout << optimal_value << std::endl;
  return 0;
}
