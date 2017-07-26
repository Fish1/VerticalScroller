#include "TriGunUpgrade.hpp"

#include "TextureManager.hpp"

#include "SoundBufferManager.hpp"

#include "GunBuilder.hpp"

#include "Player.hpp"

#include "Bullet.hpp"

#include "Define.hpp"

TriGunUpgrade::TriGunUpgrade()
{
	setTexture(TextureManager::instance().get("triupgrade"));

	enableCollision();
}

void TriGunUpgrade::activate(Player & player, World & world)
{
	GunBuilder builder;

	builder.setPlayer(true).setFireRate(0.5f).setWorld(world).setSound("galaga_shoot1")
	.setFire([](World * world, Gun * gun) 
	{
		float rotation = gun->getRotation() * (PI / 180.0f);
		float x = cos(rotation);
		float y = sin(rotation);
		world->addPlayerBullet(new Bullet(gun->getPosition(), sf::Vector2f(x, y)));

		rotation += 10.0f * (PI / 180.0f);
		x = cos(rotation);
		y = sin(rotation);
		world->addPlayerBullet(new Bullet(gun->getPosition(), sf::Vector2f(x, y)));
		
		rotation -= 20.0f * (PI / 180.0f);
		x = cos(rotation);
		y = sin(rotation);
		world->addPlayerBullet(new Bullet(gun->getPosition(), sf::Vector2f(x, y)));
	});

	player.setGun(dynamic_cast<Gun*>(builder.build()));

	markDelete();
}

