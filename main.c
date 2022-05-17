#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct CoffeeNode {
    char OrderName[100];
    char CupSize[100];
    char CoffeeType[100];
    char CoffeeMilk[100];
    char Caffein[100];
    char Calories[100];
    struct CoffeeNode *next;
} Node;

Node *createNode(char OrderName[100],char CupSize[100],char CoffeeType[100],char CoffeeMilk[100],char Caffein[100],char Calories[100]) {
	
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->OrderName, OrderName);
    strcpy(newNode->CupSize, CupSize);
    strcpy(newNode->CoffeeType, CoffeeType);
    strcpy(newNode->CoffeeMilk, CoffeeMilk);
    strcpy(newNode->Caffein, Caffein);
    strcpy(newNode->Calories, Calories);

    newNode->next = NULL;
    return newNode;
}


void insert(Node **link, Node *newNode) {
    newNode->next = *link;
    *link = newNode;
}

void ShowCoffee(Node *head) {
	int pos=0;
	
    while (head != NULL) {
		pos++;
    	printf("\n==========",pos);
    	printf("Order No. %d \n",pos);
        printf("Name            	: %s \n", head->OrderName);
        printf("Size            	: %s \n", head->CupSize);
        printf("Type            	: %s \n", head->CoffeeType);
        printf("Milk            	: %s \n", head->CoffeeMilk);
        printf("Caffein            	: %s \n", head->Caffein);
        printf("Calories             : %s \n", head->Calories);
        printf("\n");
        head = head->next;
    }
	if(pos == 0){
		printf("\n There's no order yet");
	}
}

int main(void)
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *n;
 	int input = 5;
 	int retval = 0;

	
	while(input != 0) {
  		printf("FoaMy Caffe\n");
  		printf("=========\n");
  		printf("1: Insert Coffee Order\n");
  		printf("2: View Coffee Order\n");
  		printf("3: Exit\n");
  		printf("\>>: ");
  		scanf("%d", &input);
		if(input==3){
    		printf("Thanks for order!\n");
    		exit(0);
		}
	else if(input==1){
	 	
    	char _OrderName[100] = "";
    	char _CoffeeType[100]= "";
    	char _CupSize[100]= "";
    	char _CoffeeMilk[100]= "";
    	char _Caffein[100]= "";
    	char _Calories[100]= "";
	 	
    	while(strlen(_OrderName) < 3 || strlen(_OrderName) > 20)
		{
			printf("Input your name : ");
    		scanf("%s", &_OrderName);
		}
		
		while (strstr(_CupSize, "Tall") == NULL && strstr(_CupSize, "Grande") == NULL && strstr(_CupSize, "Venti") == NULL) {
    		printf("Input cup size [Tall | Grande | Venti] : ");
    		scanf("%s", &_CupSize);
		}	
		
		while (strstr(_CoffeeType, "Espresso") == NULL && strstr(_CoffeeType, "Cappuccino") == NULL && strstr(_CoffeeType, "Mocha") == NULL) {
    		printf("Input coffee type [Espresso | Cappuccino | Mocha]  : ");
    		scanf("%s", &_CoffeeType);
		}	
		
		while (strstr(_CoffeeMilk, "None") == NULL && strstr(_CoffeeMilk, "Skim") == NULL && strstr(_CoffeeMilk, "Cream") == NULL) {
    		printf("Input coffee milk [None | Skim | Cream]  : ");
    		scanf("%s", &_CoffeeMilk);
		}	

    	n = createNode(&_OrderName,&_CupSize,&_CoffeeType,_CoffeeMilk,"1","1");
    	insert(&head, n);
    	tail = n;
	}
	else if(input==2){
    	ShowCoffee(head);
	}
	
}
 return(0);
 
 
}

