/*----INCLUDE-----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <math.h>

/*----DEFINE------------------------------------------------------------------*/

/*----CLASS-------------------------------------------------------------------*/

class Point {
	private:
		int coordinate_x;
		int coordinate_y;
	public:
		Point();
		Point(int coordinate_x, int coordinate_y);
		void set_coordinates_of_a_point(int coordinate_x, int coordinate_y);
		int get_coordinate_x();
		int get_coordinate_y();
		friend std::istream& operator>>(std::istream& input, Point& point);
};

class Polygon {
	private:
		std::vector <Point*> the_tops_of_the_polygon;
	public:
		//Polygon();
		void addPoint(Point& point);
		void print_polygon_vertices();
		bool operator==(const Polygon& polygon);
		void operator>>=(Point& point);
		friend std::ostream& operator<<(std::ostream& output, const Polygon& polygon);
};

/*----METHOD------------------------------------------------------------------*/

Point::Point() {
	coordinate_x = 0;
	coordinate_y = 0;
}

Point::Point(int coordinate_x, int coordinate_y) {
	this->coordinate_x = coordinate_x;
	this->coordinate_y = coordinate_y;
}

void Point::set_coordinates_of_a_point(int coordinate_x, int coordinate_y) {
	this->coordinate_x = coordinate_x;
	this->coordinate_y = coordinate_y;
}

int Point::get_coordinate_x() {
	return coordinate_x;
}

int Point::get_coordinate_y() {
	return coordinate_y;
}

void Polygon::addPoint(Point& point) {
	the_tops_of_the_polygon.push_back(&point);
}

/*----FUNCTION----------------------------------------------------------------*/

float the_length_of_the_straight_line(int point1_x, int point1_y, int point2_x, int point2_y) {
	return pow(pow(point2_x - point1_x, 2) + pow(point2_y - point1_y, 2), 0.5);
}

float area_of_a_triangle(float line_a, float line_b, float line_c) {
	float half_perimeter = (line_a + line_b + line_c) / 2;
	return pow(half_perimeter * (half_perimeter - line_a) * (half_perimeter - line_b) * (half_perimeter - line_c), 0.5);
}

/*----OPERATOR----------------------------------------------------------------*/

bool Polygon::operator==(const Polygon& polygon) {
	float area_of_the_first_polygon = 0;
	for (int i = 1; i < polygon.the_tops_of_the_polygon.size() - 1; i++) {
		area_of_the_first_polygon += area_of_a_triangle(
				the_length_of_the_straight_line(
					polygon.the_tops_of_the_polygon[0]->get_coordinate_x(),
					polygon.the_tops_of_the_polygon[0]->get_coordinate_y(),
					polygon.the_tops_of_the_polygon[i]->get_coordinate_x(),
					polygon.the_tops_of_the_polygon[i]->get_coordinate_y()),
				the_length_of_the_straight_line(
					polygon.the_tops_of_the_polygon[i]->get_coordinate_x(),
					polygon.the_tops_of_the_polygon[i]->get_coordinate_y(),
					polygon.the_tops_of_the_polygon[i + 1]->get_coordinate_x(),
					polygon.the_tops_of_the_polygon[i + 1]->get_coordinate_y()),
				the_length_of_the_straight_line(
					polygon.the_tops_of_the_polygon[i + 1]->get_coordinate_x(),
					polygon.the_tops_of_the_polygon[i + 1]->get_coordinate_y(),
					polygon.the_tops_of_the_polygon[0]->get_coordinate_x(),
					polygon.the_tops_of_the_polygon[0]->get_coordinate_y()));
	}
	std::cout << "area: " << area_of_the_first_polygon << std::endl;
	float area_of_the__polygon = 0;
	for (int i = 1; i < the_tops_of_the_polygon.size() - 1; i++) {
		area_of_the__polygon += area_of_a_triangle(
				the_length_of_the_straight_line(
					the_tops_of_the_polygon[0]->get_coordinate_x(),
					the_tops_of_the_polygon[0]->get_coordinate_y(),
					the_tops_of_the_polygon[i]->get_coordinate_x(),
					the_tops_of_the_polygon[i]->get_coordinate_y()),
				the_length_of_the_straight_line(
					the_tops_of_the_polygon[i]->get_coordinate_x(),
					the_tops_of_the_polygon[i]->get_coordinate_y(),
					the_tops_of_the_polygon[i + 1]->get_coordinate_x(),
					the_tops_of_the_polygon[i + 1]->get_coordinate_y()),
				the_length_of_the_straight_line(
					the_tops_of_the_polygon[i + 1]->get_coordinate_x(),
					the_tops_of_the_polygon[i + 1]->get_coordinate_y(),
					the_tops_of_the_polygon[0]->get_coordinate_x(),
					the_tops_of_the_polygon[0]->get_coordinate_y()));
	}
	std::cout << "area: " << area_of_the__polygon << std::endl;
	return (area_of_the__polygon == area_of_the_first_polygon) ? true : false;
}

void Polygon::operator>>=(Point& point) {
	for (int i = 0; i < the_tops_of_the_polygon.size(); i++) {
		the_tops_of_the_polygon[i]->set_coordinates_of_a_point(
				the_tops_of_the_polygon[i]->get_coordinate_x() + point.get_coordinate_x(),
				the_tops_of_the_polygon[i]->get_coordinate_y() + point.get_coordinate_y());
	}
}

std::ostream& operator<<(std::ostream& output, const Polygon& polygon) {
	for (int i = 0; i < polygon.the_tops_of_the_polygon.size(); i++) {
		output 
			<< "(" 
			<< polygon.the_tops_of_the_polygon[i]->get_coordinate_x()
			<< "; "
			<< polygon.the_tops_of_the_polygon[i]->get_coordinate_y() 
			<< ")";
	}
	return output;
}

std::istream& operator>>(std::istream& input, Point& point) {
	input 
		>> point.coordinate_x 
		>> point.coordinate_y;
	return input;
}

/*----MAIN--------------------------------------------------------------------*/

int main() {
	Point point0;
	Point point1(0, 10);
	Point point2(10, 10);
	Point point3(10, 0);
	Point point4(-10, -10);
	Point point5(2, 5);

	//std::cin >> point0;

	Polygon polygon1;
	polygon1.addPoint(point0);
	polygon1.addPoint(point1);
	polygon1.addPoint(point2);
	polygon1.addPoint(point3);

	Polygon polygon2;
	polygon2.addPoint(point4);
	polygon2.addPoint(point1);
	polygon2.addPoint(point2);
	polygon2.addPoint(point3);

	polygon2 >>= point5;

	bool test = (polygon1 == polygon2);
	std::cout << polygon1 << std::endl;
	std::cout << polygon2 << std::endl;
	std::cout << test << std::endl;

	//std::cout << the_length_of_the_straight_line(10, 0, 10, 10) << std::endl; 
	//std::cout << area_of_a_triangle(3, 4, 5) << std::endl;

	return 0;
}
