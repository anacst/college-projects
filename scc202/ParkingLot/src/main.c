#include <stdio.h>
#include <stdlib.h>

#include <parking.h>
#include <stack.h>
#include <queue.h>

void register_car(STACK* p1, QUEUE* p2) {
	ITEM* new_car = check_in(p1, p2);
	
	if (!new_car)
		return;
	
	check_out(new_car, p1, p2);

	descount(new_car, p1, p2, (size_stack(p1)+size_queue(p2)));
	
	int cond = availability(getDeparture(new_car), p1, p2);
	
	if(rejection(getArrival(new_car), getDeparture(new_car), cond, p1, p2))
		return;

	if(cond == 1)
		push(new_car, p1);
	else if(cond == 2)
		enqueue(new_car, p2);
}

void print_cars(STACK* p1, QUEUE* p2) {
	print(p1, p2);
}

void end(STACK** p1, QUEUE** p2) {
	destroy_stack(p1);
	destroy_queue(p2);
}

void options(int op, STACK* patio_1, QUEUE* patio_2) {

	menu(STACK* patio_1, QUEUE* patio_2);

		switch(op) {
			case 1: register_car(patio_1, patio_2);
					break;

			case 2: print(patio_1, patio_2);
					break;
	
			case 3: end(&patio_1, &patio_2);
					exit(0);
					break;
		}

	menu(patio_1, patio_2);
}

void menu(STACK* patio_1, QUEUE* patio_2) {

	int op;
	
	printf("\n\n");
	printf("\t\t\tMENU\n\n");
	printf("\t(1) Registrar Carro\n");
	printf("\t(2) Imprimir Carros\n");
	printf("\t(3) Sair\n");
	printf("\n\tSelecione uma opção: ");

	op = read_int();

	while(op < 1 || op > 3) {
		getchar();
		printf("\n\tSelecione uma opção: ");
		op = read_int();
	}
	
	options(op, patio_1, patio_2);
}

int main(void) {
	
	STACK* patio_1 = create_stack();
	QUEUE* patio_2 = create_queue();

	menu(patio_1, patio_2);
}
