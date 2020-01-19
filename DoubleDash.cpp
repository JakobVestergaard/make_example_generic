/*
 * DoubleDash.cpp
 *
 *  Created on: 13 Jul 2016
 *      Author: klaus
 */

#include "DoubleDash.h"

#include <string.h>

DoubleDash::DoubleDash ( )
{
	// TODO Auto-generated constructor stub

}

DoubleDash::DoubleDash(int argc, const char ** argv)
{
	if (argc > 1 && argv != NULL)
	{
		argC = argc;
		argV = argv;
	}
	else
	{
		throw logic_error ("Wrong number of arguments or NULL pointer argument array.");
	}

	dash ="--";
}



