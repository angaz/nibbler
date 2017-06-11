#ifndef NIBBLER_MAIN_SNAKE_HPP
#define NIBBLER_MAIN_SNAKE_HPP

#include <deque>

class Snake {
public:
	struct	Point {
		unsigned	x;
		unsigned	y;

		Point() {};
		//Point(const Point &src) : x(src.x), y(src.y) {};
		Point(unsigned x, unsigned y) : x(x), y(y) {};

		bool operator==(const Snake::Point &p2) const {
			return (this->x == p2.x && this->y == p2.y);
		}
	};

	enum	Direction {
		NONE,
		UP,
		RIGHT,
		DOWN,
		LEFT
	};


	Snake(const Snake &src);
	Snake(unsigned windowWidth, unsigned windowHeight);
	~Snake();

	Snake &operator=(const Snake &rhs);

	bool							update();
	void							setDirection(Snake::Direction direction);
	const std::deque<Snake::Point>	&getPieces() const;
	const Snake::Point				&getHead() const;
	Snake::Direction				getDirection() const;
	void 							eatFood(unsigned food);

private:
	Snake();

	std::deque<Snake::Point>	_pieces;
	Snake::Direction			_direction;
	unsigned					_foodLeft;
	Point						_window;

	Snake::Point				_getNewHeadPos();
};


#endif //NIBBLER_MAIN_SNAKE_HPP
