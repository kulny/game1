#pragma once
class Production
{
public:
	Production();
	~Production();

private:
	bool factoryBought;
	long resource1;
	bool outOfRes;
	double resIncrsRtl;
	double resIncrsMod;

	int ResProduction();


};

