#pragma once

class World
{
private:
	Texture2D _texture;
	Rectangle _rectangle;

	Vector2 _position;
	Vector2 _size;
	Rectangle _drawSize;

public:
	World();
	~World();

	Texture2D getTexture() const;
	void setTexture(Texture2D);

	Rectangle getRectangle() const;
	void setRectangle(Rectangle);

	void worldDraw();
	void worldTexture();

	Vector2 getPosition() const;
	void setPosition(Vector2);

	Vector2 getSize() const;
	void setSize(Vector2);

	Rectangle getDrawSize() const;
	void setDrawSize(Rectangle);
};

