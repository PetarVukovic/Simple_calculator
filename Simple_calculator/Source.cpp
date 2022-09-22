#include <iostream>
#include <vector>
#include <string>

struct Operation
{
	float virtual calculate(float a, float  b) = 0;
	std::string virtual print() = 0;

};
struct Add :public Operation
{
	float calculate(float a, float b)
	{
		return a + b;
	}
	std::string print()
	{
		return "Addition";
	}
};
struct Subtraction :public Operation
{
	float calculate(float a, float b)
	{
		return a - b;
	}

	std::string print()
	{
		return "Subtraction";
	}
};
struct Multiplicatin :public Operation
{
	float calculate(float a, float b)
	{
		return a * b;
	}

	std::string print()
	{
		return "Multiplicatin";
	}

};
struct Divison :public Operation
{
	float calculate(float a, float b)
	{
		return a / b;
	}

	std::string print()
	{
		return "Divison";
	}

};

int main()
{
	std::vector<Operation*>operations;
	operations.push_back(NULL);
	operations.push_back(new Add{});
	operations.push_back(new Subtraction{});
	operations.push_back(new Multiplicatin{});
	operations.push_back(new Divison{});

	for (int i = 1; i < operations.size(); i++)
	{
		auto current_operations = operations[i];
		std::cout << i << ":" << current_operations->print() << std::endl;
	}
	do
	{
		int index;
		float a, b;
		do
		{
			std::cout << "What operations do you want?" << std::endl;
			std::cin >> index;

		} while (index <= 0 || index > operations.size());

		auto current_op = operations[index];
		std::cout << "You chose:" << current_op->print() << std::endl;
		std::cout << "Inesert two numbers" << std::endl;

		std::cin >> a >> b;
		std::cout << "Your result:" << current_op->calculate(a, b) << std::endl;

	} while (1);

	return 0;
}
