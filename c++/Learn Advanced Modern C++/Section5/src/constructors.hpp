#ifndef CONSTRUCTORS_H
#define CONSTRUCTORS_H

#include <iostream>
using namespace std;

namespace constructors
{
	class internet
	{
	public:
		void connect() { cout << "connected to the internet\n"; }
		void login(const string &id, const string &pw)
		{
			cout << "logged on with username " << id;
			cout << " and password " << pw << endl;
		}
	};

	class refrigerator
	{
		int temperature{2};
		bool door_open{false};
		bool power_on{true};
		internet internet;

	public:
		// default constructor
		refrigerator() : refrigerator(2, "me", "secret") {}

		// constructor using default login
		refrigerator(int temperature) : refrigerator(temperature, "me", "secret") {}

		// constructor using default temperature
		refrigerator(const string &id, const string &pw) : refrigerator(2, id, pw) {}

		// constructor with no defaults
		refrigerator(int temperature, const string &id, const string &pw) : temperature(temperature)
		{
			internet.connect();
			internet.login(id, pw);
		}
		void print()
		{
			cout << "temperature = " << temperature << endl;
			cout << boolalpha;
			cout << "door_open = " << door_open << endl;
			cout << "power_open = " << power_on << endl;
			cout << noboolalpha << endl;
		}
	};

	int main()
	{
		refrigerator fridge;
		fridge.print();

		return 0;
	}
}
#endif // CONSTRUCTORS_H