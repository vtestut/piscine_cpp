#include "Whatever.hpp"

class Point {
public:
	double x, y;

	Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

	friend std::ostream& operator<<(std::ostream& os, const Point& p) {
		os << "(" << p.x << ", " << p.y << ")";
		return os;
	}

	bool operator<(const Point& other) const {
		return (x < other.x) || (x == other.x && y < other.y);
	}

	bool operator>(const Point& other) const {
		return (x > other.x) || (x == other.x && y > other.y);
	}
};

int main() {
	Point p1(2, 3), p2(3, 2);

	std::cout << "Original p1: " << p1 << ", p2: " << p2 << std::endl;

	swap(p1, p2);
	std::cout << "After swap p1: " << p1 << ", p2: " << p2 << std::endl;

	p1 = Point(2, 3);
	p2 = Point(3, 2);

	Point pMin = min(p1, p2);
	std::cout << "Minimum of p1 and p2: " << pMin << std::endl;

	Point pMax = max(p1, p2);
	std::cout << "Maximum of p1 and p2: " << pMax << std::endl;

	return 0;
}
