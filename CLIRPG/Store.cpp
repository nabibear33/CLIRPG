#include "pch.h"
#include "Store.h"
#include "Item.h"

CStore::CStore()
{
}

CStore::~CStore()
{
}

void CStore::Initialize()
{
}

void CStore::Update()
{
}

void CStore::Release()
{
}

bool CStore::IsValidItemChoice(int iChoice)
{
	return (iChoice <= m_Items.size()) && (iChoice >= 0);
}

void CStore::PrintItems()
{
	for (auto Item : m_Items)
	{
		Item->PrintItemInfo(true);
	}
}
