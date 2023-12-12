#include "logic.h"
#include <iostream>
#include <ostream>


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
	delete [] BitsArray;
	delete [] Array_8bits;
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

bool* LogicalGate::Logical_8_bit_adder(bool terms_1 [8], bool terms_2[8]) {
	BitsArray = LogicalFullAdder(0, terms_1[0], terms_2[0]);

	Array_8bits[0] = LogicalFullAdder(0, terms_1[0], terms_2[0]);
	Array_8bits[1] = LogicalFullAdder( BitsArray[1], terms_1[1], terms_2[1]);

	BitsArray = LogicalFullAdder(BitsArray[1], terms_1[1], terms_2[1]);
	Array_8bits[2] = LogicalFullAdder(BitsArray[1], terms_1[2], terms_2[2]);

	BitsArray = LogicalFullAdder(BitsArray[1], terms_1[2], terms_2[2]);
	Array_8bits[3] = LogicalFullAdder(BitsArray[1], terms_1[3], terms_2[3]);

	BitsArray = LogicalFullAdder(BitsArray[1], terms_1[3], terms_2[3]);
	Array_8bits[4] = LogicalFullAdder(BitsArray[1], terms_1[4], terms_2[4]);

	BitsArray = LogicalFullAdder(BitsArray[1], terms_1[4], terms_2[4]);
	Array_8bits[5] = LogicalFullAdder(BitsArray[1], terms_1[5], terms_2[5]);

	BitsArray = LogicalFullAdder(BitsArray[1], terms_1[5], terms_2[5]);
	Array_8bits[6] = LogicalFullAdder(BitsArray[1], terms_1[6], terms_2[6]);

	BitsArray = LogicalFullAdder(BitsArray[1], terms_1[6], terms_2[6]);
	Array_8bits[7] = LogicalFullAdder(BitsArray[1], terms_1[7], terms_2[7]);


	BitsArray = LogicalFullAdder(BitsArray[1], terms_1[7], terms_2[7]);
	Array_8bits[8] = BitsArray[1];


	return Array_8bits;
}

// std::ostream& /* void */ operator <<(std::ostream& os, const bool BitArray_f[2]) {
//	return os << BitArray_f[0] << " " << BitArray_f[1];
//} 

std::ostream& operator <<(std::ostream& os, const bool Array_8bits_f[9]) {
	return os << Array_8bits_f[0] << " " << Array_8bits_f[1] << " " << Array_8bits_f[2] << " " << Array_8bits_f[3] << " " <<
	Array_8bits_f[4] << " " << Array_8bits_f[5] << " " << Array_8bits_f[6] << " " << Array_8bits_f[7] << " " << Array_8bits_f[8] << " " << Array_8bits_f[8];
}

