#pragma once

class Game
{
private:
	// Member variables here! (attributes; properties)
	bool m_Running;

public:
	Game(); // Construct
	~Game(); // Deconstruct

	bool getR() const;
	void setR(bool);

	void Initialize();
	void Running();
	void ShutDown();

	void InputSys();
	void UpdateSys();
	void DisplaySys();
};
