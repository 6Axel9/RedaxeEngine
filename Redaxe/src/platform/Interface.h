#pragma once
class Interface
{
public:
	Interface();
	~Interface();
public:
	void Open();
	void Bind();
	void Update();
	void Close();
public:
	bool HasClosed();
private:
};

