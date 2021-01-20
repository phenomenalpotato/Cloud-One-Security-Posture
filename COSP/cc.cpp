#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <fstream> // Necessary to read and write files

int cc_get_accounts(char *api, std::string url_l) { // This function allows you to query all accounts that you have access to and see their Account ID.

    CURL *curl;

    CURLcode res;

    const char *url = url_l.c_str(); // The string Class provides a method called c_str() that returns a pointer to a char constant.

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();

    FILE *file = fopen("C1SPM.json", "w"); // Will open the C1SPM.json file

    if(file) {

      if(curl) {

        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1); // Mudei Aqui!!!!!

        curl_easy_setopt(curl, CURLOPT_URL, url);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file); // Will write the HTTP response in the file


        #if defined(DEBUG)
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1l); // If a the MACRO DEBUG is defined, CURL will run VERBOSE 
        #endif

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // First thing to do when your libcurl program does not perform the way you want
                                                          // It will give with a better explanation about error or even if it is successful
                                                          // The program will run more verbose
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;

        headers = curl_slist_append(headers, api);
        headers = curl_slist_append(headers, "Content-Type: application/vnd.api+json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl); // Will execute the transfer block and return a CURLcode. If everthing went OK will return CURLE_OK

        }
        
      fclose(file);

    }

    curl_easy_cleanup(curl);

    curl_global_cleanup();  /* curl_global_cleanup() should be invoked exactly once for each application <---------------------------- Quando terminar mover para a ultima função chamada
                               that uses libcurl */
    return (int)res;

}



int cc_all_accounts_checks(char *api, std::string url_c) { // This function will bring from one account that you have access to, checks that are only FAILURE AND SECURITY related.

  CURL *curl_checks;

  CURLcode res;

  curl_checks = curl_easy_init();

  const char *url = url_c.c_str();

  FILE *file = fopen("C1SPM.json", "w");

  if(file) {

    if(curl_checks) {

        curl_easy_setopt(curl_checks, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl_checks, CURLOPT_URL, url);

        curl_easy_setopt(curl_checks, CURLOPT_WRITEDATA, file);
        
        #if defined(DEBUG)
        curl_easy_setopt(curl_checks, CURLOPT_VERBOSE, 1l);
        #endif

        curl_easy_setopt(curl_checks, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl_checks, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, api);
        headers = curl_slist_append(headers, "Content-Type: application/vnd.api+json");
        curl_easy_setopt(curl_checks, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl_checks);

    }

    fclose(file);

  }

  curl_easy_cleanup(curl_checks);

  return (int)res;
}


int cc_list_all_events(char *api, std::string url_e) { // Vai ter que fazer paginação

  CURL *curl_events;

  CURLcode res;

  curl_events = curl_easy_init();

  const char *url = url_e.c_str();

  FILE *file = fopen("C1SPM.json", "w");

  if(file) { 

    if(curl_events) {

        curl_easy_setopt(curl_events, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl_events, CURLOPT_URL, url);

        curl_easy_setopt(curl_events, CURLOPT_WRITEDATA, file);

        #if defined(DEBUG)
        curl_easy_setopt(curl_events, CURLOPT_VERBOSE, 1l);
        #endif

        curl_easy_setopt(curl_events, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl_events, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, api);
        headers = curl_slist_append(headers, "Content-Type: application/vnd.api+json");
        curl_easy_setopt(curl_events, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl_events);

    }

    fclose(file);

  }

  curl_easy_cleanup(curl_events);

  return (int)res;
}

int cc_scan_account(char *api, std::string url_s) {

CURL *curl_scan;

CURLcode res;

curl_scan = curl_easy_init();

const char *url = url_s.c_str();

if(curl_scan) {

    curl_easy_setopt(curl_scan, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(curl_scan, CURLOPT_URL, url);

    curl_easy_setopt(curl_scan, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl_scan, CURLOPT_DEFAULT_PROTOCOL, "https");
    struct curl_slist *headers = NULL;


    headers = curl_slist_append(headers, "Authorization: ApiKey 448BRzg8pHZLY5WWCqdsAVVGDnjZQwXoDMWMgShTtySpNnosGDJZ5fsCQc9HXXgE");
    headers = curl_slist_append(headers, "Content-Type: application/vnd.api+json");
    curl_easy_setopt(curl_scan, CURLOPT_HTTPHEADER, headers);
    res = curl_easy_perform(curl_scan);

  }

  curl_easy_cleanup(curl_scan);
  return (int)res;

}

/*



*/