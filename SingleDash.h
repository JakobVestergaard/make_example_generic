/*
 * SIngelDash.h
 *
 *  Created on: 13 Jul 2016
 *      Author: klaus
 */

#ifndef SINGLEDASH_H_
#define SINGLEDASH_H_

#include "Options.h"

class SingleDash: public Options
{
	public:
		SingleDash ( );
		SingleDash (int argc, char const ** argv);
		virtual ~SingleDash ( ){};

	private:

};

#endif /* SINGLEDASH_H_ */
