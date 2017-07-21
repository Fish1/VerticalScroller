#include "TriGunUpgrade.hpp"

#include "TextureManager.hpp"

#include "Player.hpp"

#include "TriGun.hpp"

TriGunUpgrade::TriGunUpgrade()
{
	m_sprite->setTexture(TextureManager::instance().get("triupgrade"));
}

void TriGunUpgrade::activate(Player * player, World * world)
{
	TriGun * gun = new TriGun(*world);

	player->setGun(gun);

	markDelete();
}

