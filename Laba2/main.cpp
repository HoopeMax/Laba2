			
//План
//1)Создать класс треугольник (поля класса:три стороны треугольника,
							 //метод проверки на существоание треугольника,
							 // перегруженный метод вычисления и вывода сведений о фигуре – длины сторон, углы, периметр, площадь)
//2)Создать производный класс – равнобедренный треугольник (предусмотреть в классе проверку(метод), является ли треугольник равнобедренным)
//Задание: дано N треугольников и M равнобедренных треугольников, найти среднюю площадь для N треугольников и равнобедренный треугольник с наименьшей площадью


#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

//класс тругольника 
class Triangle
{
public:

	double side_a, side_b, side_c;

	//метод ввода сторон
	void Input_side()
	{
		std::cout << "Введите сторону а" << std::endl;
		std::cin>> side_a;
		std::cout << "Введите сторону b" << std::endl;
		std::cin >> side_b;
		std::cout << "Введите сторону c" << std::endl;
		std::cin >> side_c;
	}

	//метод проверки на существоание треугольника
	void Existence_Of_A_Triangle()
	{
		bool flag = true;
		while(flag)
		{
			if ((side_a >= (side_b + side_c)) || (side_b >= (side_a + side_c)) || (side_c >= (side_b + side_a)))
			{
				std::cout << std::endl << "Такого треугольника не существует,повторите ввод" << std::endl;
				Input_side();
			}
			else 
				flag = false;
		}
	}

	//метод поиск и вывод углов
	void Search_Output_Angles()
	{
		double  angle_alpha, angle_beta, angle_gamma;

		angle_alpha = acos(((side_a * side_a) + (side_c * side_c) - (side_b * side_b)) / (2. * side_a * side_c));
		angle_beta = acos(((side_a * side_a) + (side_b * side_b) - (side_c * side_c)) / (2. * side_a * side_b));
		angle_gamma = acos(((side_b * side_b) + (side_c * side_c) - (side_a * side_a)) / (2. * side_c * side_b));

		angle_alpha = (angle_alpha * 180) / M_PI;
		angle_beta = (angle_beta * 180) / M_PI;
		angle_gamma = (angle_gamma * 180) / M_PI;

		std::cout << std::endl << "Угол альфа=" << angle_alpha << std::endl;
		std::cout << "Угол бета=" << angle_beta << std::endl;
		std::cout << "Угол гамма=" << angle_gamma << std::endl;
	}

	//метод поиска и вывода периметра  
	double Search_Output_Perimeter()
	{
		double perimeter = side_a + side_b + side_c;
		std::cout << std::endl << "Периметр треугольника = " << perimeter << std::endl;
		return perimeter;
		
	}

	//метод поиска и вывода площади 
	void Search_Output_Area(double perimeter)
	{
		double half_perimeter = perimeter / 2;
		double Area = sqrt(half_perimeter * (half_perimeter - side_a) * (half_perimeter - side_b) * (half_perimeter - side_c));
		std::cout << std::endl << "Площадь треугольника = " << Area << std::endl;
	}
};

class Isosceles_Triangle : public  Triangle
{
	//метод проверки на равнобедренность треугольника 
	void Сhecking_for_equal_sides()
	{
		if ((side_a== side_b)||(side_a== side_c)||(side_b== side_c))
		{
			std::cout << std::endl << "Трегольник равнобедренный "  << std::endl;

		}
		else
		{ 
			std::cout << std::endl << "Трегольник не равнобедренный " << std::endl;
		}

	}

};

int  Input_size();

int main(void)
{
	
	int size(0);
	int size1(0);

	setlocale(LC_ALL, "rus");

	std::cout << std::endl << "Ведите количество треугольников: " ;
	size = Input_size();

	std::cout << std::endl << "Ведите количество равнобедрнных треугольников: ";
	size1 = Input_size();


	Triangle* object = new Triangle [size];
	//Isosceles_Triangle object2 [size];

	for (int i=0; i < size; i++)
	{
		object[i].Input_side();
		object[i].Existence_Of_A_Triangle();
		object[i].Search_Output_Angles();
		object[i].Search_Output_Area(object[i].Search_Output_Perimeter());
		std::cout << std::endl << "____________________________" <<  std::endl;	
		system("pause");
		system("cls");
		
	}
	
	system("pause");
	return 0;
}

int  Input_size()
{
	int size;
	std::cin >> size;
	return size;
};