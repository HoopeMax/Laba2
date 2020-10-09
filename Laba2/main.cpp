			
//План
//1)Создать класс треугольник (поля класса:три стороны треугольника,
							 //метод проверки на существоание треугольника,
							 // метод вычисления и вывода сведений о фигуре – длины сторон, углы, периметр, площадь)
//2)Создать производный класс – равнобедренный треугольник (предусмотреть в классе проверку(метод), является ли треугольник равнобедренным)
//Задание: дано N треугольников и M равнобедренных треугольников, найти среднюю площадь для N треугольников и равнобедренный треугольник с наименьшей площадью


#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

//класс тругольника 
class Triangle
{
protected:

	double side_a, side_b, side_c;
public:
	//метод ввода сторон
	void Input_side()
	{
		std::cout << std::endl;
		std::cout << "Введите сторону а" << std::endl;
		std::cin>> side_a;
		std::cout << "Введите сторону b" << std::endl;
		std::cin >> side_b;
		std::cout << "Введите сторону c" << std::endl;
		std::cin >> side_c;
		std::cout << std::endl;
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
		return perimeter;
		
	}

	//метод поиска и вывода площади 
	double Search_Output_Area(double perimeter)
	{
		double half_perimeter = perimeter / 2;
		double Area = sqrt(half_perimeter * (half_perimeter - side_a) * (half_perimeter - side_b) * (half_perimeter - side_c));
		return Area;
	}
};


class Isosceles_Triangle : public  Triangle
{
public:
	//метод проверки на равнобедренность треугольника 
	void Сhecking_for_equal_sides()
	{
		bool check_equal_sides = true;
		while (check_equal_sides)
		{
			if ((side_a != side_b) && (side_a != side_c) && (side_b != side_c))
			{
				std::cout << std::endl << "Трегольник не равнобедренный, повторите ввод " << std::endl;
				Input_side();
				check_equal_sides = true;
			}
			else
			{
				check_equal_sides = false;
			}
		}
		
	}

};
//просто прикольный ввод
int  Input_size();

//Вывод методов для трегольников М
void Output_Triangle(int size, Triangle* object);

//Вывод методов для трегольников N
void Output_Isosceles_Triangle(int size1, Isosceles_Triangle* object2);

int main(void)
{
	
	int size(0);
	int size1(0);
	
	setlocale(LC_ALL, "rus");

	std::cout << std::endl << "Ведите количество N треугольников: " ;
	size = Input_size();

	std::cout << std::endl << "Ведите количество M равнобедрнных треугольников: ";
	size1 = Input_size();


	Triangle* object = new Triangle [size];
	Isosceles_Triangle* object2 = new Isosceles_Triangle [size1];

	Output_Triangle(size, object);

	Output_Isosceles_Triangle(size1, object2);

	system("pause");
	return 0;
}

int  Input_size()
{
	int size;
	std::cin >> size;
	return size;
};

void Output_Triangle(int size, Triangle* object)
{
	double average(0);
	for (int i = 0; i < size; i++)
	{
		object[i].Input_side();
		object[i].Existence_Of_A_Triangle();
		object[i].Search_Output_Angles();

		std::cout << std::endl << "Периметр" << i + 1 << "треугольника = " << object[i].Search_Output_Perimeter() << std::endl;
		std::cout << std::endl << "Площадь " << i + 1 << "треугольника = " << object[i].Search_Output_Area(object[i].Search_Output_Perimeter()) << std::endl;
		
		//найти среднюю площадь для N треугольников
		average += object[i].Search_Output_Area(object[i].Search_Output_Perimeter());
		std::cout << std::endl << "____________________________" << std::endl;
		system("pause");
		//system("cls");

	}
	std::cout << std::endl << "####################################" ;
	std::cout << std::endl << "Средняя площадь для треугольников М = " << average << std::endl;
	std::cout  << "####################################" << std::endl;
}

void Output_Isosceles_Triangle(int size1, Isosceles_Triangle* object2)
{
	double min = object2[0].Search_Output_Area(object2[0].Search_Output_Perimeter());

	for (int i = 0; i < size1; i++)
	{
		object2[i].Input_side();
		object2[i].Existence_Of_A_Triangle();
		object2[i].Сhecking_for_equal_sides();
		object2[i].Search_Output_Angles();

		std::cout << std::endl << "Периметр" << i + 1 << " треугольника = " << object2[i].Search_Output_Perimeter() << std::endl;
		std::cout << std::endl << "Площадь" << i + 1 << " треугольника = " << object2[i].Search_Output_Area(object2[i].Search_Output_Perimeter()) << std::endl;

		//найти минимальную площадь для M треугольников 
		if (min > object2[i].Search_Output_Area(object2[i].Search_Output_Perimeter()))
		{
			min = object2[i].Search_Output_Area(object2[i].Search_Output_Perimeter());
		}


		std::cout << std::endl << "____________________________" << std::endl;
		system("pause");
		//system("cls");
	}
	std::cout << std::endl << "####################################";
	std::cout << std::endl << "минимальная площадь =" << min << std::endl;
	std::cout << "####################################" << std::endl;

}