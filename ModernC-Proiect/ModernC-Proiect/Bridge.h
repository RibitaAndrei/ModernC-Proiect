#pragma once
#include <utility>
#include "Pilon.h"

class Bridge : public Foundation
{
public:
	using Pilons = std::pair <Foundation*, Foundation*>;

	Bridge(Pilons pilons, Foundation::PlayerColor color, Foundation::Position position);
	Bridge(const Bridge& other);
	Bridge& operator=(const Bridge& copy) = default;
	~Bridge() {};

	Foundation* GetFirstPilon() const;
	Foundation* GetSecondPilon() const;

	void SetFirstPilon(Pilon* pilon);
	void SetSecondPilon(Pilon* pilon);

	virtual Foundation::PlayerColor GetColor() const override;
	virtual void SetColor(const Foundation::PlayerColor& color) override;

private:
	Pilons m_pilons;
};

