#pragma once
#include <utility>
#include "Foundation.h"

class Pilon : public Foundation
{
public:
	Pilon();
	Pilon(Foundation::PlayerColor color, Foundation::Position position);
	Pilon& operator=(const Pilon& copy) = default;
	Pilon(const Pilon& copy) = default;
	~Pilon() = default;

	virtual Foundation::PlayerColor GetColor() const override;
	virtual void SetColor(const Foundation::PlayerColor& color) override;
};