/*
 * main.cpp
 *
 *  Created on: 7 Jul 2016
 *      Author: klaus
 */

#include "SingleDash.h"
#include "DoubleDash.h"
#include <iostream>


using namespace std;

/*
 * This program demonstrates the Options calls, which is able to handle
 * command line arguments to the program.
 * In this version it will handle -<letter> options, i.e. -a or -o and
 * --<word> options, i.e. --anoption
 * In this specific case it is tested against taking arguments to the option
 * e.g. -f filename or --file filename
 * where filename shall be retrievable
 */

int main (int argC, char const **argV)
{
	string opt;

	try
	{

		Options *op = new SingleDash (argC, argV);

		op->setOptStr ("a,f:,");
		cout << "In the SingleDash object these options were found:" << endl;

		// Find out how many options has been presented on the command line
		while (op->getopt (opt) == 0)
		{
			string arg;
			if (op->getArg (arg, opt))
			{
				cout << opt << " is present with this argument " << arg << endl;
			}
			else
			{
				cout << opt << " is present." << endl;
			}
		}
		delete op;
		op = new DoubleDash (argC, argV);
		op->setOptStr ("file:,anoption,options,");
		cout << "In the DoubleDash object these options were found:" << endl;

		// Find out how many options has been presented on the command line
		while (op->getopt (opt) == 0)
		{
			string arg;
			if (op->getArg (arg, opt))
			{
				cout << opt << " is present with this argument " << arg << endl;
			}
			else
			{
				cout << opt << " is present." << endl;
			}
		}
		delete op;
	}
	catch (length_error &e)
	{
		cout << "Caught an length_error: " << e.what () << endl;
		return -1;
	}
	catch (logic_error &e)
	{
		cout << "Caucght a logic_error: " << e.what () << endl;
		return -2;
	}
	catch (...)
	{
		cout << "Caught unknown error. " << endl;
		return -1;
	}
	return 0;
}

