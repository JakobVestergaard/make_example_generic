/*
 * Options.cpp
 *
 *  Created on: 7 Jul 2016
 *      Author: klaus
 */

#include "Options.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
 * Default constructor
 */
Options::Options ( )
{
	argC = -1;
	argV = NULL;
	optStr = "";
	numberOptions = 0;
	expectArgument = false;
	optind = -1; // -1 = none
}

/*
 * Constructor initialises the variables
 */
Options::Options (int argc, char const ** argv)
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

	optStr = "";
	numberOptions = 0;
	expectArgument = false;
	optind = -1; // -1 = none
}

/*
 * setArguments is needed if default constructor was used to create an
 * object of this class
 */
bool Options::setArguments (int argc, const char **argv)
{
	if (argc > 1 && argv != NULL)
	{
		argC = argc;
		argV = argv;
		return true;
	}
	else
	{
		throw logic_error ("Wrong number of arguments or NULL pointer argument array.");
	}
}

int Options::getopt (string &opt)
{
	if (optind < numberOptions - 1)
	{
		opt = optsPresent[++optind];
		return 0;
	}
	opt = "";
	return -1;
}

bool Options::getArg (string &arg, string option)
{
	// Declare an iterator
	map<string, string>::iterator it;
	// Search the map for the key in options
	it = arguments.find (option);
	// Did we have any luck?
	if (it != arguments.end ())
	{
		// Return second item at this pointer
		arg = it->second;
		return true;
	}
	// No luck - tell
	return false;
}

bool Options::setOptStr (const string str)
{
	// We only want to store options not empty options string
	if (str.length () > 0)
	{
		string option;
		size_t prevpos = 0;
		size_t pos = 0;

		// Store the options
		optStr = str;

		// Traverse all possible options and find which are set for this run
		while ((pos = str.find (',', prevpos)) != string::npos)
		{
			option = str.substr (prevpos, pos - prevpos);
			prevpos = pos + 1;

			bool res = isPresent (option, dash);
			if (res)
			{ // It is present - update the array
				optsPresent[numberOptions++] = ColonPresent (option);
			}
		}
		return true;
	}
	else
	{
		throw length_error ("Zero length options string.");
	}
	return false;
}

string Options::ColonPresent (const string str)
{
	expectArgument = false;
	string res = str;
	size_t found = str.find (":");
	if (found != string::npos)
	{
		// Argument to the option required
		expectArgument = true;
		// Remove the : from the string
		res = str.substr (0, found);
	}
	return res;
}
/*
 * This version of isPresent will look for the option in the command line
 * arguments. If an argument is found it looks forward to pickup a possible
 * argument to the option
 */

bool Options::isPresent (string option, string needle)
{
	// If a valid option is followed by a : an argument is required to the
	// option.
	size_t found;

	// Add the option we're searching for to the needle
	// Because we can operate with different needles like
	// - or -- the function is made more generic
	needle += ColonPresent (option);
	// Loop through the arguments
	for (int i = 1; i < argC; i++)
	{
		// Declare a heystack to search in. Set to to the string pointed to by argV
		string heystack = argV[i];
		// Perform the find operation starting from position 0
		found = heystack.find (needle, 0);
		// Did we fnid anything?
		if (found != string::npos)
		{
			if (expectArgument)
			{
				// Yes, now look for attached arguments
				// Does the next argument point to something valid?
				if (argV[i + 1])
				{
					// It did - is i beginning of the next option or is it an
					// argument to this option. Add the argument to the arguments map
					arguments.insert (pair<string, string> (ColonPresent(option), argV[i + 1]));

				}
			}
			return true;
		}
	}
	return false;
}

/*
 * Simple split function that will split a string into tokens, where
 * tokens are seprareted by whats in sep (defaults to a space)
 */
vector<string> Options::split (string str, char sep = ' ')
{
	// Declare a vector
	vector<string> ret;
	// Insert the string to tokenise into a istringstream
	istringstream stm (str);
	// Declare a placeholder for a token
	string token;
	// Loop throught the stream of strings looking for separators
	while (std::getline (stm, token, sep))
	{
		// Push the found token on the back of the vector
		ret.push_back (token);
	}
	// Return what we've found
	return ret;
}
