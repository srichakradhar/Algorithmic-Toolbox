#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std:: endl;

int compute_min_refills(int dist, int tank, vector<int> & stops) {

	int n_refills = 0;

    // safe move - farthest reachable stop
    int last_stop = 0;
    int n = stops.size();
    stops.insert(stops.begin(), 1, 0);
    stops.push_back(dist);
    int i = 0;
    
    while(i <= n) {
    	last_stop = i;
    	// cout << "Last stop at " << last_stop << ": " << stops[last_stop] << endl;
    	while((i <= n) && (stops[i+1] - stops[last_stop] <= tank) ) {
    		i++;
    		// cout << i << ": " << stops[i] << endl;
    	}

    	if(last_stop == i)
    	{
    		return -1;
    	}
    	if(i <= n)
    	{
    		n_refills++;
    	}
    }
    
    return n_refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
