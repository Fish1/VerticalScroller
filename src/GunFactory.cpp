#include "GunFactory.hpp"

#include "GunBuilder.hpp"

#include "BulletBuilder.hpp"

#include "Bullet.hpp"

#include "TextureManager.hpp"

#include "World.hpp"

#include "Math.hpp"

#include <fstream>

GunFactory::GunFactory(World & world, bool playerGuns) :
	m_playerGuns(playerGuns)
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
	std::function<void(float, World*, Gun*, bool)> singleShot;

	singleShot = [](float bulletSpeed, World * world, Gun * gun, bool playerBullet)
	{
		float rotation = gun->getRotation() * (Math::PI / 180.0f);
		float x = cos(rotation);
		float y = sin(rotation);

		BulletBuilder bb;

		bb.setPosition(gun->getPosition());
		bb.setDirection(sf::Vector2f(x, y));
		bb.setSpeed(bulletSpeed);
		bb.setTexture(TextureManager::instance().get("smallprojectile_a"));

		world->addBullet(dynamic_cast<Bullet*>(bb.build()), playerBullet);
	};
	
	m_fireTypes.insert(
	std::pair<std::string,std::function<void(float, World*, Gun*, bool)> >("single", singleShot)
	);

	std::function<void(float, World*, Gun*, bool)> triShot;

	triShot = [](float bulletSpeed, World * world, Gun * gun, bool playerBullet)
	{
		BulletBuilder bb;

		bb.setPosition(gun->getPosition());
		bb.setSpeed(bulletSpeed);
		bb.setTexture(TextureManager::instance().get("smallprojectile_a"));

		float rotation = gun->getRotation() * (Math::PI / 180.0f);
		float x = cos(rotation);
		float y = sin(rotation);
		bb.setDirection(sf::Vector2f(x, y));
		world->addBullet(dynamic_cast<Bullet*>(bb.build()), playerBullet);

		rotation += 10.0f * (Math::PI / 180.0f);
		x = cos(rotation);
		y = sin(rotation);
		bb.setDirection(sf::Vector2f(x, y));
		world->addBullet(dynamic_cast<Bullet*>(bb.build()), playerBullet);
		
		rotation -= 20.0f * (Math::PI / 180.0f);
		x = cos(rotation);
		y = sin(rotation);
		bb.setDirection(sf::Vector2f(x, y));
		world->addBullet(dynamic_cast<Bullet*>(bb.build()), playerBullet);
	};
	
	m_fireTypes.insert(
	std::pair<std::string, std::function<void(float, World*, Gun*, bool)> >("tri", triShot));

	std::function<void(float, World*, Gun*, bool)> shotgunShot;

	shotgunShot = [](float bulletSpeed, World * world, Gun * gun, bool playerBullet)
	{
		BulletBuilder bb;

		bb.setPosition(gun->getPosition());
		bb.setSpeed(bulletSpeed);
		bb.setTexture(TextureManager::instance().get("smallprojectile_a"));

		float rotation = gun->getRotation() * (Math::PI / 180.0f);
		float x = cos(rotation);
		float y = sin(rotation);
		bb.setDirection(sf::Vector2f(x, y));
		world->addBullet(dynamic_cast<Bullet*>(bb.build()), playerBullet);

		bb.setPosition(gun->getPosition() + sf::Vector2f(10.0f, 10.0f));
		world->addBullet(dynamic_cast<Bullet*>(bb.build()), playerBullet);
		
		bb.setPosition(gun->getPosition() + sf::Vector2f(-10.0f, 10.0f));
		world->addBullet(dynamic_cast<Bullet*>(bb.build()), playerBullet);
		
		bb.setPosition(gun->getPosition() + sf::Vector2f(-10.0f, -10.0f));
		world->addBullet(dynamic_cast<Bullet*>(bb.build()), playerBullet);
		
		bb.setPosition(gun->getPosition() + sf::Vector2f(10.0f, -10.0f));
		world->addBullet(dynamic_cast<Bullet*>(bb.build()), playerBullet);
	};

	m_fireTypes.insert(
	std::pair<std::string, std::function<void(float, World*, Gun*, bool)>>("shotgun", shotgunShot));
}
