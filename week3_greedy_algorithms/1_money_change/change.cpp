#include <iostream>

int get_change(int m) {
  //write your code here
  int n = 0; // number of coins
  int denominations[3] = {10, 5, 1};

  for(int i=0; i < 3; i++) {
		n += m / denominations[i];
		m %= denominations[i];
  }
  
  return n;
}

int get_change_naive(int m) {

  // safe move - while not changed, choose highest denomination
  int denominations[3] = {10, 5, 1};
  int i = 0;
  int coins = 0;
  
  while(m > 0) {
	if(m - denominations[i] >= 0){
	  	m -= denominations[i];
	  	coins++;
  	}
  	else
  	{
	  	i++;
  	}
  }
  
  return coins;
}

int main() {
  int m;
  std::cin >> m;
  /*
  while(true) {

		m = rand() % 100;

		std::cout << m << std::endl;
		
		long long resp1 = get_change_naive(m);
		long long resp2 = get_change(m);

		if(resp1 != resp2) {
			std::cout << std::endl << "Wrong Answer: " << resp1 << ", " << resp2 << std::endl;
			break;
		} else {
			std::cout << "OK" << std::endl;
		}
	
	}
	*/
	
  std::cout << get_change(m) << '\n';
}
