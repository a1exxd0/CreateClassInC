#include <stdio.h>
#include <stdlib.h>

/**
 * \brief       Animal struct to simulate class usage
 * \attribute   name: name of the animal
 * \function    speak: function to print the name of the animal
*/
typedef struct Animal{

    /*Character array/string */
    char *name;
    int nameLength;

    /*Function pointer with identifier 'speak' and parameter Animal*     */
    void (*speak)(struct Animal*);
} Animal;

/**
 * \brief       Function to print the name of the animal
 * \param       animal: pointer to the animal struct
*/
void speak(struct Animal *animal){

    /*animal->name dereferences animal and gets name attribute 
    Same as (*animal).name but more readable. */
    printf("I am a %s\n", animal->name);
}


/**
 * \brief       Function to create an animal
 * \param       name: name of the animal
 * \return      pointer to the animal struct ALLOCATED ON HEAP
*/
Animal *createAnimal(char *name, int nameLength){

    /*Place in heap */
    Animal *animal = malloc(sizeof(Animal)); //consider this similar to the (new) keyword

    /*Set attribute by constructor */
    animal->name = name;

    /*Set attribute by constructor */
    animal->nameLength = nameLength;

    /*Set pointer to function reference */
    animal->speak = &speak;

    /*Return pointer to location in heap */
    return animal;
}

void destroyAnimal(Animal *animal){

    /*Free from memory */
    free(animal);
}

int main(){

    Animal *animal = createAnimal("Dog", 3);
    animal->speak(animal);
    destroyAnimal(animal);
    return 0;
}