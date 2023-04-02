#pragma once

class Update
{
private:
	bool _pause;

public:
	Update();
	~Update();

	void setCamera();
	void startCamera();
	void updateCamera();

	void playerDraw();
	void playerTexture();

	void playerMovement();
	void playerLimit();
	void playerCollision();

	bool getPause() const;
	void setPause(bool);

	void setSound();
};

