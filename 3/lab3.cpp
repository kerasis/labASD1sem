
#include <iostream>

int main()
{
	std::cout << "enter int x: ";
	int x;
	std::cin >> x;
	int res;
	for (int k = 0; k < 100; k++)
	{
		bool fb = 0;
		for (int l = 0; l < 100; l++)
		{
			for (int m = 0; m < 100; m++)
			{	
				res = pow(3, k) + pow(5, l) + pow(7, m);
				if (res < x)
				{
					std::cout << "3^" << k <<" + 5^" << l << " + 7^" << m << " = " << res << std::endl;
					std::cout << pow(3, k) << " " << pow(5, l) << " " << pow(7, m) << std::endl;
				}
				else 
				{
					break;
				}
			}
			if ((pow(3, k) + pow(5, l + 1) + pow(7, 0)) > x) { break; }
		}
		if ((pow(3, k+1) + pow(5, 0) + pow(7, 0)) > x) { break; }
	}
}

