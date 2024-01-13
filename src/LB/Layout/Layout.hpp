#pragma once

class Layout
{
private:
	/* data */
	int ySpace;
	int xSpace;



public:
	Layout(/* args */);
	~Layout();

	virtual void updateLayout() = 0;
};

Layout::Layout(/* args */)
{
}

Layout::~Layout()
{
}
