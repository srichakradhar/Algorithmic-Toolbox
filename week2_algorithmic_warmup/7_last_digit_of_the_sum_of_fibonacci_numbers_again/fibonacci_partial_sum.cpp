#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {

        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    cout << sum << endl;

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {

	// since 0 <= from <= to <= 10^14
	if (from < 0 || to <= 0 || from > to)
        return 0;

    int previous = 0;
    int current  = 1;
    int sum = 1;
    // for from <= 1
    int sum1 = 1;

	if(from < 2){
		sum1 = 0;
	}
	
    // cout << endl;

    for (int i = 2; i <= to; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        // cout << sum << ", ";
        if(i == from) {
        	sum1 = sum;
        	// cout << "first sum: " << sum1 << endl;
        }
        sum = (sum + current) % 10;
    }

    // cout << "second sum:" << sum << endl;

    if( to > 4 && sum < sum1 ) {
    	sum += 10;
    }

    return (sum - sum1) % 10;

}

int fibonacci_sum_fastest(long long n) {
    if (n < 1)
        return 0;

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

long long get_fibonacci_partial_sum_faster(long long from, long long to) {
	
	int to_sum = fibonacci_sum_fastest(to);
	int from_sum = fibonacci_sum_fastest(from-1);
	return (10 + to_sum - from_sum) % 10;
	
}

int main() {
    long long from, to;
	to = 100;
    /*for (from = 1; from < to; ++from) {

		cout << from << ", " << to << endl;

		long long resp1 = get_fibonacci_partial_sum_naive(from, to);
		long long resp2 = get_fibonacci_partial_sum_faster(from, to);

		if(resp1 != resp2) {
			cout << "Wrong Answer: " << resp1 << ", " << resp2 << endl;
			break;
		} else {
			cout << "OK" << endl;
		}
		
	}*/
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_faster(from, to) << '\n';
}
