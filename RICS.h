
/*
Ricard Alonzo Ugalde
CIS 655-Advanced Computer Architecture
Syracuse University
HW #2 - RICS Instruction Set Architecture

h. declaration file
*/

#include <iostream>
using namespace std;


class RICS
{
public: // class constructor returns nothing
	RICS(); // default constructor
	RICS(string itemPartNumber, string partDescription, int itemQuantity, double itemPrice);


public: // test function declaration
	void testyTest();

public: // private variable declarations
	
	string type;
	string opcode;
	int reg1 = 0;
	int reg2 = 0;
	int reg3 = 0;
	int reg4 = 0;
	int regResul1;
	int storedValue1 = 0;
	int storedValue2 = 0;
	int storedValue3 = 0;
	int storedValue4 = 0;
	int regArray[100] = { 0 };
	int copy = 0;
	int addResult = 0;
	int zeroCheck;
	int memArray[100];
	int i = 0;
	int* ptr;
	int j = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	
	

/*
getType Function
*/
public:
	string getType();


/*
Instruction type description declaration method
*/
public:
	void rTypeDescription();
	void iTypeDescription();
	void cTypeDescription();
	void sTypeDescription();

/*
Instruction type 
*/
public:
	void rType();
	void iType();
	void cType();
	void sType();


/*
decimal to binary conversion
*/
public:
	void decToBinary(int);


/*
Main Greeting and Program Selection:
*/

public:
	void mainGreeting();
	void secondaryGreeting();
	
	
/*
rtype instruction computation declaration
*/
public:
	int add();
	int addA();
	int addB();
	int addC();
	int sub();
	int subA();
	int subB();
	int subC();
	int mlt();
	int mltA();
	int mltB();
	int mltC();
	int div();
	int divA();
	int divB();
	int divC();
	

/*
itype instruction computation declaration
*/
public:
	bool andBool();
	bool randBool();
	bool andrBool();
	bool zeroBool();
	bool oneBool();
	bool orBool();
	bool xorBool();
	bool xnorBool();
	bool norBool();
	bool nandBool();

/*
ctype instruction computation declaration
*/
	int mod();
	int incReg1();
	int incReg2();
	int incReg3();
	int incRegs();
	int decReg1();
	int decReg2();
	int decReg3();
	int decRegs();
	int regRst();

/*
stype instructions
*/
	int memDisplay();
	int lmr1();
	int lmr2();
	int lmr3();
	int lmr4();
	int lmra();
	int wr1m();
	int wr2m();
	int wr3m();
	int wr4m();
	int wram();
	int mems();
	int mems2();
	int memrst();
	int regwrt1();
	int regwrt2();
	int regrst();

};
