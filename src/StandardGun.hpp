#ifndef STANDARDGUN_HPP
#define STANDARDGUN_HPP

#include "Gun.hpp"

class StandardGun : public Gun
{
private:

public:

	StandardGun(World & world);

	virtual void fire();
};

#endif
