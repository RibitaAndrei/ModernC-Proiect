#pragma once
#include <utility>
#include "Pilon.h"

class Bridge
{
private:
	std::pair <Pilon, Pilon> pilons;

public:
	Bridge(Pilon Pilon1, Pilon Pilon2);
	Bridge(const Bridge& other);
	Bridge& operator=(const Bridge& copy) = default;
	~Bridge() {};

	Pilon GetPylon1() const;
	Pilon GetPylon2() const;

	void SetPylon1(Pilon pilon1);
	void SetPylon2(Pilon pilon2);

};

