#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2000
#define D 250

// A simple restaurant structure
typedef struct
{
    char restaurant_name[15];
    double rating;
    char city[31];
    unsigned short opening_year;
} RESTAURANT_t, *RESTAURANT;

// Arraylist structure
typedef struct ArrayList_s
{
    void **list;
    int size;
    int capacity;
    int delta_capacity;
} ArrayList_t, *ArrayList;

// Creates an arraylist and returns it
ArrayList arraylist_create(int capacity, int delta_capacity)
{
    ArrayList l;
    l = (ArrayList)malloc(sizeof(ArrayList_t));
    if (l != NULL)
    {
        l->list = (void **)malloc(capacity * sizeof(void *));
        if (l->list != NULL)
        {
            l->size = 0;
            l->capacity = capacity;
            l->delta_capacity = delta_capacity;
        }
        else
        {
            free(l);
            l = NULL;
        }
    }
    return l;
}

// Frees the arraylist and its elements
void arraylist_destroy(ArrayList l)
{
    int i;
    for (i = 0; i < l->size; ++i)
    {
        free(l->list[i]);
    }
    free(l->list);
    free(l);
}

// Returns 1 if the arraylist is empty and 0 otherwise
char arraylist_isempty(ArrayList l)
{
    return l->size == 0;
}

// Returns 1 if the arraylist is full and 0 otherwise
char arraylist_isfull(ArrayList l)
{
    return l->size == l->capacity;
}

// Sets the element at index with given e and puts the older element in replaced parameter
int arraylist_set(ArrayList l, void *e, int index, void **replaced)
{
    if (index >= 0 && index < l->size)
    {
        if (replaced != NULL)
        {
            *replaced = l->list[index];
        }
        l->list[index] = e;
    }
    else if (!arraylist_isfull(l))
    {
        index = l->size;
        l->size = l->size + 1;
        l->list[index] = e;
    }
    else
    {
        index = -1;
    }
    return index;
}

// Inserts the parameter e to the index of the arraylist
int arraylist_insert(ArrayList l, void *e, int index)
{
    void **nlist;
    int ncapacity;
    if (index >= 0 && index <= l->size)
    {
        if (arraylist_isfull(l))
        {
            ncapacity = l->capacity + l->delta_capacity;
            nlist = realloc(l->list, ncapacity * sizeof(void *));
            if (nlist != NULL)
            {
                // Shifts elements between index and l->size-1 to right by 1
                memmove(&nlist[index] + 1, &nlist[index], (l->size - index) * sizeof(void *));

                l->list = nlist;
                l->capacity = ncapacity;
                l->size++;
                l->list[index] = e;
            }
            else
            {
                nlist = (void **)malloc(ncapacity * sizeof(void *));
                if (nlist != NULL)
                {
                    // Copies elements while shifting elements between index and l->size-1 to right by 1
                    memcpy(nlist, l->list, index * sizeof(void *));
                    memcpy(&nlist[index] + 1, &l->list[index], (l->size - index) * sizeof(void *));
                    free(l->list);

                    l->list = nlist;
                    l->capacity = ncapacity;
                    l->size++;
                    l->list[index] = e;
                }
                else
                {
                    index = -index;
                }
            }
        }
        else
        {
            // Shifts elements between index and l->size - 1 to right by 1
            memmove(&l->list[index] + 1, &l->list[index], (l->size - index) * sizeof(void *));

            l->size++;
            l->list[index] = e;
        }
    }
    else
    {
        index = -index;
    }
    return index;
}

// Deletes the element at index of the arraylist
void *arraylist_delete(ArrayList l, int index)
{
    void *e;
    int ncapacity;
    void **nlist;
    e = NULL;
    if (!arraylist_isempty(l) && index >= 0 && index < l->size)
    {
        e = l->list[index];
        l->size--;
        memmove(&l->list[index], &l->list[index] + 1, (l->size - index) * sizeof(void *));
        ncapacity = l->capacity / 2;
        if (l->size <= ncapacity && ncapacity > 0)
        {
            nlist = realloc(l->list, ncapacity * sizeof(void *));
            if (nlist != NULL)
            {
                l->list = nlist;
                l->capacity = ncapacity;
            }
            else
            {
                nlist = (void **)malloc(ncapacity * sizeof(void *));
                if (nlist != NULL)
                {
                    memcpy(nlist, l->list, l->size * sizeof(void *));
                    free(l->list);
                    l->list = nlist;
                    l->capacity = ncapacity;
                }
            }
        }
    }
    return e;
}

// Writes all void * elements of the arraylist to the file (generic fprintf)
void arraylist_fprint(ArrayList l, FILE *fp, void (*fprint)(void *, FILE *))
{
    int i;
    for (i = 0; i < l->size; i++)
    {
        (*fprint)(l->list[i], fp);
    }
}

// Writes given restaurant to the file
void fprint_rest(void *e, FILE *fp)
{
    RESTAURANT ei;
    ei = (RESTAURANT)e;
    fprintf(fp, "%s\n", ei->restaurant_name);
    fprintf(fp, "%d\n", ei->opening_year);
}

