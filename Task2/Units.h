#pragma once

enum Type { marine, technic, medic, none };
const char* typeNames[4] = { "marine", "technic", "medic", "none" };

class Unit abstract
{
private:
	int hp = 0;
	int damage = 0;
	Type type = none;
public:
	void SetHp(int hp)
	{
		this->hp = hp;
	}
	void SetDamage(int damage)
	{
		this->damage = damage;
	}
	void SetType(Type type)
	{
		this->type = type;
	}
	int GetDamage() const
	{
		return damage;
	}
	int GetHp() const
	{
		return hp;
	}
	Type GetType() const
	{
		return type;
	}
	const char* GetTypeStr() const
	{
		return typeNames[GetType()];
	}
	virtual const char* Ability() const = 0;
};

class Marine : public Unit
{
public:
	Marine()
	{
		SetHp(100);
		SetDamage(20);
		SetType(marine);
	}
	const char* Ability() const
	{
		return "Steampack";
	}
};

class Technic : public Unit
{
public:
	Technic()
	{
		SetHp(50);
		SetDamage(10);
		SetType(technic);
	}
	const char* Ability() const
	{
		return "Place turret";
	}
};

class Medic : public Unit
{
public:
	Medic()
	{
		SetHp(70);
		SetDamage(15);
		SetType(medic);
	}
	const char* Ability() const
	{
		return "Heal";
	}
};

__interface Barrack
{
	Unit* CreateUnit();
};

class MilitaryAcademy : public Barrack
{
	Unit* CreateUnit()
	{
		return new Marine;
	}
};

class TechnicalAcademy : public Barrack
{
	Unit* CreateUnit()
	{
		return new Technic;
	}
};

class MedicalAcademy : public Barrack
{
	Unit* CreateUnit()
	{
		return new Medic;
	}
};