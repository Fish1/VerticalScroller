#ifndef BUILDER_HPP
#define BUILDER_HPP

class GameObject;

class Builder
{
private:

public:

	virtual GameObject * build() = 0;

};

#endif
