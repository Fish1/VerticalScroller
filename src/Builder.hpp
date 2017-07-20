#ifndef BUILDER_HPP
#define BUILDER_HPP

class GameObject;

class Builder
{
public:

	virtual GameObject * build() = 0;
};

#endif
