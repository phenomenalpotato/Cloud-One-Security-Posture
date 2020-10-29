#include <stdio.h>
#include <curl/curl.h>

void cc(void) {

    CURL *curl;

    CURLcode res;

    char error[CURL_ERROR_SIZE]; // Size of the buffer

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();

    if(curl) {


        curl_easy_setopt(curl, CURLOPT_URL, "https://eu-west-1-api.cloudconformity.com/v1");

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); // First thing to do when your libcurl program does not perform the way you want
                                                    // It will give with a better explanation about error or even if it is successful
                                                   // The program will run more verbose

        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error); // Error Buffer. With this, i could give more message to an error or if something goes wrong

        curl_easy_setopt(curl, CURLOPT_HEADER, 1L); // Basicaly tells the libcurl to include the response header in the data 

        // Perform the request, res will get the return code

        res = curl_easy_perform(curl);

        // Check for errors 

            if(res != CURLE_OK) {

                fprintf(stderr, "curl_easy_perform() failed: %s ==> %s\n", curl_easy_strerror(res), error); // Giving more information about the error with 
                                                                                                           // the error buffer
                
            }

        curl_easy_cleanup(curl);

    }

    curl_global_cleanup();

}



/*

int main(int argc, char *argv[]){
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(curl, CURLOPT_URL, "https://us-west-2-api.cloudconformity.com/v1/accounts");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Authorization: ApiKey 4i3TZk5j1MXcAusmRuPdz95cLGa47Er9RM5dCrs66Nfzajb57nP54d6BwCisvuvV");
    headers = curl_slist_append(headers, "Content-Type: application/vnd.api+json");
    headers = curl_slist_append(headers, "Cookie: AWSALB=WHErSfu3iU08KSLo/zzYgDmLy0QSNQhWLD1r8fqvJazKKDEEVJh+4WJr8wDCj64LvrGuRwaTujBK6fXyX2b15AGU1duCS6YPndMNh4ULbjzyxz88strWa+DtrflJ; AWSALBCORS=WHErSfu3iU08KSLo/zzYgDmLy0QSNQhWLD1r8fqvJazKKDEEVJh+4WJr8wDCj64LvrGuRwaTujBK6fXyX2b15AGU1duCS6YPndMNh4ULbjzyxz88strWa+DtrflJ");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    res = curl_easy_perform(curl);
  }
  curl_easy_cleanup(curl);
  return (int)res;
}

*/