#include <iostream>

using namespace std;

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n) {

    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    int sum = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum = (sum + current * current) % 10;
    }

    return sum;

}

int fibonacci_sum_squares_fastest(long long n) {

    if (n <= 1)
        return n;

    int period_length = 60; // for F(n) mod 10
    int f[period_length];
	f[0] = 1;
	f[1] = 1;

	int n1 = n % period_length + 1;
	
    for (int i = 2; i < n1; ++i) {
    	f[i] = (f[i-1] + f[i-2]) % 10;
    }

    // cout << "F(n):" << f[n1 - 2] << " " << "F(n+1):" << f[n1 - 1] << endl;

    return (f[n1 - 2] * f[n1 - 1]) % 10;
    

}

int main() {
    long long n = 0;

    /*while(true) {

		n = rand() % 140 + 100;

		cout << n << endl;

		long long resp1 = fibonacci_sum_squares_naive(n);
		long long resp2 = fibonacci_sum_squares_fastest(n);

		if(resp1 != resp2) {
			cout << "Wrong Answer: " << resp1 << ", " << resp2 << endl;
			break;
		} else {
			cout << "OK" << endl;
		}

	}*/
	
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fastest(n) << endl;
}
