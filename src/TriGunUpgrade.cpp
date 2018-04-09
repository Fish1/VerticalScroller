#include "TriGunUpgrade.hpp"

#include "TextureManager.hpp"

#include "SoundBufferManager.hpp"

#include "GunBuilder.hpp"

#include "GunFactory.hpp"

#include "BulletBuilder.hpp"

#include "Bullet.hpp"

#include "Player.hpp"

#include "World.hpp"

#include "Math.hpp"

TriGunUpgrade::TriGunUpgrade()
{
	setTexture(TextureManager::instance().get("triupgrade"));

	enableCollision();
}

void TriGunUpgrade::activate(Player & player, World & world)
{
	GunFactory gunFactory(world, true);
	gunFactory.loadFromFile("res/guns/guns.txt", world);

	player.setGun(dynamic_cast<Gun*>(gunFactory.build("shotgun_500_1")));

	markDelete();
}

