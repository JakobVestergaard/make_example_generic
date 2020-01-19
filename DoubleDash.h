/*
 * DoubleDash.h
 *
 *  Created on: 13 Jul 2016
 *      Author: klaus
 */

#ifndef DOUBLEDASH_H_
#define DOUBLEDASH_H_

#include "Options.h"

class DoubleDash: public Options
{
	public:
		DoubleDash ( );
		DoubleDash (int argc, char const ** argv);
		virtual ~DoubleDash ( )
		{
		}

	private:

};

#endif /* DOUBLEDASH_H_ */
