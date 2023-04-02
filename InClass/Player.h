#pragma once

class Player
{
private:
    Vector2 _position;
    Rectangle _rectangle;
    Texture2D _texture;

protected:
    int _attack;
    int _lifePoints;
    int _gold;

public:
    Player();
    ~Player();

    Vector2 getPosition() const;
    void setPosition(Vector2);

    Rectangle getRectangle() const;
    void setRectangle(Rectangle);

    Texture2D getTexture() const;
    void setTexture(Texture2D);

    int getLife() const;
    void setLife(int);

    int getAttack() const;
    void setAttack(int);
};

// Childs
class Avatar : public Player
{
private:

public:
    Avatar();
    ~Avatar();
        
    int getGold() const;
    void setGold(int gold);

};

class NPC : public Player
{
private:
    Vector2 _size;
    Rectangle _drawSize;
    bool _active;

protected:
    int _speed;

public:
    NPC();
    ~NPC();

    bool getStatus() const;
    void setStatus(bool);

    int getSpeed() const;

    Vector2 getSize() const;
    void setSize(Vector2);

    Rectangle getDrawSize() const;
    void setDrawSize(Rectangle);
};

// NPC's Child
class Enemy : public NPC
{
private:

public:
    Enemy();
    ~Enemy();
};

class Folk : public NPC
{
private:

public:
    Folk();
    ~Folk();
};

class Boss : public NPC
{
private:

public:
    Boss();
    ~Boss();
};