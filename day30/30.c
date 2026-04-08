#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	int degree;
	struct node *next;
	struct node *prev;
}*poly1=NULL,*poly2=NULL,*poly3=NULL,*new,*temp;

void get_element(int power){
	new = (struct node *)malloc(sizeof(struct node));
	if(new != NULL){
		printf("\nenter the coffience of x^%d: ",power);
		scanf("%d",&new->data);
		new->degree = power;
		new->next = NULL;
		new->prev = NULL;
	}
	else{
		printf("DMA unsuccessful\n");
	}
}

struct node* create_poly(struct node *poly){
	if(poly != NULL){
		printf("\npolynomial already created !!!\n");
		return poly;
	}
	else{
		printf("\nenter the degree of the polynomial: ");
		int power;
		scanf("%d",&power);
		while ( power >= 0 ){
			get_element( power );
			if(poly == NULL){
				poly = new;
				temp = poly;
			}
			else{
				poly->next = new;
				new->prev = poly;
				poly = new;
			}
			power --;
		}
	}
	return temp;
}

void add_sub(int a, int b, int power, int c){
	new = (struct node *)malloc(sizeof(struct node));
	if (new != NULL){
		if (c == 1){
			new->data= a + b;
		}
		else {
			new->data= a - b;
		}
		new->degree = power;
		new->next = NULL;
		new->prev = NULL;
	}	
	else{
		printf("\nDMA unsuccessful\n");
	}
}

struct node* add_sub_poly(struct node *p1, struct node *p2, struct node *p3,int c){
	if (p1==NULL && p2 == NULL){
		printf("\npolynomial are not created\n");
		return NULL;
	}
	while (1){
		if(p1->degree == p2->degree){
			add_sub(p1->data , p2->data ,p1->degree,c);
			if(p3==NULL){
				p3 = new;
				temp = p3;
			}
			else{
				p3->next = new;
				new->prev = p3;
				p3 = new;
			}
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->degree>p2->degree){
			add_sub(p1->data,0,p1->degree,c);
			if(p3 == NULL){
				p3 = new;
				temp = p3;
			}
			else{
				p3->next = new;
				new->prev = p3;
				p3 = new;
			}
			p1=p1->next;
		}
		else{
			add_sub(0,p2->data,p2->degree,c);
			if(p3 == NULL){
				p3= new;
				temp = p3;
			}
			else{
				p3->next = new;
				new->prev = p3;
				p3= new;
			}
			p2=p2->next;
		}
		if( p3->degree == 0){
			break;
		}
	}
	return temp;
}

void print_poly(struct node *poly) {
    if (poly == NULL) {
        printf("This polynomial is empty\n");
        return;
    }

    int first = 1; 

    while (poly != NULL) {
        if (poly->data != 0) {
            
            if (poly->prev != NULL) {
                if (poly->data > 0) {
                    printf(" + ");
                } else {
                    printf(" - ");
                }
            } else {
                if (poly->data < 0) {
                    printf("-");
                }
            }

            
            int coeff = (poly->data < 0) ? -poly->data : poly->data;
            printf("%d", coeff);

            
            if (poly->degree > 0) {
                printf("x");
                if (poly->degree > 1) {
                    printf("^%d", poly->degree);
                }
            }
        }
        poly = poly->next;
    }
    printf("\n");
}

void free_poly(struct node *poly){
	if (poly != NULL){
		struct node *temp = poly;
		while(poly!=NULL){
			temp=poly;
			poly=poly->next;
			free(temp);
		}
	}
}
				



int main(){
	int choice ;
	do{
		printf("________polynomial-program__________\n");
		printf("1.enter polynomials (1)\n2.add polynomials (2)\n3.subtract polynomial (3)\n4.display (4)\n5.exit(0)\n");
		printf("enter option: ");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				system("cls");
				printf("\ncreate polynomial 1: ");
				poly1 = create_poly(poly1);
				printf("create polynomial 2: ");
				poly2 = create_poly(poly2);
				break;
			case 2:
				system("cls");
				poly3 = add_sub_poly(poly1,poly2,poly3,1);
				break;
			case 3:
				system("cls");
				poly3 = add_sub_poly(poly1,poly2,poly3,4);
				break;
			case 4:
				system("cls");
				printf("\npolynomial 1: \n");
				print_poly(poly1);
				printf("\npolynomial 2: \n");
				print_poly(poly2);
				printf("\npolynomial 3: \n");
				print_poly(poly3);
				break ;
			case 0:
				system("cls");
				printf("exiting programme....");
				free_poly(poly1);
				free_poly(poly2);
				free_poly(poly3);
				printf("exiting successfully");
				break;
			default:
				printf("invalid choice. try again...");
		}
	}
	while(choice != 0);
	return 0;
}


