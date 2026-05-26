#include "pch.h"
#include "Monster.h"
#include "Player.h"
#include "Inventory.h"
#include "Database.h"
#include "Random.h"

CMonster::CMonster()
	: CCharacter()
{
	m_pInventory = nullptr;
	m_iGold = 0;
}

CMonster::CMonster(eMonsterCode _eMonsterCode)
{
	for (int i = 0; i < MAX_DB_ARRAY_SIZE; ++i)
	{
		if (DB::MonsterDB[i]._eMonsterCode == _eMonsterCode)
		{
			*this = DB::MonsterDB[i].Monster;
			return;
		}
	}
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
}

void CMonster::Initialize()
{
	m_pInventory = new CInventory;

	PickDropItems();

	random_device rd;
	int iRandomGold = (rd() % 7) - 3;
	m_iGold += iRandomGold;
}

void CMonster::Update()
{
}

void CMonster::Release()
{
}

void CMonster::OnDead(CPlayer* pPlayer)
{
	pPlayer->GetInventory()->UpdateGold(m_iGold);
	DropItem(pPlayer);
}

void CMonster::DropItem(CPlayer* pPlayer)
{
	for (int i = m_pInventory->GetItemCount(); i >= 0; --i)
	{
		pPlayer->GetInventory()->AddItem(m_pInventory->PopItem(i));
	}
}

void CMonster::PickDropItems()
{
	for (int i = 0; i < MAX_DB_ARRAY_SIZE; ++i)
	{
		if (DB::DropItemDB[i]._eMonsterCode == m_eMonsterCode)
		{
			double dRand = CRandom::Uniform(0.0, 1.0);
			if (dRand > DB::DropItemDB[i].dDropChance)
			{
				CItem* pItem = new CItem(DB::DropItemDB[i]._eItemCode);
				m_pInventory->AddItem(pItem);
			}
		}
	}
}
