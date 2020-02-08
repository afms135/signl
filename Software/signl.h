#ifndef SIGNL_H
#define SIGNL_H
#include "jack.h"
#include <signal.h>

class signl : jack_client
{
public:
	signl();
	~signl();
	sample_t process(sample_t in);
	void shutdown();
	void start();

private:
	volatile sig_atomic_t running;
};

#endif /*SIGNL_H*/
