#include "TriGunUpgrade.hpp"

#include "TextureManager.hpp"

#include "Player.hpp"

TriGunUpgrade::TriGunUpgrade()
{
	setTexture(TextureManager::instance().get("triupgrade"));
}

void TriGunUpgrade::activate(Player * player, World * world)
{
	markDelete();
}

