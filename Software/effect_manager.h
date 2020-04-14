#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H
#include "effects/effect.h"
#include <string>
#include <vector>
#include <memory>

/**
 * \brief Class used to load external effect plugins.
 *
 * This class loads external effects compiled as shared objects (`.so` files on
 * Linux) and dynamically loads them at startup.
 *
 * Each shared object is required to export two external symbols, with C
 * linkage:
 *
 * \code
 * effect *plugin_create(unsigned int rate); //This function is passed the current sample rate and returns a pointer to a new effect instance.
 * \endcode
 *
 * \code
 * void plugin_destroy(effect *e); //This function is passed a pointer to an effect and deletes the effect instance.
 * \endcode
 *
 * Optionally if the inherited class is named \c plugin the macro \c PLUGIN_API
 * (defined in effect.h) can instead be used if inserted at the end of the file.
 *
 * \n
 * Example:
 *
 * A sample command line to compile a plugin (on Linux) is the following:
 * `g++ -fPIC -shared plugin.cpp -o plugin.so`
 *
 * The \c Makefile in the effects directory will build any \c .cpp file in this
 * way.
 *
 * \warning Ensure that the effects created by this class are destroyed before
 * this class, as when this class is destoryed it unloads any plugins.
 * Meaning that any references or pointers to created effects will become
 * invalid and can segfault the application.
 */
class effect_manager
{
public:
	///Index of the null plugin, guaranteed to always exist.
	static const int EFFECT_NULL = 0;

	/**
	 * \brief Create an instance of a effect manager.
	 *
	 * Searches the given path looking for plugins with the given file
	 * extension, attempting to load them when found.
	 *
	 * \exception std::runtime_error If searching the given path failed.
	 * \param path String containing path to a directory to load plugins from.
	 * \param ext String containing the file extension to search for (optional: defaults to `.so`).
	 */
	effect_manager(std::string path, std::string ext = ".so");

	/**
	 * \brief Create instance of plugin.
	 *
	 * Returns a reference to a new instance of an effect.
	 *
	 * \note The effect instance is wrapped in a \c unique_ptr with a custom
	 * destructor ensuring RAII semantics so the effect is deleted when it
	 * falls out of scope.
	 *
	 * \exception std::runtime_error If idx is out of range.
	 * \param idx Index of effect to create (0 <= idx < #size()).
	 * \param rate Sample rate to pass to effect.
	 */
	std::unique_ptr<effect, plugin_dtor_t> operator()(unsigned int idx, unsigned int rate);

	/**
	 * \brief Number of loaded plugins.
	 *
	 * Returns the number of plugins loaded plus the null effect.
	 *
	 * \retval uint Number of effects.
	 */
	unsigned int size();

	/**
	 * \brief Create vector of all loaded plugins.
	 *
	 * Returns a vector containing an instance of all loaded effects.
	 *
	 * \note Each effect instance is wrapped in a \c unique_ptr with a custom
	 * destructor ensuring RAII semantics so that all the effects are deleted
	 * when the vector falls out of scope.
	 *
	 * \param rate Sample rate to pass to effects.
	 */
	std::vector<std::unique_ptr<effect, plugin_dtor_t>> list(unsigned int rate);

	///Deleted copy constructor, class can only be moved.
	effect_manager(const effect_manager& other) = delete;
	///Deleted copy assignment operator, class can only be moved.
	effect_manager& operator=(const effect_manager& other) = delete;
	///Move constructor, transfers ownership of
	effect_manager(effect_manager&& other);
	///Move assignment operator, unloads shared objects and transfers ownership of other.plugins to this.
	effect_manager& operator=(effect_manager&& other);
	///Destructor, unloads all shared object from memory and clears #plugins.
	~effect_manager();

private:
	///Structure representing a loaded external plugin.
	struct plugin
	{
		void *handle; ///<Pointer to handle of shared object, returned from dlopen().
		plugin_ctor_t create; ///<Pointer to function that creates an instance of an effect.
		plugin_dtor_t destroy; ///<Pointer to function the destroys an instance of an effect.
	};
	std::vector<struct plugin> plugins; ///<List of all plugins loaded.
};

#endif /*EFFECTMANAGER_H*/
