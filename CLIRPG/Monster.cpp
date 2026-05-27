#include "pch.h"
#include "Monster.h"
#include "Player.h"
#include "Inventory.h"
#include "Database.h"
#include "Random.h"
#include "Memory.h"

CMonster::CMonster()
	: CCharacter()
{
	m_pInventory = nullptr;
	m_iGold = 0;
}

CMonster::CMonster(eMonsterCode _eMonsterCode)
{
}


CMonster::CMonster(eMonsterCode _eMonsterCode, const char szName[], int iMaxHP, int iHP, int iAttack, int iGold)
	: CCharacter(szName, iMaxHP, iHP, iAttack)
{
	m_pInventory = nullptr;
	m_eMonsterCode = _eMonsterCode;
	m_iGold = iGold; 
}

CMonster::CMonster(const CMonster& other) : CCharacter(other)
{
	m_pInventory = other.m_pInventory;
	m_eMonsterCode = other.m_eMonsterCode;
	m_iGold = other.m_iGold;
}

CMonster::~CMonster()
{
	SafeDeleteSingle(m_pInventory);
}

void CMonster::Initialize()
{
	m_pInventory = new CInventory;

	PickDropItems();

	m_iGold += CRandom::UniformInt(-3, 3);
}

void CMonster::Update()
{
}

void CMonster::Release()
{
}

CCharacter* CMonster::Clone()
{
	return new CMonster(*this);
}

void CMonster::OnDead(CPlayer* pPlayer)
{
	pPlayer->GetInventory()->UpdateGold(m_iGold);
	cout << m_iGold << " 골드를 플레이어가 획득" << endl;

	DropItem(pPlayer);
}

void CMonster::DropItem(CPlayer* pPlayer)
{
	for (int i = m_pInventory->GetItemCount(); i > 0; --i)
	{
		CItem* pDroppedItem = m_pInventory->PopItem(i - 1);
		
		cout << "아이템 " << pDroppedItem->GetName() << "을(를) 플레이어가 획득" << endl;
		pPlayer->GetInventory()->AddItem(pDroppedItem);
	}
}

void CMonster::PickDropItems()
{
	for (int i = 0; i < MAX_DB_ARRAY_SIZE; ++i)
	{
		if (DB::DropItemDB[i]._eMonsterCode == m_eMonsterCode)
		{
			double dRand = CRandom::UniformReal(0.0, 1.0);
			if (dRand > DB::DropItemDB[i].dDropChance)
			{
				CItem* pItem = CItem::Create(DB::DropItemDB[i]._eItemCode);
				m_pInventory->AddItem(pItem);
			}
		}
	}
}
