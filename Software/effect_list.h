#ifndef EFFECT_LIST
#define EFFECT_LIST
#include "effect_manager.h"
#include "effects/effect.h"
#include <vector>
#include <memory>

/**
 * \brief Utility class for a list of effects.
 */
struct effect_list
{
	/**
	 * \brief Create instance of effect list.
	 *
	 * \param l List of effects to move into #list.
	 */
	effect_list(std::vector<std::unique_ptr<effect, plugin_dtor_t>> &&l) :
		list(std::move(l)),
		idx(effect_manager::EFFECT_NULL)
	{
	}

	///Increment index, selects next effect in list, wraps around
	void operator++()
	{
		idx++;
		idx %= list.size();
	}

	///Increment index, selects previous effect in list, wraps around
	void operator--()
	{
		idx--;
		idx %= list.size();
	}

	///Return currently selected effect
	const std::unique_ptr<effect, plugin_dtor_t>& operator()()
	{
		return list[idx];
	}

private:
	std::vector<std::unique_ptr<effect, plugin_dtor_t>> list; ///<List of effects.
	unsigned int idx; ///<Current effect index.
};

#endif /*EFFECT_LIST*/
