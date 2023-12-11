#include "logic.h"
#include <iostream>


Transistor::Transistor() {
	gate = false;
	source = false;
	drain = false;
}

Transistor::Transistor(bool source, bool gate) {
	this->source = source;
	this->gate = gate;

	gate ? drain = source : drain = false;
}

bool Transistor::GetDrain() {
	return drain;
}


void Transistor::InfoT() const {
	std::cout << "s- " << source << std::endl;
	std::cout << "g- " << gate << std::endl;
	std::cout << "d- " << drain << std::endl;
}



Transistor::~Transistor() {};



///////////////////////////////////////////////////////////////////////



LogicalGate::LogicalGate() {
	entrance = false;
	exit = false;
	//BitsArray[0] = false;
}



LogicalGate::LogicalGate(bool entrance, bool exit) {
	this->entrance = entrance;
	this->exit = exit;
}

LogicalGate::~LogicalGate() {
	delete[] BitsArray;
}


bool LogicalGate::LogicalAND(bool exit_1, bool exit_2) {
	Transistor R1(1, exit_1);
	Transistor R2(R1.GetDrain(), exit_2);

	return R2.GetDrain();
}


bool LogicalGate::LogicalOR(bool exit_1, bool exit_2) {
	Transistor R1(1, exit_1), R2(1, exit_2);


	if (R1.GetDrain()) { return 1; }
	else if (R2.GetDrain()) { return 1; }
	else { return 0; }
}

bool LogicalGate::LogicalNOT(bool exit) {
	return !exit;
}

bool LogicalGate::LogicalANDNOT(bool exit_1, bool exit_2) {	//	NAND
	return (LogicalNOT(LogicalAND(exit_1, exit_2)));
}


bool LogicalGate::LogicalXOR(bool exit_1, bool exit_2) {
	return (LogicalOR(LogicalAND(LogicalNOT(exit_2), exit_1), LogicalAND(LogicalNOT(exit_1), exit_2)));
}


bool LogicalGate::LogicalORNOT(bool exit_1, bool exit_2) {
	return (LogicalNOT(LogicalOR(exit_1, exit_2)));
}


void LogicalGate::BinaryAdder(bool term_1, bool term_2) {
	std::cout << LogicalAND(term_1, term_2);
	std::cout << LogicalXOR(term_1, term_2) << std::endl;

}


bool* LogicalGate::LogicalFullAdder(bool carry_over_from_loworder, bool term_1, bool term_2) {

	BitsArray[0] = LogicalXOR(carry_over_from_loworder, LogicalXOR(term_1, term_2));
	BitsArray[1] = LogicalOR(LogicalAND(LogicalXOR(term_1, term_2), carry_over_from_loworder), LogicalAND(term_1, term_2));
	//std::cout << BitsArray[1] << std::endl;

	return BitsArray;
}