//multiply.hpp
//defines a function template for multiplication:

template <typename T>
T mult(T a, T b){
	return a * b;
}

//explicitly define mult over int and float:
template int mult<int> (int, int);
template float mult<> (float, float);
