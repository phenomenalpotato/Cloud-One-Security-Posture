#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

int cc_get_accounts(char *api, char *url) { // Will receive the URL and APIKey

    CURL *curl;

    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();

    if(curl) {

      curl_easy_setopt(curl, CURLOPT_HTTPGET, 1); // Mudei Aqui!!!!!

      curl_easy_setopt(curl, CURLOPT_URL, url);


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

    curl_easy_cleanup(curl);

    curl_global_cleanup();  /* curl_global_cleanup() should be invoked exactly once for each application <---------------------------- Quando terminar mover para a ultima função chamada
                               that uses libcurl */
    return (int)res;

}



int cc_all_accounts_checks(void) {

  CURL *curl_checks;

  CURLcode res;

  curl_checks = curl_easy_init();

  if(curl_checks) {



  }

  return (int)res;
}