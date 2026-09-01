#include <iostream>
using namespace std;

namespace I {
	int add(int a , int b) {
		return a + b;
		}
}

namespace F{
	float add(float a, float b){
		return a + b;
		}
	}

int main(void)
{	
	cout << "Hello world!" << endl;
	using namespace I;
	int result = add(3,2);
	using namespace std;
	cout <<"3 + 2 = " << result << endl;
	cout<<"3.2 + 2.5 = " << F::add(3.2, 2.5) << endl;
	return 0;
}

