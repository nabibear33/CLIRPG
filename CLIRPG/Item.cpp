#include "pch.h"
#include "Item.h"


CItem::CItem()
{
	strcpy_s(m_szName, sizeof(m_szName), "");
	strcpy_s(m_szDetail, sizeof(m_szDetail), "");
}

CItem::CItem(const char szName[])
{
	strcpy_s(m_szName, sizeof(m_szName), szName);
	strcpy_s(m_szDetail, sizeof(m_szDetail), "");
	// strcpy_s(m_szDetail, sizeof(m_szDetail), szDetail);
	
}

CItem::~CItem()
{
}

void CItem::Initialize()
{
}

void CItem::Update()
{
}

void CItem::Release()
{
}
