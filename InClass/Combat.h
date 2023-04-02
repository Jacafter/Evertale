#pragma once

class Combat
{
private:
	Vector2 _position;
	Vector2 _size;

	bool _active;

public:
	Combat();
	~Combat();

	bool getCombatActive() const;
	void setCombatActive(bool);

	Vector2 getPosition() const;
	void setPosition(Vector2);

	Vector2 getSize() const;
	void setSize(Vector2);

	void enemyText();
	void bossText();
	void folkText();

	void combatAttack();
	void combatRun();
	void combatTrade();
	void combatWalkAway();
};

