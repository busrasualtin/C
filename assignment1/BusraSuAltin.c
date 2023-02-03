#include <stdio.h> // Do not edit these directives or add another.
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000 // Do not edit this macro.

typedef struct // Do not edit this struct.
{
    unsigned long restaurant_id;
    char restaurant_name[15];
    char description[127];
    double rate;
    char cuisine[31];
    unsigned short opening_year;
    unsigned long capacity;
    char city[31];
    char address[63];
    char owner[31];
} RECORD_t, *RECORD;

/* DECLARE YOUR FUNCTION PROTOTYPES HERE. */
void find_by_opening_year(unsigned short opening_year, RECORD *restaurant_array, unsigned long size, unsigned long start, unsigned long end, unsigned long *p_found_num, RECORD **p_found_restaurants);
RECORD find_by_restaurant_name(char *restaurant_name, RECORD *restaurant_array, unsigned long size, unsigned long start, unsigned long end);
unsigned long insert(RECORD restaurant, RECORD *restaurant_array, unsigned long *p_size);
RECORD delete (unsigned long restaurant_id, RECORD *restaurant_array, unsigned long *p_size);
void sort(RECORD restaurant_array, unsigned long size, double rate, char *restaurant_name);

int main()
{
    /* --- DO NOT EDIT THIS PART. --- */
    unsigned long num_records = MAX;
    unsigned long i;
    RECORD tmp;
    RECORD *rec = (RECORD *)malloc(sizeof(RECORD) * num_records);
    FILE *file = fopen("restdata.txt", "rb");
    if (file == NULL)
    {
        printf("Cannot open the file.\n");
        exit(0);
    }
    for (i = 0; i < num_records; i++)
    {
        tmp = (RECORD)malloc(sizeof(RECORD_t));
        fread(tmp, sizeof(RECORD_t), 1, file);
        rec[i] = tmp;
    }
    fclose(file);
    /* --- DO NOT EDIT THIS PART. --- */

    /**************************/
    /* Your code starts here. */
    /**************************/

    /*

        Call the functions that you implemented, 
        You can create a menu to demonstrate your functions.
        
    */

    /**************************/
    /* Your code ends here.   */
    /**************************/

    /* --- DO NOT EDIT THIS PART. --- */
    file = fopen("data_out.txt", "wb");
    for (i = 0; i < num_records; i++)
    {
        tmp = rec[i];
        fwrite(tmp, sizeof(RECORD_t), 1, file);
        free(tmp);
    }
    fclose(file);
    free(rec);
    return 1;
    /* --- DO NOT EDIT THIS PART. --- */
}

/* IMPLEMENT YOUR FUNCTIONS HERE */
void find_by_opening_year(unsigned short opening_year, RECORD *restaurant_array, unsigned long size, unsigned long start, unsigned long end, unsigned long *p_found_num, RECORD **p_found_restaurants)
{
    /*
    num <- find the number of RECORDs with given release_year between start and end in restaurant_array
    restaurants <- NULL
    if num != 0 then
        restaurants <- allocate an array of RECORDs of size num
        put the RECORDs with given opening_year between start and end in restaurant_array into restaurants
    endif
    *p_found_num <- num // return the number of RECORDs via pointer parameter
    *p_found_restaurants <- restaurants // return the array of found RECORDS via pointer parameter
    */

    int num = 0;
    for (unsigned long i = start; i <= end; i++)
    {
        if (restaurant_array[i]->opening_year == opening_year)
        {
            *p_found_restaurants[num];
            num++;
        }
    }

    *p_found_num = num;
}

RECORD find_by_restaurant_name(char *restaurant_name, RECORD *restaurant_array, unsigned long size, unsigned long start, unsigned long end)
{
    /*
    p_found <- NULL
    p_found <- find the RECORD with given restaurant_name in restaurant_array between start and end (p_found does not change if no such RECORD is found)
    return p_found
    */

    RECORD p_found = NULL;
    for (unsigned long i = start; i < end; i++)
    {
        if (strcmp(restaurant_array[i]->restaurant_name, restaurant_name) == 0)
        {
            p_found = restaurant_array[i];
            break;
        }
    }

    return p_found;
}

unsigned long insert(RECORD restaurant, RECORD *restaurant_array, unsigned long *p_size)
{
    /*
    index <- find the first location which contains NULL in restaurant_array
    if index is valid then
        *p_restaurant_array[index] <- restaurant
    else
        new_restaurants_array <- extends *p_restaurant_array by 1 to insert to the end
        if extension is successful then
            index <- *p_size
            new_restaurants_array[index] <- restaurant
            *p_restaurant_array <- new_restaurants_array // return the new array via pointer parameter
            *p_size <- *p_size + 1 // return the new size via pointer parameter
        else
            index <- -(*p_size)
        endif
    endif
    return index
    */
    int index;
    for (int i = 0; i < *p_size; i++)
    {
        if (restaurant_array[i] == NULL)
        {
            index = i;
            break;
        }
    }

    restaurant_array[index] = restaurant;
    return index;
}

RECORD delete (unsigned long restaurant_id, RECORD *restaurant_array, unsigned long *p_size)
{
    /*	
    index <- find the index of the RECORD with given restaurant_id in restaurant_array
    if index is valid then
        rec <- restaurant_array[index]
    else
        rec <- NULL
    endif
    return rec
    */

    int index;
    for (int i = 0; i < *p_size; i++)
    {
        if (restaurant_array[i]->restaurant_id == restaurant_id)
        {
            restaurant_array[i] = NULL;
            index = i;
            break;
        }
    }

    return index;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(RECORD restaurant_array, unsigned long size, double rate, char *restaurant_name)
{
    // This sort function must sort by rate. If rates are the same, the function must
    // sort by restaurant_name alphabetically.
    /*
    x <- end + 1
    while x != start do
        high <- start
        for i <- start, i <= x - 2, i <- i + 1 do
            if compare(restaurant_array[i], restaurant_array[i + 1]) > 0 then
                swap(&restaurant_array[i], &restaurant_array[i + 1])
                high <- i + 1
            endif
        endfor
        x <- high
    endwhile
    */

    RECORD t = NULL;
    int x, y;
    for (x = 0; x < (size - 1); x++)
    {
        for (y = 0; y < size - x - 1; y++)
        {
            if (restaurant_array[y].rate > restaurant_array[y + 1].rate)
            {
                t = &restaurant_array[y];
                restaurant_array[y] = restaurant_array[y + 1];
                restaurant_array[y + 1] = *t;
            } else if(restaurant_array[y].rate == restaurant_array[y].rate){
                if(strcmp(restaurant_array[y].restaurant_name, restaurant_array[y + 1].restaurant_name) == 1){
                    t = &restaurant_array[y];
                    restaurant_array[y] = restaurant_array[y + 1];
                    restaurant_array[y + 1] = *t;
                }
            }
        }
    }
}
