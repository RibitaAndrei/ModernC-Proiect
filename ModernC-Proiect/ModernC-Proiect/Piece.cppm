module;

#include <cstdint>

export module piece;
import <iostream>;
#include <utility>;

namespace pieces
{
	export class Pilon
	{
	private:
		char m_color;
		std::pair <int, int> m_position;

	public:
		Pilon();
		Pilon& operator=(const Pilon& copy) = default;
		Pilon(const Pilon& copy) = default;
		~Pilon() = default;

		char getColor() const;
		void setColor(char color);

		int getPositionX() const;
		void setPositionX(int posX);

		int getPositionY() const;
		void setPositionY(int posY);

		std::pair<int, int> getPositionXY() const;
		void setPositionXY(int posX, int posY);
	};//clasa pilon

	export class Bridge
	{
	private:
		std::pair <Pilon, Pilon> pilons;

	public:
		Bridge(Pilon Pilon1, Pilon Pilon2);
		Bridge(const Bridge& copy);
		~Bridge() = default;
		friend bool operator == (const Bridge& c1, const Bridge& c2);

		Pilon getPylon1() const;
		Pilon getPylon2() const;

		void setPylon1(Pilon pilon1);
		void setPylon2(Pilon pilon2);
	};//clasa bridge


}