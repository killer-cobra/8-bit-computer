#pragma once
#ifndef LOGIC
#define LOGIC
#include <iostream>

class Transistor // МОП транзистор (MOSFET)
{
private:
	bool gate : 1;		//		Затвор (  GATE  )
	bool source : 1;	//		Исток  ( SOURSE )
	bool drain : 1;		//		Сток   ( DRAIN  )



public:
	Transistor();

	Transistor(bool source, bool gate);

	bool GetDrain();

	void InfoT() const;

	~Transistor();
};




class LogicalGate {
private:
	bool entrance : 1;	//  	Вход	( ENTRANCE )
	bool exit : 1;	//		Выход	(	EXIT   )
	bool *BitsArray = new bool[2];
	bool* Array_8bits = new bool[9];

	void BinaryAdder(bool term_1, bool term_2);

public:
	LogicalGate();

	LogicalGate(bool entrance, bool exit);

	~LogicalGate();

	bool LogicalAND(bool exit_1, bool exit_2);

	bool LogicalOR(bool exit_1, bool exit_2);

	bool LogicalNOT(bool exit);

	bool LogicalANDNOT(bool exit_1, bool exit_2);	//	NAND

	bool LogicalXOR(bool exit_1, bool exit_2);

	bool LogicalORNOT(bool exit_1, bool exit_2);

	bool* LogicalFullAdder(bool term_1, bool term_2, bool term_3);



	bool* Logical_8_bit_adder(bool [8], bool [8]);
};

//std::ostream& /* void */ operator << (std::ostream &os, const bool[2]);

std::ostream& operator << (std::ostream& os, const bool[9]);


#endif