// Frees the arraylist and all of its elements (generic destroy)
void arraylist_destroy_all(ArrayList l, void (*destroy)(void *))
{
    int i;
    if (destroy != NULL)
    {
        for (i = 0; i < l->size; i++)
        {
            (*destroy)(l->list[i]);
        }
    }
    free(l->list);
    free(l);
}

// Frees given restaurant
void destroy_rest(void *e)
{
    free(e);
}

// ****************************** ASSIGNMENT 3 ****************************** //

/*
	NOTE:
		@param - the description of the parameter
		@return - the description of what the function returns
*/

/**
 * Function: create_restaurant
 * ---------------------------
 * This function creates a restaurant with the given parameters.
 *
 * @param restaurant_name Name of the restaurant
 * @param rating Rating of the restaurant which is a rational number between
 *               0 and 10
 * @param city City of the restaurant
 * @param opening_year Opening year of the restaurant
 *
 * @return The created restaurant
 */
RESTAURANT create_restaurant(char *restaurant_name, double rating, char *city, unsigned short opening_year)
{
    // TODO: Fill this block.

    RESTAURANT r;
    strcpy(r->restaurant_name, restaurant_name);
    strcpy(r->city, city);
    r->rating = rating;
    r->opening_year = opening_year;

    return r;
}
/**
 * Function: search_restaurants
 * ----------------------------
 * This function finds the restaurants whose rating is between min_rate and max_rate,
 * places them in an array list, and returns the array list.
 *
 * @param l An array list of restaurants
 * @param min_rating Minimum rating value
 * @param max_rating Maximum rating value
 *
 * @return An array list of restaurants
 */
ArrayList search_restaurants(ArrayList l, double min_rating, double max_rating)
{
    // TODO: Fill this block.
    // while writing this code I was inspired by lab7
    ArrayList found = arraylist_create(l->capacity , l->delta_capacity);
    int i;
    for(i=0;i<l->size;i++)
    {
        if(((RESTAURANT)l->list[i])->rating >= min_rating || ((RESTAURANT)l->list[i])->rating <= max_rating )
        {
            RESTAURANT r = create_restaurant(((RESTAURANT)l->list[i])->restaurant_name, ((RESTAURANT)l->list[i])->rating, ((RESTAURANT)l->list[i])->city, ((RESTAURANT)l->list[i])->opening_year);
            arraylist_insert(found, (void*)r, found ->size);
        }
    }
    return found;
}
/**
 * Function: print_restaurant
 * --------------------------
 * This function prints the data of a restaurant.
 *
 * @param r A restaurant
 */
void print_restaurant(RESTAURANT r)
{
    // TODO: Fill this block.
    printf("\nName: %s\nCity: %s\nOpening Year: %d\nRating: %d\n", r->restaurant_name, r->city, r->opening_year, r->rating);
}

/**
 * Function: update_restaurants
 * ---------------------------
 * This function updates the ratings of the restaurants with the given
 * name in the array list.
 *
 * @param l An array list of restaurants
 * @param restaurant_name Name of the restaurants to be updated
 * @param rating New rating for the restaurants
 */
void update_restaurants(ArrayList l, char *restaurant_name, double rating)
{
    // TODO: Fill this block.
    int i;
    void *upd = NULL;
    RESTAURANT *r= (RESTAURANT *) (RESTAURANT) l->list;
    for (i = 0; i <= l->size; i++) {
        if (strcmp(r[i]->restaurant_name, restaurant_name) == 0) {
            RESTAURANT res = create_restaurant(r[i]->restaurant_name, rating, r[i]->city, r[i]->opening_year);
            arraylist_set(l, (void * ) res, i, upd);
        };
    }
}


/**
 * Function: delete_restaurants
 * ---------------------------
 * This function deletes the restaurants with the given
 * name in the arraylist.
 *
 * @param l An array list of restaurants
 * @param restaurant_name Name of the restaurants to be deleted
 */
void delete_restaurants(ArrayList l, char *restaurant_name)
{
    // TODO: Fill this block.
    int i;
    int j;

    for(i=0;i<N;i++)
    {
        if(strcmp(restaurant_name,rest[i]->restaurant_name)==0)
            rest[i]=j;

    }
    strcpy(rest[j]->restaurant_name,"");
    strcpy(rest[j]->city,"");
    rest[j]->rating=0;
    rest[j]->opening_year=0;
}
/**
 * Function: compare_restaurants_ascending
 * -------------------------
 * This function compares given restaurants with respect to first
 * their ratings and then their names. It returns
 * 	- 1, if rest1 > rest2
 * 	- -1, if rest1 < rest2
 * 	- 0, if rest1 = rest2
 *
 * @param rest1 First restaurant
 * @param rest2 Second restaurant
 */
