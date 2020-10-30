#include <stdio.h>
#include <stdlib.h>
#include "cc.h"
#include "sm.h"
#include "ds.h"

int main(int argc, char *argv[]) {

    char *api = getenv("api");

    char *url = getenv("url");

    if(api == NULL || url == NULL) {

        perror("ERROR: Variable not found!!");

    }
   
    switch (*argv[1]) {
   
    case 'l':

        cc_get_accounts(api, url);

    break;
    
    }

    return 0;
}