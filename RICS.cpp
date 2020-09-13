/*
Ricard Alonzo Ugalde
CIS 655-Advanced Computer Architecture
Syracuse University
HW #2 - RICS Instruction Set Architecture

.cpp implementation file
*/

#include "RICS.h" // header file in local directory
#include <iostream> // header in standard library
#include <iomanip>

using namespace std; // avoid having to qualify every mention of cout, cin, endl, etc.

// implementataion of the function testyTest from invoice.h to testy test things
void RICS::testyTest()
{
	cout << "Testing, testing. This is the testy test." << endl;
}


/*
invoice class constructors because it returns nothing and its named just like th class.
*/
RICS::RICS() // default constructor
{
	cout << endl;

}
RICS::RICS(string itemPartNumber, string itemPartDescription, int itemQuantity, double itemPrice)
{
	
}


/*
get Type of instruction
*/
string RICS::getType()
{
	return type;
}

/*
User prompts and gretings
*/
void RICS::mainGreeting()
{
	cout << "*		Hello There! Welcome to RICS Instruction Set Architecture	**\n\n";
	cout << "*		Please Enter a desired instruction type code, or		**" << endl;
	cout << "*		Enter 2 for a complete list of instructions available.		**" << endl;

	return;
}
void RICS::secondaryGreeting()
{
	cout << "Please Enter a desired instruction type code: \n" << endl;
	cout << "enter 'main' to return to main menue \n" << endl;
	cin >> type;
	if (type == "r" || type == "00")
	{
		rType();
	}
	else if (type == "i" || type == "01")
	{
		iType();
	}
	else if (type == "c" || type == "10")
	{
		cType();
	}
	else if (type == "s" || type == "11")
	{
		sType();
	}
	else if (type == "main")
	{
		return mainGreeting();
	}

	return;
}

/*
Instruction type Descrption Implementation
*/
void RICS::rTypeDescription()
{
	cout << " R-Type Instruction\n" << endl;
	cout << " Adds the contents of two registers" << endl;
	cout << " and stores the value in a third register.\n" << endl;
	cout << " | 00 | 000000 |0000|0000|0000|" << endl;
	cout << " |type| op-code| $d | $s | $t |\n" << endl;
		
	return;
}
void RICS::iTypeDescription()
{
	cout << " I-Type Instruction\n" << endl;
	cout << " Adds the contents of two registers" << endl;
	cout << " and stores the value in a third register.\n" << endl;
	cout << " | 01 | 000000 |0000|0000|0000|OOOO|" << endl;
	cout << " |type| op-code|reg1|reg2|reg3|reg4|\n" << endl;

	return;
}
void RICS::cTypeDescription()
{
	cout << " C-Type Instruction\n" << endl;
	cout << " Adds the contents of two registers" << endl;
	cout << " and stores the value in a third register.\n" << endl;
	cout << " | 10 | 000000 |0000|0000|0000|OOOO|" << endl;
	cout << " |type| op-code|reg1|reg2|reg3|reg4|\n" << endl;

	return;
}
void RICS::sTypeDescription()
{
	cout << " S-Type Instruction\n" << endl;
	cout << " Adds the contents of two registers" << endl;
	cout << " and stores the value in a third register.\n" << endl;
	cout << " | 11 | 000000 |0000|0000|0000|OOOO|" << endl;
	cout << " |type| op-code|reg1|reg2|reg3|reg4|\n" << endl;

	return;
}

/*
Instruction selection implementation
*/

