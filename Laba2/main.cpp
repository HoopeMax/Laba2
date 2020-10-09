			
//����
//1)������� ����� ����������� (���� ������:��� ������� ������������,
							 //����� �������� �� ������������ ������������,
							 // ������������� ����� ���������� � ������ �������� � ������ � ����� ������, ����, ��������, �������)
//2)������� ����������� ����� � �������������� ����������� (������������� � ������ ��������(�����), �������� �� ����������� ��������������)
//�������: ���� N ������������� � M �������������� �������������, ����� ������� ������� ��� N ������������� � �������������� ����������� � ���������� ��������


#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

//����� ����������� 
class Triangle
{
public:

	double side_a, side_b, side_c;

	//����� ����� ������
	void Input_side()
	{
		std::cout << std::endl;
		std::cout << "������� ������� �" << std::endl;
		std::cin>> side_a;
		std::cout << "������� ������� b" << std::endl;
		std::cin >> side_b;
		std::cout << "������� ������� c" << std::endl;
		std::cin >> side_c;
		std::cout << std::endl;
	}

	//����� �������� �� ������������ ������������
	void Existence_Of_A_Triangle()
	{
		bool flag = true;
		while(flag)
		{
			if ((side_a >= (side_b + side_c)) || (side_b >= (side_a + side_c)) || (side_c >= (side_b + side_a)))
			{
				std::cout << std::endl << "������ ������������ �� ����������,��������� ����" << std::endl;
				Input_side();
			}
			else 
				flag = false;
		}
	}

	//����� ����� � ����� �����
	void Search_Output_Angles()
	{
		double  angle_alpha, angle_beta, angle_gamma;

		angle_alpha = acos(((side_a * side_a) + (side_c * side_c) - (side_b * side_b)) / (2. * side_a * side_c));
		angle_beta = acos(((side_a * side_a) + (side_b * side_b) - (side_c * side_c)) / (2. * side_a * side_b));
		angle_gamma = acos(((side_b * side_b) + (side_c * side_c) - (side_a * side_a)) / (2. * side_c * side_b));

		angle_alpha = (angle_alpha * 180) / M_PI;
		angle_beta = (angle_beta * 180) / M_PI;
		angle_gamma = (angle_gamma * 180) / M_PI;

		std::cout << std::endl << "���� �����=" << angle_alpha << std::endl;
		std::cout << "���� ����=" << angle_beta << std::endl;
		std::cout << "���� �����=" << angle_gamma << std::endl;
	}

	//����� ������ � ������ ���������  
	double Search_Output_Perimeter()
	{
		double perimeter = side_a + side_b + side_c;
		std::cout << std::endl << "�������� ������������ = " << perimeter << std::endl;
		return perimeter;
		
	}

	//����� ������ � ������ ������� 
	double Search_Output_Area(double perimeter)
	{
		double half_perimeter = perimeter / 2;
		double Area = sqrt(half_perimeter * (half_perimeter - side_a) * (half_perimeter - side_b) * (half_perimeter - side_c));
		std::cout << std::endl << "������� ������������ = " << Area << std::endl;
		return Area;
	}
};

class Isosceles_Triangle : public  Triangle
{
public:
	//����� �������� �� ���������������� ������������ 
	void �hecking_for_equal_sides()
	{
		bool check_equal_sides = true;
		while (check_equal_sides)
		{
			if ((side_a != side_b) && (side_a != side_c) && (side_b != side_c))
			{
				std::cout << std::endl << "���������� �� ��������������, ��������� ���� " << std::endl;
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

int  Input_size();

int main(void)
{
	
	int size(0);
	int size1(0);
	double average(0);

	setlocale(LC_ALL, "rus");

	std::cout << std::endl << "������ ���������� N �������������: " ;
	size = Input_size();

	std::cout << std::endl << "������ ���������� M ������������� �������������: ";
	size1 = Input_size();


	Triangle* object = new Triangle [size];
	Isosceles_Triangle* object2 = new Isosceles_Triangle [size1];

	for (int i=0; i < size; i++)
	{
		object[i].Input_side();
		object[i].Existence_Of_A_Triangle();
		object[i].Search_Output_Angles();
		average += object[i].Search_Output_Area(object[i].Search_Output_Perimeter());//����� ������� ������� ��� N �������������
		std::cout << std::endl << "____________________________" <<  std::endl;	
		system("pause");
		//system("cls");
		
	}
	
	std::cout << std::endl << "������� ������� ��� N ������������� = " << average / size << std::endl;

	for (int i = 0; i < size1; i++)
	{
		object2[i].Input_side();
		object2[i].Existence_Of_A_Triangle();
		object2[i].�hecking_for_equal_sides();
		object2[i].Search_Output_Angles();
		object2[i].Search_Output_Area(object2[i].Search_Output_Perimeter());
		std::cout << std::endl << "____________________________" << std::endl;
		system("pause");
		//system("cls");

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


