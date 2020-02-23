#ifndef SIGNL_H
#define SIGNL_H
#include "jack.h"
#include "effects/effect.h"
#include <memory>
#include <vector>
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
	std::vector<std::unique_ptr<effect>> effect_chain;
	static void sigterm_handler(int sig);
	static volatile sig_atomic_t running;
};

#endif /*SIGNL_H*/
