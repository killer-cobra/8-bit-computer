#include <iostream>
#include "logic.h"
#define DEBUG




int main() {

	std::cout << "Hello World" << std::endl;
	Transistor bitField(1, 1);
#ifdef DEBUG
	std::cout << bitField.GetDrain();
#endif

	bitField.InfoT();

	std::cout << "--------------------" << std::endl;

	LogicalGate Logic;
	std::cout << "result: " << Logic.LogicalAND(0, 0) << std::endl;

	std::cout << "result: " << Logic.LogicalOR(1, 1) << std::endl;

	std::cout << "result: " << Logic.LogicalNOT(1) << std::endl;

	std::cout << "result: " << Logic.LogicalANDNOT(1, 0) << std::endl;

	std::cout << "result: " << Logic.LogicalXOR(1, 1) << std::endl;

	//Logic.BinaryAdder(1, 0);

	std::cout << "-----LogicalFullAdder------" << std::endl;
	bool* result = Logic.LogicalFullAdder(1, 1, 1);

	std::cout << result[0] << std::endl;
	std::cout << result[1] << std::endl;

	



	std::cout << std::endl;

	std::cout << "--------------------" << std::endl;

	std::cout << sizeof(bitField);
}