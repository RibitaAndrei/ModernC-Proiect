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
	~Bridge() {};

	Pilon getPylon1() const;
	Pilon getPylon2() const;

	void setPylon1(Pilon pilon1);
	void setPylon2(Pilon pilon2);

};

