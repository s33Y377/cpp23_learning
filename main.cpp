#include <iostream>
#include <print>
#include <cmath>
#include <expected>
#include <iomanip>
#include <string_view>
#include <cstdlib>

using namespace std;

enum class parse_error
{
	invalid_input,
	overflow
};

int Add(int x, int y);

static auto parse_number(std::string_view& str) -> std::expected<double, parse_error>
{
	const char* begin = str.data();
	char* end;
	double retval = std::strtod(begin, &end);

	if (begin == end)
		return std::unexpected(parse_error::invalid_input);
	else if (std::isinf(retval))
		return std::unexpected(parse_error::overflow);

	str.remove_prefix(end - begin);
	return retval;
}

static unsigned long fibonacci(unsigned int n) {
	if (n <= 1) {
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

static int health() {
	unsigned int Health{ 0 };
	Health -= 1;
	return Health;
}

int Health { 100 };
static void TakeDamage(int Damage = 1) {
	cout << "Inflicting " << Damage << " Damage";
	Health -= Damage;
	cout << " - Health: " << Health << '\n';
}

static bool GetHealth() {
	return false;
}

static void test_function() {
	unsigned int n{ 5 };

	std::cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << std::endl;

	bool isAlive{ true };
	std::cout << "isAlive : " << isAlive << std::endl;

	std::string Name{ "Goblin Warrior" };
	std::cout << "Name : " << Name << std::endl;

	int LargeNumber{ 100'000'000 };
	std::cout << "LargeNumber : " << LargeNumber << std::endl;

	int Level{ 2 + 3 };
	std::cout << "Level : " << Level << std::endl;

	int Level1{ (1 + 2) * 3 };
	std::cout << "Level1 : " << Level1 << std::endl;

	Level++;  // Level is now 6
	std::cout << "Level : " << Level << std::endl;
	++Level;  // Level is now 7
	std::cout << "Level : " << Level << std::endl;

	Level -= 3; // Level is now 5
	Level *= 3;  // Level is now 15
	Level /= 5; // Level is now 3
	Level *= Level; // Level is now 9

	int NegativeValue{ -5 };
	std::cout << "Health : " << health() << std::endl;

	int Input{ 4 };
	int Result{ -Input }; // Result is -4
	std::cout << "Result : " << Result << std::endl;

	std::cout << "Result : " << Result << std::endl;

	int Vakue{ 20 };
	int TargetLevel{ 20 };
	// This will be true
	bool isTargetLevel{ Vakue == TargetLevel };
	std::cout << "isTargetLevel : " << isTargetLevel << std::endl;

	bool MyBoolean{ 15 >= 10 + 5 };
	std::cout << "MyBoolean : " << MyBoolean << std::endl;

	TakeDamage();


	string MyString{ "Hello" };
	//float MyNumber{ MyString };

	GetHealth();

	double Pi{ 3.14 };

	float test{ 3.0 };
	cout << endl << "Pi :" << Pi << endl;

	auto process = [](std::string_view str)
		{
			std::cout << "str: " << std::quoted(str) << ", ";
			if (const auto num = parse_number(str); num.has_value())
				std::cout << "value: " << *num << '\n';
			else if (num.error() == parse_error::invalid_input)
				std::cout << "error: invalid input\n";
			else if (num.error() == parse_error::overflow)
				std::cerr << "error: overflow\n";
			else
				std::cerr << "unexpected!\n"; // or invoke std::unreachable();
		};

	for (auto src : { "42", "42abc", "meow", "inf" })
		process(src);

	int Add_var{ Add(2,3) };
	cout << "Add : " << Add_var << endl;

	cout << "Loop => " << endl;
	int i{ 0 };
	while (i <= 10) {
		++i;
		if (i == 6) continue;
		if (i % 2 == 0) {
			cout << "even : " << i << endl;
		}
	}
	cout << endl;

	for (int Number{ 1 }; Number < 10; Number++) {
		cout << Number << ", ";
	}
	cout << endl;

	int Number{ 1 };
	for (; Number < 10; ) {
		cout << Number << ", ";
		++Number;
	}
	cout << endl;
}

class Monster {
public:	
	int Health{ 150 };

	void TakeDamage(int Damage) {
		Health -= Damage;
	}
};

class Monster2 {
public:
	int Health{ 150 };
	// Declaration
	void TakeDamage(int Damage);
};

// Definition
void Monster2::TakeDamage(int Damage) {
	Health -= Damage;
}

class Monster3 {
public:
	int Health{ 150 };

	void TakeDamage(int Damage) {
		Health -= Damage;
		if (Health < 0) { Health = 0; }
	}
};

class Monster4 {
public:
	Monster4() {
		cout << "Ready for Battle!" << endl;
	}

	~Monster4() {
		cout << "Battle ended by deconstructor !" << endl;
	}

private:
	string mName;
};

class Monster5 {
public:
	explicit Monster5(string const& mName) {
		cout << mName << " Ready for Battle!" <<endl;
	}

	explicit Monster5(string const& mName,  string const& mLastname) {
		cout << mName << " " << mLastname << endl;
	}
private:
	string mName;
};

struct Vector3 {
	float x;
	float y;
	float z;
};

Vector3 operator+(Vector3 a, Vector3 b) {
	return Vector3{
	  a.x + b.x,
	  a.y + b.y,
	  a.z + b.z
	};
}

class Actor {
public:
	void Render() {}
};

class Character : public Actor {
public:
	void Move() {}
	void Attack() {}
	void DropLoot() {}
};

class Goblin : public Character {
public:
	void Enrage() {}
};

class Dragon : public Character {
public:
	void Fly() {}
};

void class_inheritance() {
	Dragon Dave;

	// Dave is an Actor
	Dave.Render();

	// And a Character
	Dave.Attack();

	// And a Dragon
	Dave.Fly();
};

void class_calls() {
	Monster2 Bonker2;
	Monster2 Basher2;
	cout << "Bonker Health: " << Bonker2.Health << endl;
	cout << "\nBasher Health: " << Basher2.Health << endl;
	Bonker2.TakeDamage(20);
	cout << "Bonker Health: " << Bonker2.Health << endl;



	Monster Bonker;
	Monster Basher;
	cout << "Bonker Health: " << Bonker.Health;
	cout << "\nBasher Health: " << Basher.Health;

	Bonker.Health = 50;
	cout << "\nBonker Health: " << Bonker.Health;
	cout << "\nBasher Health: " << Basher.Health << endl;

	Monster3 Goblin;
	Goblin.Health -= 200;
	cout << "Health: " << Goblin.Health << " :(" << endl;

	Monster4 Goblin1;

	Monster5 Goblin5{ "Sarvesh" };

	Monster5 Goblin651{ "Sarvesh" , "Vishwakarma" };

	Vector3 CurrentPosition{ 1.0, 2.0, 3.0 };
	Vector3 Movement{ 4.0, 5.0, 6.0 };
	Vector3 NewPosition{
	  CurrentPosition + Movement
	};

	std::cout
		<< "x= " << NewPosition.x
		<< ", y = " << NewPosition.y
		<< ", z = " << NewPosition.z
		<< endl;
};

int main() {
	if (__cplusplus == 202101L) std::cout << "C++23";
	else if (__cplusplus == 202002L) std::cout << "C++20";
	else if (__cplusplus == 201703L) std::cout << "C++17";
	else if (__cplusplus == 201402L) std::cout << "C++14";
	else if (__cplusplus == 201103L) std::cout << "C++11";
	else if (__cplusplus == 199711L) std::cout << "C++98";
	else std::cout << "pre-standard C++." << __cplusplus;
	std::cout << "\n";

	class_calls();
	class_inheritance();
	
	return 0;
}

int Add(int x, int y) {
	return x + y;
}