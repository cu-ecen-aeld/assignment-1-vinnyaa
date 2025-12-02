#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

/**
* This function should:
*   1) Call the my_username() function in autotest-validate.c to get your hard coded username.
*   2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h within
*       the assignment autotest submodule at assignment-autotest/test/assignment1/
*   3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE to verify the two strings are equal.  See
*       the [unity assertion reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
*/
void test_validate_my_username()
{
    /**
     * TODO: Replace the line below with your code here as described above to verify your /conf/username.txt 
     * config file and my_username() functions are setup properly
     */
    // get string from my_username()
    // char* my_username_value;
    const char *my_username_value = my_username();

    // get string from malloc_username_from_config_file()
    char* my_username_from_malloc;
    my_username_from_malloc = malloc_username_from_conf_file();

    // changed the below to the three argument variety assert comparing the first two arguments
    // if the assert fails, the third argument will be printed
    TEST_ASSERT_EQUAL_STRING_MESSAGE(my_username_value, my_username_from_malloc, "Usernames in conf text file and my_username() do not match");

    // as per the definition of malloc_username_from_conf_file(), I must free the memory location
    free(my_username_from_malloc);

}
