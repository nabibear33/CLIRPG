#pragma once

class CItem;
class CPlayer;

class CStore
{
public:
	CStore();
	virtual ~CStore();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	void Sell(CPlayer* Player, CItem* Item);
	void Buy(CPlayer* Player, CItem* Item);

	void PrintItems();

private:
	CItem* Equipments;
	CItem* Consumables;

	int iCurrentTab = 0;

};

