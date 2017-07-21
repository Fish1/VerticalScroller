#ifndef SLOWGUN_HPP
#define SLOWGUN_HPP

#include "Gun.hpp"

class SlowGun : public Gun
{
private:

public:

	SlowGun(World & world);

	virtual void fire();
};

#endif
