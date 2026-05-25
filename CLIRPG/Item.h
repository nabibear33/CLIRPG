#pragma once

class CItem
{
public:
	CItem();
	CItem(const char szName[]);
	virtual ~CItem();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

private:
	char m_szName[MAX_NAME_SIZE];

	// TODO : Import Item Info from Outer Source
	char m_szDetail[MAX_DETAIL_SIZE];

	int iSellPrice;
	int iBuyPrice;
};

