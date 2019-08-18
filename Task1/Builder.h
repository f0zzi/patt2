#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Plan
{
private:
	pair<string, int> found;
	pair<string, int> roof;
	pair<int, int> walls;
	pair<int, int> doors;
	pair<int, int> windows;
public:
	pair<string, int> GetFound() { return found; }
	pair<string, int> GetRoof() { return roof; }
	pair<int, int> GetWalls() { return walls; }
	pair<int, int> GetDoors() { return doors; }
	pair<int, int> GetWindows() { return windows; }
	Plan()
	{
		cout << "Enter found type: ";
		cin >> found.first;
		cout << "Enter found price: ";
		cin >> found.second;
		cout << "Enter roof type: ";
		cin >> roof.first;
		cout << "Enter roof price: ";
		cin >> roof.second;
		cout << "Enter number of walls:	";
		cin >> walls.first;
		cout << "Enter price of wall: ";
		cin >> walls.second;
		cout << "Enter number of doors: ";
		cin >> doors.first;
		cout << "Enter price of door: ";
		cin >> doors.second;
		cout << "Enter number of windows: ";
		cin >> windows.first;
		cout << "Enter price of window: ";
		cin >> windows.second;
	}
};

class Door
{
private: int price;
public:	Door(int price) : price(price) {}
};

class Wall
{
private: int price;
public: Wall(int price) : price(price) {}
};

class Window
{
private: int price;
public: Window(int price) : price(price) {}
};

class Roof
{
private: string type; int price;
public: Roof(string type, int price) : type(type), price(price) {}
		string GetType() { return type; }

};

class Found
{
private: string type; int price;
public: Found(string type, int price) : type(type), price(price) {}
		string GetType() { return type; }
};

class House
{
private:
	vector<Wall>walls;
	vector<Window>windows;
	vector<Door>doors;
	vector<Roof>roofs;
	vector<Found>founds;
public:
	void AddWall(int price)
	{
		walls.push_back(Wall(price));
	}
	void AddWindow(int price)
	{
		windows.push_back(Window(price));
	}
	void AddDoor(int price)
	{
		doors.push_back(Door(price));
	}
	void AddRoof(string type, int price)
	{
		roofs.push_back(Roof(type, price));
	}
	void AddFound(string type, int price)
	{
		founds.push_back(Found(type, price));
	}
	void PrintReport()
	{
		cout << "House report:" << endl;
		cout << "Found: " << founds.begin()->GetType() << endl;
		cout << "Walls";
		if (walls.size())
			cout << "\tx" << walls.size() << endl;
		else
			cout << "\t-" << endl;
		cout << "Windows";
		if (windows.size())
			cout << "\tx" << windows.size() << endl;
		else
			cout << "\t-" << endl;
		cout << "Doors";
		if (doors.size())
			cout << "\tx" << doors.size() << endl;
		else
			cout << "\t-" << endl;
		cout << "Roof: " << roofs.begin()->GetType() << endl;
	}
};

class Builder
{
public:
	virtual void Reset() = 0;
	virtual void MakeFound(string type, int price) {}
	virtual void MakeWalls(int price) {}
	virtual void MakeDoors(int price) {}
	virtual void MakeWindows(int price) {}
	virtual void MakeRoof(string type, int price) {}
};

class MoneyBuilder : public Builder
{
private:
	int money;
public:
	void Reset()
	{
		money = 0;
	}
	void MakeFound(string type, int price)
	{
		money += price;
	}
	void MakeWalls(int price)
	{
		money += price;
	}
	void MakeDoors(int price)
	{
		money += price;
	}
	void MakeWindows(int price)
	{
		money += price;
	}
	void MakeRoof(string type, int price)
	{
		money += price;
	}
	int GetMoney() const
	{
		return money;
	}
};

class BrickBuilder : public Builder
{
private:
	House* house;
public:
	void Reset()
	{
		house = new House();
	}
	void MakeFound(string type, int price)
	{
		house->AddFound(type, price);
	}
	void MakeWalls(int price)
	{
		house->AddWall(price);
	}
	void MakeDoors(int price)
	{
		house->AddDoor(price);
	}
	void MakeWindows(int price)
	{
		house->AddWindow(price);
	}
	void MakeRoof(string type, int price)
	{
		house->AddRoof(type, price);
	}
	House* GetHouse()
	{
		return house;
	}
};

class Director
{
private:
	Plan* plan;
	Builder* builder;
public:
	void SetBuilder(Builder& builder)
	{
		this->builder = &builder;
	}
	void SetPlan(Plan& plan)
	{
		this->plan = &plan;
	}
	void Build()
	{
		if (plan)
		{
			builder->Reset();
			builder->MakeFound(plan->GetFound().first, plan->GetFound().second);
			for (int i = 0; i < plan->GetWalls().first; i++)
				builder->MakeWalls(plan->GetWalls().second);
			for (int i = 0; i < plan->GetDoors().first; i++)
				builder->MakeDoors(plan->GetDoors().second);
			for (int i = 0; i < plan->GetWindows().first; i++)
				builder->MakeWindows(plan->GetWindows().second);
			builder->MakeRoof(plan->GetRoof().first, plan->GetRoof().second);
		}
		else
		{
			builder->Reset();
			builder->MakeFound("Concrete", 10);
			for (int i = 0; i < 4; i++)
				builder->MakeWalls(10);
			for (int i = 0; i < 1; i++)
				builder->MakeDoors(10);
			for (int i = 0; i < 2; i++)
				builder->MakeWindows(10);
			builder->MakeRoof("Tile", 10);
		}
	}
};