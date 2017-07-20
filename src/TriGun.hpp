#ifndef TRIGUN_HPP
#define TRIGUN_HPP

#include "Gun.hpp"

class TriGun : public Gun
{
public:

	TriGun(World & world);

	virtual void fire();
};

#endif
