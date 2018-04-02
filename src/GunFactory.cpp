#include "GunFactory.hpp"

#include "GunBuilder.hpp"

#include "BulletBuilder.hpp"

#include "TextureManager.hpp"

#include "World.hpp"

#include "Math.hpp"

GunFactory::GunFactory(World & world)
{
	/*
	 * Shot: Single
	 * Speed; 500
	 * Rate: 1
	 */
	GunBuilder * builder = new GunBuilder();

	builder->setFireRate(1.0f);
	builder->setWorld(world);

	builder->setFire([](World * world, Gun * gun) 
	{
		float rotation = gun->getRotation() * (Math::PI / 180.0f);
		float x = cos(rotation);
		float y = sin(rotation);

		BulletBuilder bb;

		bb.setPosition(gun->getPosition());
		bb.setDirection(sf::Vector2f(x, y));
		bb.setSpeed(500.0f);
		bb.setTexture(TextureManager::instance().get("smallprojectile_a"));

		world->addEnemyBullet(dynamic_cast<Bullet*>(bb.build()));
	});

	m_builders.insert(std::pair<std::string, GunBuilder*>("single_500_1", builder));
	
	/*
	 * Shot: Single
	 * Speed; 600
	 * Rate: 0.5
	 */
	builder = new GunBuilder();

	builder->setFireRate(0.5f);
	builder->setWorld(world);

	builder->setFire([](World * world, Gun * gun) 
	{
		float rotation = gun->getRotation() * (Math::PI / 180.0f);
		float x = cos(rotation);
		float y = sin(rotation);

		BulletBuilder bb;

		bb.setPosition(gun->getPosition());
		bb.setDirection(sf::Vector2f(x, y));
		bb.setSpeed(600.0f);
		bb.setTexture(TextureManager::instance().get("smallprojectile_a"));

		world->addEnemyBullet(dynamic_cast<Bullet*>(bb.build()));
	});

	m_builders.insert(std::pair<std::string, GunBuilder*>("single_600_0.5", builder));
}

GameObject * GunFactory::build(std::string key)
{
	return m_builders.at(key)->build();
}
