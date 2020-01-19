/*
 * Options.h
 *
 *  Created on: 7 Jul 2016
 *      Author: klaus
 */

#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <string>
#include <vector>
#include <map>

// By including at this point it is included in the
// necessary implementation modules.
#include <stdexcept>

using namespace std;

class Options
{
	public:
		Options ( ); // Default constructor needed if a global object is created
		Options (int argc, char const ** argv);
		virtual ~Options ( )
		{
		}

		// Needed if the default constructor was used
		bool setArguments (int argc, const char **argv);
		virtual bool setOptStr (const string str);
		virtual int getopt (string &opt);
		virtual bool getArg (string &arg, string option);

	protected:
		// Holds the argument count
		int argC;
		// Holds the pointer to the argument array of pointers
		const char **argV;
		// Initialised to either "-" or "--"
		string dash;

	private:
		int numberOptions; // Don't call it numOpts
		// Finds if an option is present on the current commandline
		bool isPresent (string option, string needle);

		int optind;
		string optStr;
		string optsPresent[50];

		string ColonPresent (const string str);
		bool expectArgument;

		vector<string> split (string str, char sep);

		map<string, string> arguments;

};

#endif /* OPTIONS_H_ */
