#include <iostream>

using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    int sum = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum = (sum + current) % 10;
    }

    return sum;
}

int fibonacci_sum_faster(long long n) {
    if (n <= 1)
        return n;
	//if(n > 500) { // about twice the period_length
		int period_length = 60; // for mod 10
		int f[period_length];
		int pisano_period_sum = 1;
		f[0] = 0;
		f[1] = 1;

		for (int i = 2; i < period_length; ++i) {
			f[i] = (f[i-1] + f[i-2]) % 10;
			pisano_period_sum = (pisano_period_sum + f[i]) % 10;
		}

		int extra_sum = 0;
		int r = n % period_length;
        for (int i = 0; i <= r; ++i) {
            extra_sum += f[i];
        }

		return (pisano_period_sum * (n / period_length) + extra_sum) % 10;
	/*}
	else
	{
		int previous = 0;
		int current  = 1;
		int sum = 1;

		for (int i = 0; i < n - 1; ++i) {
		    int tmp_previous = previous;
		    previous = current;
		    current = (tmp_previous + current) % 10;
		    sum = (sum + current) % 10;
		}
	}

    return sum;*/
}

int fibonacci_sum_fastest(long long n) {
    if (n <= 1)
        return n;

    int period_length = 60; // for F(n) mod 10
    int f[period_length];
	f[0] = 1;
	f[1] = 1;

	int n2 = n % period_length + 2;
	
    for (int i = 2; i < n2; ++i) {
    	f[i] = (f[i-1] + f[i-2]) % 10;
    }
    
	// S(n) = F(n+2) - 1

    return (10 + f[n2 - 1] - 1) % 10; // when f[n] == 0 add 10 and mod 10
}

int main() {

    long long n = 0;

    /*while(true) {

		n = rand() % 1400 + 100;

		cout << n << endl;

		long long resp1 = fibonacci_sum_fast(n);
		long long resp2 = fibonacci_sum_fastest(n);

		if(resp1 != resp2) {
			cout << "Wrong Answer: " << resp1 << ", " << resp2 << endl;
			break;
		} else {
			cout << "OK" << endl;
		}

	}*/

    std::cin >> n;
    std::cout << fibonacci_sum_fastest(n); // << ", " << fibonacci_sum_fast(n);
}
