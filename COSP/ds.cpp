#include <iostream>
#include <curl/curl.h>

int ds_computers(char *api, std::string url_c) {

CURL *curl_computers;

CURLcode res;

const char *url = url_c.c_str(); // The string Class provides a method called c_str() that returns a pointer to a char constant.

curl_global_init(CURL_GLOBAL_ALL);

curl_computers = curl_easy_init();

FILE *file = fopen("C1SPM.json", "w"); // Will open the C1SPM.json file

if(file) {

    if(curl_computers) {

        curl_easy_setopt(curl_computers, CURLOPT_HTTPGET, 1);

        curl_easy_setopt(curl_computers,CURLOPT_URL, url);

        curl_easy_setopt(curl_computers,CURLOPT_WRITEDATA, file);

        #if defined(DEBUG) 
        curl_easy_setopt(curl_computers,CURLOPT_VERBOSE, 1);
        #endif

        curl_easy_setopt(curl_computers, CURLOPT_FOLLOWLOCATION, 1L);

        curl_easy_setopt(curl_computers, CURLOPT_DEFAULT_PROTOCOL, "https");

        struct curl_slist *headers = NULL;

        headers = curl_slist_append(headers, api);
        headers = curl_slist_append(headers, "api-version: v1"); 

        curl_easy_setopt(curl_computers, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl_computers); // Will execute the transfer block and return a CURLcode. If everthing went OK will return CURLE_OK


    }

    fclose(file);
}

    curl_easy_cleanup(curl_computers);

    curl_global_cleanup();  /* curl_global_cleanup() should be invoked exactly once for each application <---------------------------- Quando terminar mover para a ultima função chamada
                            that uses libcurl */

    return int(res);

}



// int cc_get_accounts(char *api, std::string url_l) { // This function allows you to query all accounts that you have access to and see their Account ID.

//     CURL *curl;

//     CURLcode res;

//     const char *url = url_l.c_str(); // The string Class provides a method called c_str() that returns a pointer to a char constant.

//     curl_global_init(CURL_GLOBAL_ALL);

//     curl = curl_easy_init();

//     FILE *file = fopen("C1SPM.json", "w"); // Will open the C1SPM.json file

//     if(file) {

//       if(curl) {

//         curl_easy_setopt(curl, CURLOPT_HTTPGET, 1); // Mudei Aqui!!!!!

//         curl_easy_setopt(curl, CURLOPT_URL, url);

//         curl_easy_setopt(curl, CURLOPT_WRITEDATA, file); // Will write the HTTP response in the file


//         #if defined(DEBUG)
//         curl_easy_setopt(curl, CURLOPT_VERBOSE, 1l); // If a the MACRO DEBUG is defined, CURL will run VERBOSE 
//         #endif

//         curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // First thing to do when your libcurl program does not perform the way you want
//                                                           // It will give with a better explanation about error or even if it is successful
//                                                           // The program will run more verbose
//         curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
//         struct curl_slist *headers = NULL;

//         headers = curl_slist_append(headers, api);
//         headers = curl_slist_append(headers, "Content-Type: application/vnd.api+json");
//         curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
//         res = curl_easy_perform(curl); // Will execute the transfer block and return a CURLcode. If everthing went OK will return CURLE_OK

//         }
        
//       fclose(file);

//     }

//     curl_easy_cleanup(curl);

//     curl_global_cleanup();  /* curl_global_cleanup() should be invoked exactly once for each application <---------------------------- Quando terminar mover para a ultima função chamada
//                                that uses libcurl */
//     return (int)res;

// }