void RICS::rType()
{
	cout << "R-type instrictions selected. " << endl;
	cout << "Please enter a six bit operation code, or instruction name: \n";
	cin >> opcode;
		if( opcode == "add" || opcode == "000000" )
		{
			cout << "Add selected. $d = $s + $t\n" << endl;
			add();
		}

		else if (opcode == "addA" || opcode == "000001")
		{
			cout << "add-A selected. R1+R2 = R3 and R4." << endl;
			addA();
		}


		else if (opcode == "addB" || opcode == "000010")
		{
			cout << "add-B selected. R1+R2+R3 = R4.\n" << endl;
			addB();
		}

		else if (opcode == "addC" || opcode == "000011")
		{
			cout << "add-C selected. R3+R4 = R4.\n" << endl;
			addC();
		}
		
		else if (opcode == "sub" || opcode == "000100")
		{
			cout << "Sub selected. $d = $s + $t\n" << endl;
			sub();
		}

		else if (opcode == "subA" || opcode == "000101")
		{
			cout << "sub-A selected. R1-R2 = R3 and R4." << endl;
			subA();
		}

		else if (opcode == "subB" || opcode == "000110")
		{
			cout << "sub-B selected. R1-R2-R3 = R4." << endl;
			subB();
		}

		else if (opcode == "subC" || opcode == "000111")
		{
			cout << "sub-C selected. R3-R4 = R4.\n" << endl;
			subC();
		}

		else if (opcode == "mlt" || opcode == "001000")
		{
			cout << "Mlt selected. R1*R2 = R3\n" << endl;
			mlt();
		}

		else if (opcode == "mltA" || opcode == "001001")
		{
			cout << "mlt-A selected. R1*R2 = R3 and R4." << endl;
			mltA();
		}

		else if (opcode == "mltB" || opcode == "001010")
		{
			cout << "mlt-B selected. R1*R2*R3 = R4." << endl;
			mltB();
		}

		else if (opcode == "mltC" || opcode == "001011")
		{
			cout << "mult-C selected. R3*R4 = R4.\n" << endl;
			mltC();
		}

		else if (opcode == "div" || opcode == "001100")
		{
			cout << "Div selected. R1/R2 = R3\n" << endl;
			div();
		}

		else if (opcode == "divA" || opcode == "001101")
		{
			cout << "div-A selected. R1/R2 = R3 and R4." << endl;
			divA();
		}

		else if (opcode == "divB" || opcode == "001110")
		{
			cout << "div-B selected. R4/R3 = R3." << endl;
			divB();
		}

		else if (opcode == "divC" || opcode == "001111")
		{
			cout << "div-C selected. R3/R4 = R4.\n" << endl;
			divC();
		}

		else  
		{
			rType();
		}
}
void RICS::iType()
{	
	cout << "I-type instrictions selected. " << endl;
	cout << "Please enter a six bit operation code, or instruction name: \n";
	cin >> opcode;
	if (opcode == "and" || opcode == "010000")
	{
		cout << "And selected. R1 && R2 = R3\n" << endl;
		andBool();
	}

	else if (opcode == "rand" || opcode == "010001")
	{
		cout << "Rand selected. R1 && -R2 = R3\n" << endl;
		randBool();
	}

	else if (opcode == "andr" || opcode == "100010")
	{
		cout << "Andr selected. -R1 && R2 = R3\n" << endl;
		andrBool();
	}

	else if (opcode == "zero" || opcode == "100011")
	{
		cout << "Zeroes selected. R_n = 0\n" << endl;
		zeroBool();
	}

	else if (opcode == "one" || opcode == "010101")
	{
		cout << "Ones selected. R_n = 1\n" << endl;
		oneBool();
	}

	else if (opcode == "or" || opcode == "010100")
	{
		cout << "Or selected. R1 || R2 = R3\n" << endl;
		orBool();
	}

	else if (opcode == "xor" || opcode == "011110")
	{
		cout << "Xor selected. R1 = 0 || R2 = 0 : R3 = 0\n" << endl;
		cout << "Xor selected. R1 = 1 || R2 = 1 : R3 = 1\n" << endl;
		cout << "Xor selected. R1 = 1 || R2 = 0 : R3 = 1\n" << endl;
		cout << "Xor selected. R1 = 1 || R2 = 1 : R3 = 0\n" << endl;
		xorBool();
	}

	else if (opcode == "xnor" || opcode == "010110")
	{
		cout << "Xnor selected. R1 = 0 || R2 = 0 : R3 = 1\n" << endl;
		cout << "Xnor selected. R1 = 1 || R2 = 1 : R3 = 0\n" << endl;
		cout << "Xnor selected. R1 = 1 || R2 = 0 : R3 = 0\n" << endl;
		cout << "Xnor selected. R1 = 1 || R2 = 1 : R3 = 1\n" << endl;
		xnorBool();
	}

	else if (opcode == "nor" || opcode == "011000")
	{
		cout << "Nor selected. R1 = 0 || R2 = 0 : R3 = 1\n" << endl;
		cout << "Nor selected. R1 = 0 || R2 = 1 : R3 = 0\n" << endl;
		cout << "Nor selected. R1 = 1 || R2 = 0 : R3 = 0\n" << endl;
		cout << "Nor selected. R1 = 1 || R2 = 1 : R3 = 0\n" << endl;
		norBool();
	}

	else if (opcode == "nand" || opcode == "011001")
	{
		cout << "Nand selected. R1 = 0 || R2 = 0 : R3 = 1\n" << endl;
		cout << "Nand selected. R1 = 0 || R2 = 1 : R3 = 1\n" << endl;
		cout << "Nand selected. R1 = 1 || R2 = 0 : R3 = 1\n" << endl;
		cout << "Nand selected. R1 = 1 || R2 = 1 : R3 = 0\n" << endl;
		nandBool();
	}


	else
	{
		iType();
	}

}
void RICS::cType()
{
	cout << "C-type instrictions selected. " << endl;
	cout << "Please enter a six bit operation code, or instruction name: \n";
	cin >> opcode;
	if (opcode == "mod" || opcode == "100000")
	{
		cout << "Modulus selected. R1 % R2 = R3\n" << endl;
		mod();
	}

	else if (opcode == "increg1" || opcode == "100001")
	{
		cout << "Increase Reg1 selected. R1++\n"  << endl;
		incReg1();
	}
	else if (opcode == "increg2" || opcode == "100010")
	{
		cout << "Increase Reg2 selected. R2++\n" << endl;
		incReg2();
	}
	else if (opcode == "increg3" || opcode == "100011")
	{
		cout << "Increase Reg3 selected. R3++\n" << endl;
		incReg3();
	}
	else if (opcode == "incregs" || opcode == "100100")
	{
		cout << "Increase Regs selected. R1++, R2++, R3++, R4++\n" << endl;
		incRegs();
	}

	else if (opcode == "decreg1" || opcode == "100101")
	{
		cout << "Decrease Reg1 selected. R1--\n" << endl;
		decReg1();
	}
	else if (opcode == "decreg2" || opcode == "100110")
	{
		cout << "Decrease Reg2 selected. R2--\n" << endl;
		decReg2();
	}
	else if (opcode == "increg3" || opcode == "100111")
	{
		cout << "Decrease Reg3 selected. R3--\n" << endl;
		decReg3();
	}
	else if (opcode == "decregs" || opcode == "101000")
	{
		cout << "Decrease Regs selected. R1--, R2--, R3--, R4--\n" << endl;
		decRegs();
	}

	else if (opcode == "101001" || opcode == "regrst")
	{
		cout << "Resets all registers. " << endl;
		regrst();
	}

	else
	{
		cType();
	}

}
void RICS::sType()
{	
	
	cout << "S-type instrictions selected. " << endl;
	cout << "Please enter a six bit operation code, or instruction name: \n";
	cin >> opcode;
	if (opcode == "110000" || opcode == "lmr1" || opcode == "loadmem")
	{
		cout << "Load from memory into register1 selected: " << endl;
		lmr1();
	}

	else if (opcode == "111010" || opcode == "memdisplay")
	{
		cout << "Display memory selected. \n" << endl;
		memDisplay();
	}

	else if (opcode == "110001" || opcode == "lmr2")
	{
		cout << "Load from memory into register2 selected: " << endl;
		lmr2();
	}

	else if (opcode == "110010" || opcode == "lmr3")
	{
		cout << "Load from memory into register3 selected: " << endl;
		lmr3();
	}
	else if (opcode == "110011" || opcode == "lmr4")
	{
		cout << "Load from memory into register3 selected: " << endl;
		lmr4();
	}

	else if (opcode == "110100" || opcode == "lmra")
	{
		cout << "Load from memory into all register selected: " << endl;
		lmra();
	}

	else if (opcode == "110101" || opcode == "wr1m")
	{
		cout << "Write to memoray location from register1: " << endl;
		wr1m();
	}

	else if (opcode == "110110" || opcode == "wr2m")
	{
		cout << "Write to memoray location from register2: " << endl;
		wr2m();
	}

	else if (opcode == "110111" || opcode == "wr3m")
	{
		cout << "Write to memoray location from register3: " << endl;
		wr3m();
	}
	else if (opcode == "111000" || opcode == "wr4m")
	{
		cout << "Write to memoray location from register4: " << endl;
		wr4m();
	}
	else if (opcode == "111001" || opcode == "wram")
	{
		cout << "Write to memoray location from all 4 registers: " << endl;
		wr4m();
	}

	else if (opcode == "111011" || opcode == "mems")
	{
		cout << "Writes immediate value to memeroy location: " << endl;
		mems();
	}

	else if (opcode == "111100" || opcode == "mem2")
	{
		cout << "Writes immediate value to memeroy location2: " << endl;
		mems2();
	}

	else if (opcode == "111101" || opcode == "memrst")
	{
		cout << "Erases desired memory location " << endl;
		memrst();
	}
	else if (opcode == "111110" || opcode == "regwrt1")
	{
		cout << "Writes immediate value to reg1 " << endl;
		regwrt1();
	}

	else if (opcode == "111011" || opcode == "regwrt2")
	{
		cout << "Writes immediate value to reg1 " << endl;
		regwrt2();
	}


	else
	{
		sType();
	}
}


