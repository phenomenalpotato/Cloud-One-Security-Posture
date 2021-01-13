#include <stdio.h>
#include <stdlib.h>
#include "cc.cpp"
#include "sm.cpp"
#include "ds.cpp"


// Fazer com que o user possa passar mais de um argumento e fazer com isso, consiga executar mais funções do que de uma vez!! 

int main(int argc, char *argv[]) {

    char *api = getenv("api");

    char *url_l = getenv("url_l");

    char *url_c = getenv("url_c");

    char *url_e = getenv("url_e");

    if(api == NULL || url_l == NULL || url_c == NULL || url_e == NULL) {

        perror("ERROR: Variables not found!!");

    }
   
    switch (*argv[1]) {
   
    case 'l':

        cc_get_accounts(api, url_l);

    break;

    case 'c':

        cc_all_accounts_checks(api, url_c);

    break;

    case 'e':

        cc_list_all_events(api, url_e);

    break;
    
    }

    return 0;
}