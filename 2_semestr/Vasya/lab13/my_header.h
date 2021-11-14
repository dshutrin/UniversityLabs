#pragma once
using namespace std;

struct NOTEBOOK{
	string model;
	struct size{
		float x;
		float y;
		float z;
	};
	float w;
	int price;
	int hard_drive;
	size n_size;
};