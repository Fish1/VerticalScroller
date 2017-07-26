#ifndef TRIGUNUPGRADE_HPP
#define TRIGUNUPGRADE_HPP

#include "Upgrade.hpp"

class TriGunUpgrade : public Upgrade
{
private:

public:

	TriGunUpgrade();

	virtual void activate(Player & player, World & world);

};

#endif