/*
Decimal to Binary Conversion
*/
void RICS::decToBinary(int n)
{
	// Size of an integer is assumed to be 32 bits 
	for (int i = 15; i >= 0; i--) {
		int k = n >> i;
		if (k & 1)
			cout << "1";
		else
			cout << "0";
	}

}


/*
Rtype instruction computation implementation
*/
int RICS::add()
{
	
	cout << "enter first operand: " << endl;
	cin >> storedValue1;
	cout << "select register 1-10: $s";
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand: " << endl;
	cin >> storedValue2;
	cout << "select register 1-10: $t";
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select destination register: $d ";
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue1 + storedValue2;
	
	
	cout << "\n";

	cout << " | 00  | 000000 |"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      $d         |	$s        |	$t         |   	\n\n\n" << endl;
	
	
	
	cout << reg1 <<		"\t |" << storedValue1 <<	"\t\t  |" << &regArray[reg1] <<	"\t    |" << endl;
	cout << reg2 <<		"\t |" << storedValue2 <<	"\t\t  |" << &regArray[reg2] <<	"\t    |" << endl;
	cout << reg3 <<		"\t |" << storedValue3 <<	"\t\t  |" << &regArray[reg3] <<	"\t    |" << endl;
	cout << reg4 <<		"\t |" << storedValue4 <<	"\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();

	
	return 0;
}
int RICS::addA()
{
	cout << "enter first operand: " << endl;
	cin >> storedValue1;
	cout << "select register 1-10: $s";
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand: " << endl;
	cin >> storedValue2;
	cout << "select register 1-10: $t";
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select destination register: $d ";
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue1 + storedValue2;


	cout << "\n";

	cout << " | 00  | 000001 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue3); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();

	
	return 0;
}
int RICS::addB()
{
	cout << "enter first operand" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "enter third operand" << endl;
	cin >> storedValue4;
	cout << "select register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue1 + storedValue2 + storedValue4;


	cout << "\n";

	cout << " | 00  | 000010 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	op3 	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	
	secondaryGreeting();


	return 0;
}
int RICS::addC()
{
	cout << "enter first operand" << endl;
	cin >> storedValue3;
	cout << "select register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	cout << "enter second operand" << endl;
	cin >> storedValue4;
	cout << "select register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;

		
	storedValue3 = storedValue3 + storedValue4;


	cout << "\n";

	cout << " | 00  | 000011 |"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(0); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	op3 	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();


	return 0;
}

int RICS::sub()
{

	cout << "enter first operand: " << endl;
	cin >> storedValue1;
	cout << "select register 1-10: $s";
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand: " << endl;
	cin >> storedValue2;
	cout << "select register 1-10: $t";
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select destination register: $d ";
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue1 - storedValue2;


	cout << "\n";

	cout << " | 00  | 000001 |"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      $d         |	$s        |	$t         |   	\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}

