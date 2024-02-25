#include <iostream>
using namespace std;
int main(){
	int a, b, c, d;
	int x, y;
	std::cin >> a >> b >> c >> d;
	x = (b + (b << 5)) + ((((d << 4) - d) + ((a << 3) + (a << 2))) >> 9) - ((c << 6) + c) + ((d << 4) - (d << 1));
	y = 33 * b + (d * 15 + 12 * a) / 512 - 65 * c + d * 14;
	std::cout << x << " " << y;
	return 0;
}