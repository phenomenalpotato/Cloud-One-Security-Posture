#include <stdio.h>
#include <stdlib.h>
#include "cc.h"
#include "sm.h"
#include "ds.h"


// Fazer com que o usur possa passar mais de um argumento e fazer com isso, consiga executar mais funções do que de uma vez!! 

int main(int argc, char *argv[]) {

    char *api = getenv("api");

    char *url_l = getenv("url_l");

    char *url_c = getenv("url_c");

    if(api == NULL || url_l == NULL || url_c == NULL) {

        perror("ERROR: Variable not found!!");

    }
   
    switch (*argv[1]) {
   
    case 'l':

        cc_get_accounts(api, url_l);

    break;

    case 'c':

        cc_all_accounts_checks(api, url_c);

    break;
    
    }

    return 0;
}