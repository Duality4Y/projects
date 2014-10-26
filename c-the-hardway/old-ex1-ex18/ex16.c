#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//define a structure Person
struct Person
{
	char *name; //this structure has members for a name (string)
	int age; //for a age (int)
	int height; //for a height (int)
	int weight; //for a weight (int)
};

//this function creates a Person.
//and returns a pointer to this Person structure.
struct Person *Person_create(char *name, int age, int height, int weight)
{
	//create some space for it.
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);//check whether we got that space else abort.
	
	//assign the values to it's member functions.
	who->name = strdup(name);//copy the string name into who->name
	who->age = age;
	who->height = height;
	who->weight = weight;
	
	return who;
}
//function that free's memory where the structure was.
void Person_destroy(struct Person *who)
{
	assert(who != NULL);//check whether there anything to be freed. else abort.
	
	free(who->name); //free the string. thus strdup uses malloc.
	free(who);//and free the structure it self.
}

//print all the member variables in who structure.
void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);
	
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);
	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);
	
	//make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);
	
	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);
	
	//clean up
	Person_destroy(joe);
	Person_destroy(frank);
	
	return 0;
}
