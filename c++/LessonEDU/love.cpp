#include <iostream>
#include <string>

using namespace std;

int main(void){

int max = 10;

int lovebox[] = {1, 2, 3, 4, 5, 6};

//foreach(int i in lovebox)
for(int i : lovebox){
	cout << "LOVE from foreach ^ " << i << endl;
}

for(int i = 0; i < max; i++){
	cout << "LOVE from for" << endl;
}

int amount = 0;

while(amount < max) {
	cout << "LOVE from while" << endl;
	amount++;
}

amount = 0;
do{
	cout << "LOVE from do" << endl;
	amount++;
} while(amount < max);

}
