/*
Ricard Alonzo Ugalde
CIS 655-Advanced Computer Architecture
Syracuse University
HW #2 - RICS Instruction Set Architecture

.cpp main file
*/

#include "RICS.h"
#include <iostream>
using namespace std;


int main()
{
	/*
	Add Mips Functionality by accepting R type Instructions
	*/
	string type1;
	string  enter;
	int loop = 0;
		
	RICS ob1;
	ob1.mainGreeting();
	cin >> enter;
	

	if (enter == "2" || enter == "two")
	{
		ob1.rTypeDescription();
		ob1.iTypeDescription();
		ob1.cTypeDescription();
		ob1.sTypeDescription();
		return main();
		
		
		return 0;
	}

	else if ( enter == "00" || enter == "r")
	{
		ob1.rType(); // calls the rtype function
		return main();
	}

	else if (enter == "01" || enter == "i")
	{
		ob1.iType(); // calls the itype function
		return main();
	}

	else if (enter == "10" || enter == "c")
	{
		ob1.cType(); // calls the ctype function
		return main();
	}

	else if (enter == "11" || enter == "s")
	{
		ob1.sType(); // calls the stype function
		return main();
	}

	else if (enter == "3" "main")
	{
		ob1.mainGreeting();
		return main();
	}
		


	




	return 0;
}