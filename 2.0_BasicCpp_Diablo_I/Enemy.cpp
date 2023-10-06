#include "Enemy.h"
#include "Player.h"

namespace diablo_I {

	Enemy::Enemy():
		attackDamage(0), hp(0), enemyWeakness(Enemy_Tag::ENEMY_WEAKNESS_DEFAULT), enemyType(Enemy_Tag::ENEMY_TYPE_SKELETON)
	{
	}

	int& Enemy::GetEnemyHp() {
		return hp;
	}

	Enemy_Tag Enemy::GetEnemyType() {
		return enemyType;
	}

	const uint8_t& Enemy::GetEnemyAttackDamageValue()const {
		return attackDamage;
	}
	void Enemy::EnemyGetDamage(const uint16_t& someDamage) {
		hp -= someDamage;
		switch (this->GetEnemyType()) {
		case Enemy_Tag::ENEMY_TYPE_SKELETON:
			if (hp <= 0) {
				std::cout << "\n\nYou killed a skeleton\n";
			}
			else {
				std::cout << "\n\nYou damaged a skeleton\n";
			}
			break;
		case Enemy_Tag::ENEMY_TYPE_VAMPIRE_KNIGHT:
			if (hp <= 0) {
				std::cout << "\n\nYou killed a vampire \n";
			}
			else {
				std::cout << "\n\nYou damaged a vampire \n";
			}
			break;
		case Enemy_Tag::ENEMY_TYPE_DRAGON_GUARDIANT:
			if (hp <= 0) {
				std::cout << "\n\nYou killed a dragon \n";
			}
			else {
				std::cout << "\n\nYou damaged a dragon \n";
			}
			break;
		}

	}

}