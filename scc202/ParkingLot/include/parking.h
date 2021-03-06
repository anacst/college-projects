#ifndef PARKING_H
	#define PARKING_H

	#include <stack.h>
	#include <queue.h>
	#include <car.h>
	#define MAX1 5
	#define MAX2 10

	int read_int() ;
	float read_float();	
	int parking_full(STACK*, QUEUE*);
	int departure_time(int, int);
	ITEM* check_in(STACK*, QUEUE*);
	void check_out(CAR*, STACK*, QUEUE*);
	float descount(CAR*, STACK*, QUEUE*, int);
	int availability(int, STACK*, QUEUE*);
	int rejection(int, int, int, STACK*, QUEUE*);
	void print(STACK* p1, QUEUE* p2);

#endif
