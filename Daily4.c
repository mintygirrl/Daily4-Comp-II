#include <stdio.h>

/***********************************************************
Author: Fallon Weiss
Date: 1/26/24
Effort: 45 minutes
Purpose: Exploring more with the left and right shift bitwise operators 
through the use of setting certain bits as 1s or 0s and checking
them, as well as unsetting them to revert to what they were before.
***********************************************************/

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int* flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[])
{
    unsigned int flag_holder = 0;

    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);
    
    display_32_flags(flag_holder);

    unset_flag(&flag_holder, 31);
    unset_flag(&flag_holder, 3);
    set_flag(&flag_holder, 9);

    display_32_flags(flag_holder);
    return 0;
}


void set_flag(unsigned int* flag_holder, int flag_position)
{
    //
    int compare = 1 << flag_position;
    *flag_holder = *flag_holder | compare;
}

void unset_flag(unsigned int* flag_holder, int flag_position)
{
    int compare = 1 << flag_position;
    compare = ~compare;
    *flag_holder = *flag_holder & compare;
}

int check_flag(unsigned int flag_holder, int flag_position)
{
    int versus = flag_holder >> flag_position;
    int compare = 1 & versus;
    return compare;
}

void display_32_flags(unsigned int flag_holder)
{
    int i;
    for(i=31; i>=0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        if(i%4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}