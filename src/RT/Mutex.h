#ifndef MUTEX_H
#define MUTEX_H

#include "../Definitions.h"

#if (defined(__OS_LINUX__) || defined(__OS_MACOSX__))

#include <pthread.h>
typedef pthread_mutex_t MUTEX;
typedef pthread_cond_t CONDITION;

#elif defined(__OS_WINDOWS__)

#include <windows.h>
#include <process.h>
typedef CRITICAL_SECTION MUTEX;
typedef HANDLE CONDITION;

#endif


/***************************************************/
/*! \class Mutex
\brief Mutex class.

This class provides a uniform interface for
cross-platform mutex use. On Linux systems, 
the pthread library is used. Under
Windows, critical sections are used.

by Perry R. Cook and Gary P. Scavone, 1995 - 2010.
*/
/***************************************************/

class Mutex
{
public:
	//! Default constructor.
	Mutex();

	//! Class destructor.
	~Mutex();

	//! Lock the mutex.
	void lock( void );

	//! Unlock the mutex.
	void unlock( void );

	//! Wait indefinitely on the mutex condition variable.
	/*!
	The mutex must be locked before calling this function, and then
	subsequently unlocked after this function returns.
	*/
	void wait( void );

	//! Signal the condition variable.
	/*!
	The mutex must be locked before calling this function, and then
	subsequently unlocked after this function returns.
	*/
	void signal( void );

protected:
	MUTEX mutex_;
	CONDITION condition_;
};

#endif