#include "GunFactory.hpp"

#include "GunBuilder.hpp"

#include "BulletBuilder.hpp"

#include "Bullet.hpp"

#include "TextureManager.hpp"

#include "World.hpp"

#include "Math.hpp"

#include <fstream>

GunFactory::GunFactory(World & world)
{
	loadFireTypes(world);
}

void GunFactory::loadFromFile(std::string filename, World & world)
{
	std::cout << "Loading Guns..." << std::endl;
	std::ifstream in(filename);

	std::string name;
	std::string fireType;
	float bulletSpeed;
	float fireRate;

	while(in >> name >> fireType >> bulletSpeed >> fireRate)
	{
		std::cout << " -- " << name << std::endl;

		GunBuilder * builder = new GunBuilder();

		builder->setFireRate(fireRate);
		builder->setBulletSpeed(bulletSpeed);
		builder->setFire(m_fireTypes.at(fireType));
		builder->setWorld(world);

		m_builders.insert(std::pair<std::string, GunBuilder*>(name, builder));
	}
}

GameObject * GunFactory::build(std::string key)
{
	return m_builders.at(key)->build();
}

void GunFactory::loadFireTypes(World & world)
{
	std::function<void(float, World*, Gun*)> singleShot;

	singleShot = [](float bulletSpeed, World * world, Gun * gun)
	{
		float rotation = gun->getRotation() * (Math::PI / 180.0f);
		float x = cos(rotation);
		float y = sin(rotation);

		BulletBuilder bb;

		bb.setPosition(gun->getPosition());
		bb.setDirection(sf::Vector2f(x, y));
		bb.setSpeed(bulletSpeed);
		bb.setTexture(TextureManager::instance().get("smallprojectile_a"));

		world->addEnemyBullet(dynamic_cast<Bullet*>(bb.build()));
	};
	
	m_fireTypes.insert(
	std::pair<std::string,std::function<void(float, World*, Gun*)> >("single", singleShot)
	);

	std::function<void(float, World*, Gun*)> triShot;

	triShot = [](float bulletSpeed, World * world, Gun * gun)
	{
		BulletBuilder bb;

		bb.setPosition(gun->getPosition());
		bb.setSpeed(bulletSpeed);
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
	};
	
	m_fireTypes.insert(
	std::pair<std::string, std::function<void(float, World*, Gun*)> >("tri", triShot));
}
