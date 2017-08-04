#include "TriGunUpgrade.hpp"

#include "TextureManager.hpp"

#include "SoundBufferManager.hpp"

#include "GunBuilder.hpp"
#include "BulletBuilder.hpp"

#include "Player.hpp"

#include "Math.hpp"

TriGunUpgrade::TriGunUpgrade()
{
	setTexture(TextureManager::instance().get("triupgrade"));

	enableCollision();
}

void TriGunUpgrade::activate(Player & player, World & world)
{
	GunBuilder builder;

	builder.setPlayer(true).setFireRate(0.2f).setWorld(world).setSound("galaga_shoot1")
	.setFire([](World * world, Gun * gun) 
	{
		BulletBuilder bb;

		bb.setPosition(gun->getPosition());
		bb.setSpeed(600.0f);
		bb.setTexture(TextureManager::instance().get("smallprojectile_a"));

		float rotation = gun->getRotation() * (Math::PI / 180.0f);
		float x = cos(rotation);
		float y = sin(rotation);
		bb.setDirection(sf::Vector2f(x, y));
		world->addPlayerBullet(dynamic_cast<Bullet*>(bb.build()));

		rotation += 10.0f * (Math::PI / 180.0f);
		x = cos(rotation);
		y = sin(rotation);
		bb.setDirection(sf::Vector2f(x, y));
		world->addPlayerBullet(dynamic_cast<Bullet*>(bb.build()));
		
		rotation -= 20.0f * (Math::PI / 180.0f);
		x = cos(rotation);
		y = sin(rotation);
		bb.setDirection(sf::Vector2f(x, y));
		world->addPlayerBullet(dynamic_cast<Bullet*>(bb.build()));
	});

	player.setGun(dynamic_cast<Gun*>(builder.build()));

	markDelete();
}