int RICS::subA()
{
	cout << "enter first operand" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue1 - storedValue2;


	cout << "\n";

	cout << " | 00  | 000101 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue3); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}
int RICS::subB()
{
	cout << "enter first operand" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "enter third operand" << endl;
	cin >> storedValue4;
	cout << "select register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue1 - storedValue2 - storedValue4;


	cout << "\n";

	cout << " | 00  | 000110 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	op3 	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();


	return 0;
}
int RICS::subC()
{
	cout << "enter first operand" << endl;
	cin >> storedValue3;
	cout << "select register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	cout << "enter second operand" << endl;
	cin >> storedValue4;
	cout << "select register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;


	storedValue3 = storedValue3 - storedValue4;


	cout << "\n";

	cout << " | 00  | 000111 |"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(0); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	op3 	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();


	return 0;
}
int RICS::mlt()
{
	
	cout << "enter first operand" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue1 * storedValue2;


	cout << "\n";

	cout << " | 00  | 001000 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t	 |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}
int RICS::mltA()
{
	cout << "enter first operand" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue1 * storedValue2;


	cout << "\n";

	cout << " | 00  | 001001 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue3); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}
int RICS::mltB()
{
	cout << "enter first operand" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "enter third operand" << endl;
	cin >> storedValue4;
	cout << "select register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue1 * storedValue2 * storedValue4;


	cout << "\n";

	cout << " | 00  | 001010 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	op3 	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();


	return 0;
}
int RICS::mltC()
{
	cout << "enter first operand" << endl;
	cin >> storedValue3;
	cout << "select register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	cout << "enter second operand" << endl;
	cin >> storedValue4;
	cout << "select register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;


	storedValue3 = storedValue3 * storedValue4;


	cout << "\n";

	cout << " | 00  | 001011 |"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(0); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	op3 	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();


	return 0;
}
int RICS::div()
{

	cout << "enter first operand" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue1 / storedValue2;


	cout << "\n";

	cout << " | 00  | 001100 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t	 |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}
int RICS::divA()
{
	cout << "enter first operand" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue1 / storedValue2;


	cout << "\n";

	cout << " | 00  | 001101 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue3); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}
int RICS::divB()
{
	cout << "enter first operand" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;
		
	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue4 / storedValue3;


	cout << "\n";

	cout << " | 00  | 001010 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	op3 	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();


	return 0;
}
int RICS::divC()
{
	cout << "enter first operand" << endl;
	cin >> storedValue3;
	cout << "select register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	cout << "enter second operand" << endl;
	cin >> storedValue4;
	cout << "select register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;


	storedValue3 = storedValue4 / storedValue3;


	cout << "\n";

	cout << " | 00  | 001111 |"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(0); cout << "|"; cout << endl;
	cout << " |Rtype| op-code|      op 1      |	op2       |	result     |   	op3 	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();


	return 0;
}


/*
Itype instruction computation declaration
*/
bool RICS::andBool()
{
	
	cout << "enter first operand 0 or 1" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand 0 or 1" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	if (storedValue1 == 1 && storedValue2 == 1)
	{
		storedValue3 = 1;
	}
	else
	{
		storedValue3 = 0;
	}
	


	cout << "\n";

	cout << " | 01  | 010000 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
	cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();



	return 0;
}
bool RICS::randBool()
{

	cout << "enter first operand 0 or 1" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand 0 or 1" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	if (storedValue1 == 1 && storedValue2 == 0)
	{
		storedValue3 = 1;
	}
	else
	{
		storedValue3 = 0;
	}



	cout << "\n";

	cout << " | 01  | 010001 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
	cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();



	return 0;
}
bool RICS::andrBool()
{

	cout << "enter first operand 0 or 1" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand 0 or 1" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	if (storedValue1 == 0 && storedValue2 == 1)
	{
		storedValue3 = 1;
	}
	else
	{
		storedValue3 = 0;
	}



	cout << "\n";

	cout << " | 01  | 010010 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
	cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();



	return 0;
}
bool RICS::zeroBool()
{

	cout << "Set all all registers to 0? Enter 1 for yes, 0 for no.\n" << endl;
	cin >> zeroCheck;

	if (zeroCheck == 1)
	{
		cout << "All registers set to 0\n" << endl;
		storedValue1 = 0;
		storedValue2 = 0;
		storedValue3 = 0;
		storedValue4 = 0;

		cout << "\n";

		cout << " | 01  | 010011 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}
	else
	{
		cout << "select register 1-60 to set to 0" << endl;
		cin >> reg1;
		regArray[reg1] = storedValue1;


		cout << "select register 1-60 to set to 0" << endl;
		cin >> reg2;
		regArray[reg2] = storedValue2;

		cout << "select register 1-60 to set to 0" << endl;
		cin >> reg3;
		regArray[reg3] = storedValue3;

		
		cout << " | 01  | 010011 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();
	}


	return 0;
}
bool RICS::oneBool()
{

	cout << "Set all all registers to 1? Enter 1 for yes, 0 for no.\n" << endl;
	cin >> zeroCheck;

	if (zeroCheck == 1)
	{
		cout << "All registers set to 1\n" << endl;
		storedValue1 = 1;
		storedValue2 = 1;
		storedValue3 = 1;
		storedValue4 = 1;

		cout << "\n";

		cout << " | 01  | 010011 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}
	else
	{
		cout << "select register 1-60 to set to 0" << endl;
		cin >> reg1;
		regArray[reg1] = storedValue1;


		cout << "select register 1-60 to set to 0" << endl;
		cin >> reg2;
		regArray[reg2] = storedValue2;

		cout << "select register 1-60 to set to 0" << endl;
		cin >> reg3;
		regArray[reg3] = storedValue3;


		cout << " | 01  | 010101 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();
	}


	return 0;
}
bool RICS::orBool()
{

	cout << "enter first operand 0 or 1" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand 0 or 1" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	if (storedValue1 == 1 || storedValue2 == 1)
	{
		storedValue3 = 1;
	}
	else
	{
		storedValue3 = 0;
	}



	cout << "\n";

	cout << " | 01  | 010100 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
	cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();



	return 0;
}
bool RICS::xnorBool()
{

	cout << "enter first operand 0 or 1" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand 0 or 1" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	if (storedValue1 == 0 || storedValue2 == 0)
	{
		storedValue3 = 1;

		cout << "\n";

		cout << " | 01  | 010110 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();


	}
	
	else if(storedValue1 == 0 || storedValue2 == 1)
	{
		storedValue3 = 0;

		cout << "\n";

		cout << " | 01  | 010110 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}

	else if (storedValue1 == 1 || storedValue2 == 0)
	{
		storedValue3 = 0;

		cout << "\n";

		cout << " | 01  | 010110 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}

	else if (storedValue1 == 1 || storedValue2 == 1)
	{
		storedValue3 = 1;

		cout << "\n";

		cout << " | 01  | 010110 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}
	



	return 0;
}
bool RICS::xorBool()
{

	cout << "enter first operand 0 or 1" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand 0 or 1" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	if (storedValue1 == 0 || storedValue2 == 0)
	{
		storedValue3 = 0;

		cout << "\n";

		cout << " | 01  | 011110 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();


	}
	
	else if(storedValue1 == 0 || storedValue2 == 1)
	{
		storedValue3 = 1;

		cout << "\n";

		cout << " | 01  | 011110 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}

	else if (storedValue1 == 1 || storedValue2 == 0)
	{
		storedValue3 = 0;

		cout << "\n";

		cout << " | 01  | 011110 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}

	else if (storedValue1 == 1 || storedValue2 == 1)
	{
		storedValue3 = 0;

		cout << "\n";

		cout << " | 01  | 011110 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}
	



	return 0;
}
bool RICS::norBool()
{

	cout << "enter first operand 0 or 1" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand 0 or 1" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	if (storedValue1 == 0 || storedValue2 == 0)
	{
		storedValue3 = 1;

		cout << "\n";

		cout << " | 01  | 011000 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();


	}

	else if (storedValue1 == 0 || storedValue2 == 1)
	{
		storedValue3 = 0;

		cout << "\n";

		cout << " | 01  | 011000 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}

	else if (storedValue1 == 1 || storedValue2 == 0)
	{
		storedValue3 = 0;

		cout << "\n";

		cout << " | 01  | 011000 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}

	else if (storedValue1 == 1 || storedValue2 == 1)
	{
		storedValue3 = 0;

		cout << "\n";

		cout << " | 01  | 011000 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}




	return 0;
}
bool RICS::nandBool()
{

	cout << "enter first operand 0 or 1" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand 0 or 1" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	if (storedValue1 == 0 && storedValue2 == 0)
	{
		storedValue3 = 1;

		cout << "\n";

		cout << " | 01  | 011001 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();


	}

	else if (storedValue1 == 0 && storedValue2 == 1)
	{
		storedValue3 = 1;

		cout << "\n";

		cout << " | 01  | 011001 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}

	else if (storedValue1 == 1 && storedValue2 == 0)
	{
		storedValue3 = 1;

		cout << "\n";

		cout << " | 01  | 011001 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}

	else if (storedValue1 == 1 && storedValue2 == 1)
	{
		storedValue3 = 0;

		cout << "\n";

		cout << " | 01  | 011001 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
		cout << " |Itype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



		cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
		cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
		cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
		cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
		cout << "Register | Register Value | Register Address|" << endl;
		cout << "\n";

		secondaryGreeting();

	}




	return 0;
}


/*
Ctype instruction computation declaration
*/
int RICS::mod()
{
	
	cout << "enter first operand" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	cout << "enter second operand" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;

	cout << "select operand result register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;

	storedValue3 = storedValue1 % storedValue2;


	cout << "\n";

	cout << " | 00  | 100000 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
	cout << " |Ctype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}
int RICS::incReg1()
{

	/*cout << "enter desired register value:" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;

	
	cout << "select operand result register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;*/

	storedValue1 = storedValue1 + 1;


	cout << "\n";

	cout << " | 10  | 100001 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Ctype| op-code|      op 1      |	op2       |	copy       |   result	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	
	secondaryGreeting();


	return 0;
}
int RICS::incReg2()
{

	cout << "enter desired register value:" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;


	cout << "select operand result register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;

	storedValue4 = storedValue2 + 1;


	cout << "\n";

	cout << " | 10  | 100010 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Ctype| op-code|      op 1      |	op2       |	copy       |   result	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();


	return 0;
}
int RICS::incReg3()
{

	cout << "enter desired register value:" << endl;
	cin >> storedValue3;
	cout << "select register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;


	cout << "select operand result register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;

	storedValue4 = storedValue3 + 1;


	cout << "\n";

	cout << " | 10  | 100011 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Ctype| op-code|      op 1      |	op2       |	copy       |   result	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}
int RICS::incRegs()
{
	cout << "enter desired register value:" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;
	storedValue1 = storedValue1 + 1;

	cout << "enter desired register value:" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;
	storedValue2 = storedValue2 + 1;

	cout << "enter desired register value:" << endl;
	cin >> storedValue3;
	cout << "select register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;
	storedValue3 = storedValue3 + 1;

	cout << "enter desired register value:" << endl;
	cin >> storedValue4;
	cout << "select register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;
	storedValue4 = storedValue4 + 1;

	

	cout << "\n";

	cout << " | 10  | 100100 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Ctype| op-code|      op 1      |	op2       |	op3        |   op4	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}
int RICS::decReg1()
{

	cout << "enter desired register value:" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;


	cout << "select operand result register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;

	storedValue4 = storedValue1 - 1;


	cout << "\n";

	cout << " | 10  | 100101 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Ctype| op-code|      op 1      |	op2       |	copy       |   result	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}
int RICS::decReg2()
{

	/*cout << "enter desired register value:" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;


	cout << "select operand result register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;*/

	storedValue2 = storedValue2 - 1;


	cout << "\n";

	cout << " | 10  | 100110 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Ctype| op-code|      op 1      |	op2       |	copy       |   result	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";

	secondaryGreeting();


	return 0;
}
int RICS::decReg3()
{

	cout << "enter desired register value:" << endl;
	cin >> storedValue3;
	cout << "select register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;


	cout << "select operand result register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;

	storedValue4 = storedValue3 - 1;


	cout << "\n";

	cout << " | 10  | 100111 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Ctype| op-code|      op 1      |	op2       |	copy       |   result	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}
int RICS::decRegs()
{
	cout << "enter desired register value:" << endl;
	cin >> storedValue1;
	cout << "select register 1-60" << endl;
	cin >> reg1;
	regArray[reg1] = storedValue1;
	storedValue1 = storedValue1 - 1;

	cout << "enter desired register value:" << endl;
	cin >> storedValue2;
	cout << "select register 1-60" << endl;
	cin >> reg2;
	regArray[reg2] = storedValue2;
	storedValue2 = storedValue2 - 1;

	cout << "enter desired register value:" << endl;
	cin >> storedValue3;
	cout << "select register 1-60" << endl;
	cin >> reg3;
	regArray[reg3] = storedValue3;
	storedValue3 = storedValue3 - 1;

	cout << "enter desired register value:" << endl;
	cin >> storedValue4;
	cout << "select register 1-60" << endl;
	cin >> reg4;
	regArray[reg4] = storedValue4;
	storedValue4 = storedValue4 - 1;



	cout << "\n";

	cout << " | 10  | 101000 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Ctype| op-code|      op 1      |	op2       |	op3        |   op4	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}
int RICS::regrst()
{
	reg1 = 0;
	reg2 = 0;
	reg3 = 0;
	reg4 = 0;
	storedValue1 = 0;
	storedValue2 = 0;
	storedValue3 = 0;
	storedValue4 = 0;


	cout << "All registers reset.\n";

	cout << " | 10  | 101001 |"; decToBinary(0); cout << "|"; decToBinary(0); cout << "|"; decToBinary(0); cout << "|"; decToBinary(0); cout << "|"; cout << endl;
	cout << " |Ctype| op-code|      op 1      |	op2       |	op3        |   op4	    |\n\n\n" << endl;



	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2+1] << "\t    |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3+2] << "\t    |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4+3] << "\t    |" << endl;
	cout << "Register | Register Value | Register Address|" << endl;
	cout << "\n";
	secondaryGreeting();


	return 0;
}


/*
Stype instruction computation declaration
*/
int RICS::memDisplay()
{
	
	
	size_t n = sizeof(memArray) / sizeof(memArray[0]);

	// loop through the elements of the array
	for (size_t i = 0; i < n; i++) 
	{
		if (i > 0 && i % 2 == 1)
		{ 
			
			cout << "Memory address location " << i << ":" << setw(5) << &memArray[i];
		}
		else
		{
			cout << "Memory address location " << i << ":" << setw(5) << &memArray[i];
		}

		cout << endl;
			
	}
	

	
	secondaryGreeting();


	return 0;
}
int RICS::lmr1()
{
	cout << "Select Memory location to load from 0-99" << endl;
	cin >> i;
	memArray[50] = 10; // test value
	ptr = &memArray[i];
	cout << "The value  at memory location " << i << " is: " << memArray[i] << "\n"<< endl;

	cout << "Select register to store value from memory location " << i << "\n" << endl;
	cin >> reg1;
	regArray[reg1] = memArray[i];
	storedValue1 = regArray[reg1];
			
	cout << "\n";

	cout << " | 11  | 110000 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i] << "\t     |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i +1] << "\t     |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i +2] << "\t     |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i +3] << "\t     |" << endl;
	cout << "Register | Register Value | Register Address| Memory Address |" << endl;
	cout << "\n";

	cout << "Memory address location " << i << ":" << setw(5) << &memArray[i];

	secondaryGreeting();

	return 0;
}
int RICS::lmr2()
{
	cout << "Select Memory location to load from 0-99" << endl;
	cin >> i;
	memArray[50] = 10; // test value
	ptr = &memArray[i];
	cout << "The value  at memory location " << i << " is: " << memArray[i] << "\n" << endl;

	cout << "Select register to store value from memory location " << i << "\n" << endl;
	cin >> reg2;
	regArray[reg2] = memArray[i];
	storedValue2 = regArray[reg2];

	cout << "\n";

	cout << " | 11  | 110001 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i -1] << "\t     |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i] << "\t     |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 1] << "\t     |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 2] << "\t     |" << endl;
	cout << "Register | Register Value | Register Address| Memory Address |" << endl;
	cout << "\n";

	cout << "Memory address location " << i << ":" << setw(5) << &memArray[i];

	secondaryGreeting();

	return 0;
}
int RICS::lmr3()
{
	cout << "Select Memory location to load from 0-99" << endl;
	cin >> i;
	memArray[50] = 10; // test value
	ptr = &memArray[i];
	cout << "The value  at memory location " << i << " is: " << memArray[i] << "\n" << endl;

	cout << "Select register to store value from memory location " << i << "\n" << endl;
	cin >> reg3;
	regArray[reg3] = memArray[i];
	storedValue3 = regArray[reg3];

	cout << "\n";

	cout << " | 11 | 110010 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i - 1] << "\t     |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i] << "\t     |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 1] << "\t     |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 2] << "\t     |" << endl;
	cout << "Register | Register Value | Register Address| Memory Address |" << endl;
	cout << "\n";

	

	secondaryGreeting();

	return 0;
}
int RICS::lmr4()
{
	cout << "Select Memory location to load from 0-99" << endl;
	cin >> i;
	memArray[50] = 10; // test value
	ptr = &memArray[i];
	cout << "The value  at memory location " << i << " is: " << memArray[i] << "\n" << endl;

	cout << "Select register to store value from memory location " << i << "\n" << endl;
	cin >> reg4;
	regArray[reg4] = memArray[i];
	storedValue4 = regArray[reg4];

	cout << "\n";

	cout << " | 11 | 110010 |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(reg4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i - 1] << "\t     |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i] << "\t     |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 1] << "\t     |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 2] << "\t     |" << endl;
	cout << "Register | Register Value | Register Address| Memory Address |" << endl;
	cout << "\n";

	

	secondaryGreeting();

	return 0;
}
int RICS::lmra()
{
	cout << "Select Memory location to load from 0-99" << endl;
	cin >> i;
	memArray[50] = 10; // test value
	ptr = &memArray[i];
	cout << "The value  at memory location " << i << " is: " << memArray[i] << "\n" << endl;

	
	regArray[reg4] = memArray[i];
	storedValue4 = regArray[reg4];
	storedValue1 = regArray[reg4];
	storedValue2 = regArray[reg4];
	storedValue3 = regArray[reg4];
	cout << "\n";

	cout << " | 11 | 110100  |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i - 1] << "\t     |" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i] << "\t     |" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 1] << "\t     |" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 2] << "\t     |" << endl;
	cout << "Register | Register Value | Register Address| Memory Address |" << endl;
	cout << "\n";



	secondaryGreeting();

	return 0;
}

int RICS::wr1m()
{
	cout << "Select Register:\n" << endl;
	cin >> reg1;
	cout << "Enter register value:\n " << endl;
	cin >> j;
	storedValue1 = j;
		
	cout << "Select Memory location to write to 0-99" << endl;
	cin >> i;

	memArray[i] = storedValue1;

	cout << memArray[i] << "\n" << endl;

		
	
	cout << "The value  at memory location " << i << " is: " << memArray[i] << "\n" << endl;
	cout << "\n";

	cout << " | 11 | 110100  |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i] << "\t     |" << memArray[i] << "\n"  << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i+1] <<	   "\t     |" << memArray[x] << "\n"  << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i+2] << "\t     |" << memArray[y] << "\n"  << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i+3] << "\t     |" << memArray[z] << "\n"  << endl;
	cout << "Register | Register Value | Register Address| Memory Address | Memory Value " << endl;
	cout << "\n";



	secondaryGreeting();

	return 0;
}
int RICS::wr2m()
{
	cout << "Select Register:\n" << endl;
	cin >> reg2;
	cout << "Enter register value:\n " << endl;
	cin >> j;
	storedValue2 = j;

	cout << "Select Memory location to write to 0-99" << endl;
	cin >> x;

	memArray[x] = storedValue2;

	cout << memArray[x] << "\n" << endl;



	cout << "The value  at memory location " << x << " is: " << memArray[x] << "\n" << endl;
	cout << "\n";

	cout << " | 11 | 110110  |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i - 1] << "\t     |" << memArray[i] << "\n" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i] << "\t     |" << memArray[x] << "\n" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 1] << "\t     |" << memArray[y] << "\n" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 2] << "\t     |" << memArray[z] << "\n" << endl;
	cout << "Register | Register Value | Register Address| Memory Address | Memory Value " << endl;
	cout << "\n";



	secondaryGreeting();

	return 0;
}
int RICS::wr3m()
{
	cout << "Select Register:\n" << endl;
	cin >> reg3;
	cout << "Enter register value:\n " << endl;
	cin >> j;
	storedValue3 = j;

	cout << "Select Memory location to write to 0-99" << endl;
	cin >> y;

	memArray[y] = storedValue3;

	cout << memArray[i] << "\n" << endl;



	cout << "The value  at memory location " << y << " is: " << memArray[y] << "\n" << endl;
	cout << "\n";

	cout << " | 11 | 110111  |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i - 1] << "\t     |" << memArray[i] << "\n" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i] << "\t     |" << memArray[x] << "\n" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 1] << "\t     |" << memArray[y] << "\n" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 2] << "\t     |" << memArray[z] << "\n" << endl;
	cout << "Register | Register Value | Register Address| Memory Address | Memory Value " << endl;
	cout << "\n";



	secondaryGreeting();

	return 0;
}
int RICS::wr4m()
{
	cout << "Select Register:\n" << endl;
	cin >> reg4;
	cout << "Enter register value:\n " << endl;
	cin >> j;
	storedValue4 = j;

	cout << "Select Memory location to write to 0-99" << endl;
	cin >> z;

	memArray[z] = storedValue4;

	cout << memArray[z] << "\n" << endl;



	cout << "The value  at memory location " << z << " is: " << memArray[z] << "\n" << endl;
	cout << "\n";

	cout << " | 11 | 111000  |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i - 1] << "\t     |" << memArray[i] << "\n" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i] << "\t     |" << memArray[x] << "\n" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 1] << "\t     |" << memArray[y] << "\n" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 2] << "\t     |" << memArray[z] << "\n" << endl;
	cout << "Register | Register Value | Register Address| Memory Address | Memory Value " << endl;
	cout << "\n";



	secondaryGreeting();

	return 0;
}
int RICS::wram()
{
	cout << "Select Register:\n" << endl;
	cin >> reg4;
	reg3 = reg4;
	reg2 = reg4;
	reg1 = reg4;
	cout << "Enter register value:\n " << endl;
	cin >> j;
	storedValue4 = j;
	storedValue3 = j;
	storedValue2 = j;
	storedValue1 = j;
	cout << "Select Memory location to write to 0-99" << endl;
	cin >> z;

	memArray[z] = storedValue4;
	memArray[z] = storedValue3;
	memArray[z] = storedValue2;
	memArray[z] = storedValue1;
	cout << memArray[z] << "\n" << endl;



	cout << "The value  at memory location " << z << " is: " << memArray[z] << "\n" << endl;
	cout << "\n";

	cout << " | 11 | 111001  |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i - 1] << "\t     |" << memArray[i] << "\n" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i] << "\t     |" << memArray[x] << "\n" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 1] << "\t     |" << memArray[y] << "\n" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 2] << "\t     |" << memArray[z] << "\n" << endl;
	cout << "Register | Register Value | Register Address| Memory Address | Memory Value " << endl;
	cout << "\n";



	secondaryGreeting();

	return 0;
}
int RICS::mems()
{
	
	cout << "Enter memory value:\n " << endl;
	cin >> j;
	
	cout << "Select Memory location to write to 0-99" << endl;
	cin >> i;

	memArray[i] = j;

	cout << memArray[i] << "\n" << endl;



	cout << "The value  at memory location " << i << " is: " << memArray[i] << "\n" << endl;
	cout << "\n";

	cout << " | 11 | 111011  |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i] << "\t     |" << memArray[i] << "\n" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i + 1] << "\t     |" << memArray[x] << "\n" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 2] << "\t     |" << memArray[y] << "\n" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 3] << "\t     |" << memArray[z] << "\n" << endl;
	cout << "Register | Register Value | Register Address| Memory Address | Memory Value " << endl;
	cout << "\n";



	secondaryGreeting();

	return 0;
}
int RICS::mems2()
{

	cout << "Enter memory value:\n " << endl;
	cin >> j;

	cout << "Select Memory location to write to 0-99" << endl;
	cin >> x;

	memArray[x] = j;

	cout << memArray[i] << "\n" << endl;



	cout << "The value  at memory location " << x << " is: " << memArray[x] << "\n" << endl;
	cout << "\n";

	cout << " | 11 | 111011  |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i - 1] << "\t     |" << memArray[i] << "\n" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i] << "\t     |" << memArray[x] << "\n" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 1] << "\t     |" << memArray[y] << "\n" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 2] << "\t     |" << memArray[z] << "\n" << endl;
	cout << "Register | Register Value | Register Address| Memory Address | Memory Value " << endl;
	cout << "\n";



	secondaryGreeting();

	return 0;
}
int RICS::memrst()
{


	j = 0;

	cout << "Select Memory location to write to 0-99" << endl;
	cin >> x;

	memArray[i,x,y,z] = j;

	cout << memArray[i, x, y, z] << "\n" << endl;



	cout << "The value  at memory location " << x << " is: " << memArray[x] << "\n" << endl;
	cout << "\n";

	cout << " | 11 | 111101  |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i - 1] << "\t     |" << memArray[x] << "\n" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i] << "\t     |" << memArray[x] << "\n" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 1] << "\t     |" << memArray[x] << "\n" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 2] << "\t     |" << memArray[x] << "\n" << endl;
	cout << "Register | Register Value | Register Address| Memory Address | Memory Value " << endl;
	cout << "\n";



	secondaryGreeting();

	return 0;
}

int RICS::regwrt1()
{
	cout << "Select Register:\n" << endl;
	cin >> reg1;
	cout << "Enter register value:\n " << endl;
	cin >> j;
	storedValue1 = j;

	

	cout << " | 11 | 111110  |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i - 1] << "\t     |" << memArray[i] << "\n" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i] << "\t     |" << memArray[x] << "\n" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 1] << "\t     |" << memArray[y] << "\n" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 2] << "\t     |" << memArray[z] << "\n" << endl;
	cout << "Register | Register Value | Register Address| Memory Address | Memory Value " << endl;
	cout << "\n";



	secondaryGreeting();

	return 0;
}
int RICS::regwrt2()
{
	cout << "Select Register:\n" << endl;
	cin >> reg2;
	cout << "Enter register value:\n " << endl;
	cin >> j;
	storedValue2 = j;



	cout << " | 11 | 111011  |"; decToBinary(storedValue1); cout << "|"; decToBinary(storedValue2); cout << "|"; decToBinary(storedValue3); cout << "|"; decToBinary(storedValue4); cout << "|"; cout << endl;
	cout << " |Stype| op-code|      op 1      |	op2       |	result     |   	copy	    |\n\n\n" << endl;


	cout << reg1 << "\t |" << storedValue1 << "\t\t  |" << &regArray[reg1] << "\t    |" << &memArray[i - 1] << "\t     |" << memArray[i] << "\n" << endl;
	cout << reg2 << "\t |" << storedValue2 << "\t\t  |" << &regArray[reg2] << "\t    |" << &memArray[i] << "\t     |" << memArray[x] << "\n" << endl;
	cout << reg3 << "\t |" << storedValue3 << "\t\t  |" << &regArray[reg3] << "\t    |" << &memArray[i + 1] << "\t     |" << memArray[y] << "\n" << endl;
	cout << reg4 << "\t |" << storedValue4 << "\t\t  |" << &regArray[reg4] << "\t    |" << &memArray[i + 2] << "\t     |" << memArray[z] << "\n" << endl;
	cout << "Register | Register Value | Register Address| Memory Address | Memory Value " << endl;
	cout << "\n";



	secondaryGreeting();

	return 0;
}