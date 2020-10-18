#include <iostream>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int get_period_length(long long n, long long m) {


	int period_length = 0;

	int previous = 1;
    int current  = 1;
    // int prev = 0, curr = 1;
    int tmp_previous, tmp;
    int i = 2;

	// period_length should remain 0 when m <= 1
    while (m > 1) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
        if((i>1) && (previous == 0) && (current == 1)){
        	period_length = i;
        	break;
        }
        // std::cout << current << " ";
        ++i;
    }

    // std::cout << std::endl;

    return period_length;
    
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    if (m <= 1)
    	return 0;

	int period_length = get_period_length(n, m);

	// std::cout << "Period length: " << period_length << std::endl;

	int f[period_length];
	f[0] = 0;
	f[1] = 1;

	if(period_length < 2)
	period_length = n;

    for (int i = 2; i < period_length; ++i) {
    	f[i] = (f[i-1] + f[i-2]) % m;
    }

    /*
    std::cout << "Pisano Period" << std::endl;

    for (int i = 0; i < period_length; ++i) {
    	std::cout << f[i] << " ";
    }

    std::cout << std::endl;
    */
    
    return f[n % period_length];
}

int main() {
    long long n, m;
    /*while(true) {

		n = rand() % 150 + 100;

		cout << n << endl;

		long long resp1 = get_fibonacci_huge_naive(n, 10);
		long long resp2 = get_fibonacci_huge_fast(n, 10);

		if(resp1 != resp2) {
			cout << "Wrong Answer: " << resp1 << ", " << resp2 << endl;
			break;
		} else {
			cout << "OK" << endl;
		}

	}*/
    std::cin >> n >> m;
	// for(m= 1; m < 11; m++)
   	std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
