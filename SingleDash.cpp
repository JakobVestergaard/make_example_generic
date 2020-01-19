/*
 * SIngelDash.cpp
 *
 *  Created on: 13 Jul 2016
 *      Author: klaus
 */

#include "SingleDash.h"

#include <string.h>

SingleDash::SingleDash ( )
{
	// TODO Auto-generated constructor stub

}

SingleDash::SingleDash(int argc, const char ** argv)
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

	dash = "-";
}