int compare_restaurants_ascending(void *rest1, void *rest2)
{
    // TODO: Fill this block.
    int a;
    a=strcmp(rest1,rest2);
    if(a>0)
        return 1;  //1, if rest1 > rest2
    else if(a<0)
        return -1;  //-1, if rest1 < rest2
    else
        return 0;  //0, if rest1 = rest2
}
/**
 * Function: compare_restaurants_descending
 * -------------------------
 * This function compares given restaurants with respect to first
 * their ratings and then their names. It returns
 * 	- 1, if rest1 < rest2
 * 	- -1, if rest1 > rest2
 * 	- 0, if rest1 = rest2
 *
 * @param rest1 First restaurant
 * @param rest2 Second restaurant
 */
int compare_restaurants_descending(void *rest1, void *rest2)
{
    // TODO: Fill this block.
    int a;
    a=strcmp(rest1,rest2);
    if(a>0)
        return 1;  //1, if rest1 < rest2
    else if(a<0)
        return -1;  //-1, if rest1 > rest2
    else
        return 0;  //0, if rest1 = rest2
}

/**
 * Function: arraylist_sort
 * -------------------------
 * This generic function sorts an array list using the given compare
 * function.
 *
 * @param l An array list
 * @param compare Pointer to the function which compares two elements
 */
void swap(int *q, int *p){
    int temp=*p;
    *p=*q;
    *q=temp;
}
void arraylist_sort(ArrayList l, int (*compare)(void *, void *))
{
    // TODO: Fill this block.
    int i,j;
    for(i=0;i<N-1;i++){
        for(j=0;j<N;j++)
        {
            if(strcmp(rest[i]->restaurant_name , rest[j]->restaurant_name)>0)
            {
                swap (rest[i],rest[j]);
            }
        }
    }
    // NOTE: If you cannot write down a generic function which works for all
    //       types, write down a function which sorts resturants. If you
    //       cannot use function pointers, you can write down multiple functions
    //       which sort using different criteria.
}

/**
 * Function: arraylist_remove_duplicates
 * --------------------------
 * This generic function deletes the duplicate elements in the array list
 * using the given compare function.
 *
 * @param l An array list
 * @param compare Pointer to the function which compares two elements
 */
void arraylist_remove_duplicates(ArrayList l, int (*compare)(void *, void *))
{
    // TODO: Fill this block.
    int i,j;
    RESTAURANT *res = (RESTAURANT)l->list;
    for(i=0;i<=l->size;i++)
    {
        for(j=i+1;j<=l->size;i++)
        {
            if(strcmp(res[i],res[j])==0)
            {
                RESTAURANT r= create_restaurant(res[i]->restaurant_name, res[i]->city, res[i]->rating, res[i]->opening_year);
            }
        }
    }

    // NOTE: If you cannot write down a generic function which works for all
    //       types, write down a function which removes duplicate restaurants.
}

// ********************************** MAIN ********************************** //

int main()
{
    // **********************************************************************
    // Creates an arraylist with the restaurants read from a file.
    // DO NOT EDIT THIS PART !!!
    int i;

    FILE *fi = fopen("restdata_assignment3.txt", "rb");
    if (fi == NULL)
    {
        printf("Cannot open the file.\n");
        exit(0);
    }
    RESTAURANT *rest = (RESTAURANT *)malloc(sizeof(RESTAURANT) * 1000);
    for (i = 0; i < N; ++i)
    {
        RESTAURANT tmp = (RESTAURANT)malloc(sizeof(RESTAURANT_t));
        fread(tmp, sizeof(RESTAURANT_t), 1, fi);
        rest[i] = tmp;
    }
    fclose(fi);

    ArrayList l = arraylist_create(N, D);
    for (i = 0; i < 1000; ++i)
    {
        arraylist_insert(l, rest[i], i);
    }
    // **********************************************************************
    print_restaurant(*rest);
    // **********************************************************************
    // TEST YOUR FUNCTIONS HERE !!!
    /*

        Test Procedure:
            1. Create 3 new restaurants
            2. Insert the restaurants to the array list to any index you desire
            3. Update the rating of the restaurants with the name "Woods"
            to any rating
            4. Remove the duplicates in the array list
            5. Search and get the restaurants with rating in a range that you
            specified
            6. Print the restaurants that you found in step 5
            7. Delete the restaurant with the name "Henderson"
            8. Sort the restaurants according to the ratings and restaurant names
            respectively, in any order (you need to choose ascending or descending order)
                - Example in ascending order
                    7.9 Daba			7.8 Yaba
                    8.0 Faba	=>		7.9 Caba
                    7.8 Yaba			7.9 Daba
                    7.9 Caba			8.0 Faba
            9. Print the sorted array list
    */
    // **********************************************************************

    // **********************************************************************
    // Destroys the arraylist.
    // DO NOT EDIT THIS PART !!!
    for (i = 0; i < N; ++i)
    {
        free(rest[i]);
    }
    free(rest);
    arraylist_destroy_all(l, destroy_rest);

    // **********************************************************************

    return 0;
}
