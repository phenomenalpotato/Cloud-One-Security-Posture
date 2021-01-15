#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <iostream> // Necessary to read and write files
#include <nlohmann/json.hpp>
#include <fstream> // Necessary to read and write files
#include <iomanip> // Necessary to use std::setw()

#define PONTO puts("==============--------------------===========================---------------------");

using json = nlohmann::json;

void readJson(void) {

    PONTO

    std::ifstream ifs; // Data type represents the input stream and is used to read information from files. ifstream is usead
    // to open a file for reading purpose reading purpose only

    ifs.open("teste.json", std::ios::in);

    if (ifs.is_open()) {

      json parsed_json = json::parse(ifs);

      std::cout << std::setw(4) << parsed_json << "\n\n"; 

      ifs.close();

    }

    else {

      puts("Something went wrong while opening the file! Try to check if the file exist or/ and is the correct path");
    }

}

int cc_get_accounts(const char *api, std::string url_l) { // This function allows you to query all accounts that you have access to and see their Account ID.

    CURL *curl;

    CURLcode res;

    const char *url = url_l.c_str(); // The string Class provides a method called c_str() that returns a pointer to a char constant.

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();

    FILE *file = fopen("teste.json", "w");
    
    if(file) {

      if(curl) {

        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1); // Mudei Aqui!!!!!

        curl_easy_setopt(curl, CURLOPT_URL, url);

        // curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writecallback); // Comentar aqui caso queira que o texto apareça Aqui!!!!

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

        fclose(file);

      }
    
    curl_easy_cleanup(curl);

    curl_global_cleanup();  /* curl_global_cleanup() should be invoked exactly once for each application <---------------------------- Quando terminar mover para a ultima função chamada
                               that uses libcurl */
    return (int)res;

  }

  else {

      puts("Something went wrong while opening the file! Try to check if the file exist or/ and is the correct path");   
  }

}

// template<class UnaryFunction>
// void recursive_iterate(const json& j, UnaryFunction f) {

//   for(auto it = j.begin(); it != j.end(); ++it) {

//     if(it->is_structured()) {

//       recursive_iterate(*it, f);

//     }

//     else {

//       f(it);
//     }

//   }

// }

bool Comp(std::string valor1, std::string valor2) {

  return valor1.compare(valor2);

}

void findJson(std::string attribute) {

  PONTO

  std::ifstream ifs; 

  ifs.open("teste.json", std::ios::in);

  if (ifs.is_open()) {

      json parsed_json = json::parse(ifs);

      for(auto el : parsed_json["data"].items()) {

        if(Comp(attribute, "attributes") == 0) { // Will show only the attribute field from the Json

          std::cout << std::setw(3) << el.key() << ": " << std::setw(4) << el.value()["attributes"] << '\n';  // What fields will the user search
          // break;

        }

        if(Comp(attribute, "id") == 0) { // Will show only the id field from the Json

          std::cout << std::setw(3) << el.key() << ": " << std::setw(4) << el.value()["id"] << '\n'; // What fields will the user search

        }

        if(Comp(attribute, "relationships") == 0) { // Will show only the relationships field from the Json

          std::cout << std::setw(3) << el.key() << ": " << std::setw(4) << el.value()["relationships"] << '\n'; // What fields will the user search

        }

        PONTO

      }

      // std::cout << std::setw(4) << parsed_json << "\n\n"; 

      // recursive_iterate(parsed_json, [](json::const_iterator it){

      //   std::cout << *it << std::endl;
        
      // });

      // std::cout << "Valor na key data" << *resultado << '\n';

    //   for(auto&x : parsed_json.items()) {

    //     std::cout << "key: " << x.key() << ", value: " << x.value() << '\n';

    // }

      ifs.close();

    }

    else {

      puts("Something went wrong while opening the file! Try to check if the file exist or/ and is the correct path");
    }

}

int main(void) {

  // std::string url_l = "https://us-west-2-api.cloudconformity.com";
  // const char *api = "ApiKey 448BRzg8pHZLY5WWCqdsAVVGDnjZQwXoDMWMgShTtySpNnosGDJZ5fsCQc9HXXgE";

  printf("What do you want to:\n" 
                          "1 - Search through the JSON file\n"
                          "2 - Read the whole file and print it in the terminal\n"
                          "3 - Check the product and Write the information in the C1SPM.json file\n\n");

  int decision = 0;

  printf("Option: ");

  scanf("%d", &decision);

  printf("\n");

  if(decision == 1) {
    
    std::string field; 

    std::cin.ignore();

    puts("Do you want the attributes field, or id, or relationships: ");
    getline(std::cin, field);

    findJson(field);

  }

  else if(decision == 2) {

    readJson();
  }

  else if(decision == 3) {

    std::cin.ignore(); // Ignores \n or the previous input that was left 

    char *api = getenv("api"); // Will get the api variable from the system

    std::string url;

    printf("Qual a sua URL: ");

    getline(std::cin, url);

    std::string url_l = url + std::string("/v1/accounts"); // Will concatenate the variable url at the end with /v1/accounts 

    std::cout << url_l << std::endl;

    cc_get_accounts(api, url_l);

  }

  else {

    exit(1);
  }

  return 0;

}