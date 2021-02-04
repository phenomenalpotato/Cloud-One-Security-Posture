#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream> // Necessary to read and write files
#include <nlohmann/json.hpp> // Necessary to parse the JSON file
#include <iomanip> // Necessary to use std::setw()
#include "cc.cpp"
#include "sm.cpp"
#include "ds.cpp"

// Fazer um tipo de opção que permite o User de checar a conexão com a URL/ API do produto!! Ver se está resolvendo Nome, consegue chegar no produto etc

#define PONTO puts("==============--------------------===========================---------------------");


// Fazer com que o user possa passar mais de um argumento e fazer com isso, consiga executar mais funções do que de uma vez!! 

using json =  nlohmann::json;


void readJson(void) {

    PONTO

    std::ifstream ifs; // Data type represents the input stream and is used to read information from files. ifstream is usead
    // to open a file for reading purpose reading purpose only

    ifs.open("C1SPM.json", std::ios::in);

    if (ifs.is_open()) {

      json parsed_json = json::parse(ifs);

      std::cout << std::setw(4) << parsed_json << "\n\n"; 

      ifs.close();

    }

    else {

      puts("Something went wrong while opening the file! Try to check if the file exist or/ and is the correct path");
    }

}

bool Comp(std::string valor1, std::string valor2) {

  return valor1.compare(valor2);

}

void findJson(std::string attribute, short int decisionEndpointSearchJson) {

  PONTO

  std::ifstream ifs; 

  ifs.open("C1SPM.json", std::ios::in);

  if (ifs.is_open()) {

      json parsed_json = json::parse(ifs);

      if(decisionEndpointSearchJson == 1 || decisionEndpointSearchJson == 2 || decisionEndpointSearchJson == 3) {

        for(auto el : parsed_json["data"].items()) {

            if(Comp(attribute, "attributes") == 0) { // Will show only the attribute field from the Json

              std::cout << std::setw(3) << el.key() << ": " << std::setw(4) << el.value()["attributes"] << '\n'; // What fields will the user search
            
            }

            if(Comp(attribute, "id") == 0) { // Will show only the id field from the Json

              std::cout << std::setw(3) << el.key() << ": " << std::setw(4) << el.value()["id"] << '\n'; // What fields will the user search

            }

            if(Comp(attribute, "relationships") == 0) { // Will show only the relationships field from the Json

              std::cout << std::setw(3) << el.key() << ": " << std::setw(4) << el.value()["relationships"] << '\n'; // What fields will the user search

            }

            if(Comp(attribute, "rule") == 0) { // Will show only the rule field from the Json

              std::cout << std::setw(3) << el.key() << ": " << std::setw(4) << el.value()["relationships"]["rule"] << '\n';  // What fields will the user search

            }

            if(Comp(attribute, "type") == 0) { // Will show only the type field from the Json

              std::cout << std::setw(3) << el.key() << ": " << std::setw(4) << el.value()["type"] << '\n'; // What fields will the user search

            }

          PONTO

        }

      }

      if(decisionEndpointSearchJson == 4) {

          for(auto el : parsed_json["computers"].items()) {

            if(Comp(attribute, "y") == 0) { // Will show only the type field from the Json

              std::cout << std::setw(4) << el.key() << ": " << std::setw(4) << el.value()["hostName"] << ": " << std::setw(4) << el.value()["ID"] << 
              std::setw(4) << ": " << el.value()["displayName"] << std::setw(4) << ": " << el.value()["platform"] << 
              " Last IP Used: " << std::setw(4) << el.value()["lastIPUsed"] << '\n'; // What fields will the user search

              std::cout << "Tasks: " << std::setw(6) << el.value()["tasks"] << '\n'; 

              std::cout << "Computer Status: " << std::setw(6) << el.value()["computerStatus"] << "\n\n";

              std::cout << "Firewall Status: " << std::setw(6) << el.value()["firewall"] << "\n\n";

              std::cout << "Intrusion Prevention Status: " << std::setw(6) << el.value()["intrusionPrevention"] << "\n\n";

              std::cout << "Web Reputation Status: " << std::setw(6) << el.value()["webReputation"] << "\n\n";

              std::cout << "Anti Malware Status: " << std::setw(6) << el.value()["antiMalware"] << "\n\n";

              std::cout << "Application Control Status: " << std::setw(6) << el.value()["applicationControl"] << "\n\n";

              std::cout << "Integrity Monitoring Status: " << std::setw(6) << el.value()["integrityMonitoring"] << "\n\n";

              std::cout << "Log Inspection Status: " << std::setw(6) << el.value()["logInspection"] << "\n\n";

            }

            PONTO

          }
          
      }

      ifs.close();

    }

    else {

      puts("Something went wrong while opening the file! Try to check if the file exist or/ and is the correct path");
    }

}

// ==============----------------------------------------===================================================-----------------------------

int main(void) {

printf("What do you want to:\n" 
                          "1 - Search through the JSON file\n"
                          "2 - Read the whole file and print it in the terminal\n"
                          "3 - Check the product and Write the information in the C1SPM.json file\n"
                          "4 - Start a Scan in the product - Cloud One Conformity\n\n");

  int decision = 0;

  printf("Option: ");

  scanf("%d", &decision);

  printf("\n");

// ===============================------------------------------------------------------=========================================================

  if(decision == 1) {

        printf("Which Endpoint you searched before: \n"
                            "1 - Get Cloud Conformity Accounts\n"
                            "2 - Get Cloud Conformity All Accounts Checks\n"
                            "3 - Get Cloud Conformity List All Events\n"
                            "4 - Get Cloud One Workload Security Computers\n");

        printf("Option: ");

        short int decisionEndpointSearchJson;

        std::string field ; // This variable will store the name of the field the user wants from the Json file

        scanf("%hu", &decisionEndpointSearchJson);

        if(decisionEndpointSearchJson == 1) {
        
          std::cin.ignore();

          puts("Do you want the attributes field, or id, or relationships: ");
          getline(std::cin, field);

          findJson(field, decisionEndpointSearchJson);

        }

        else if(decisionEndpointSearchJson == 2) {

          std::cin.ignore();

          puts("Do you want the attributes field, or id, or relationships, or rule, or type: ");
          getline(std::cin, field);

          findJson(field, decisionEndpointSearchJson);
          
        }

        else if(decisionEndpointSearchJson == 3) {

          std::cin.ignore();

          puts("Do you want the attributes field, or type, or id, or relationships ");
          getline(std::cin, field);

          findJson(field, decisionEndpointSearchJson);

        }

        else if(decisionEndpointSearchJson == 4) {

          std::cin.ignore();

          puts("Do you want to know more about the computerStatus[y][n]: ");
          getline(std::cin, field);

          findJson(field, decisionEndpointSearchJson);

        }

        else {

          exit(20); // Error 20: Means that the user choose a diferente option or didn't choose nothing at all in the decisionEndpointSearchJson variable
        }



  }

  // ==========================-----------------------------------------=================================--------------------------


  else if(decision == 2) {

    readJson();
  }


// ==========================-----------------------------------------=================================--------------------------

  else if(decision == 3) {

        char *api = getenv("api"); // Will get the api variable from the system

        if(api == NULL) {

            perror("ERROR: Variables not found!!");

        }

        printf("Which Endpoint: \n"
                            "1 - Get Cloud Conformity Accounts\n"
                            "2 - Get Cloud Conformity All Accounts Checks\n"
                            "3 - Get Cloud Conformity List All Events\n"
                            "4 - Get Cloud One Workload Security Computers\n"
                            "5 - Get Cloud One Workload Security Intrusion Prevention Rules\n");

        printf("Option: ");

        short int decisionEndpoint;

        scanf("%hu", &decisionEndpoint);

          if(decisionEndpoint == 1) {

            std::cin.ignore(); // Ignores \n or the previous input that was left 

            std::string url;

            printf("What is your URL: ");
            getline(std::cin, url);

            std::string url_l = url + std::string("/v1/accounts"); // Will concatenate the variable url at the end with /v1/accounts 

            std::cout << url_l << std::endl;

            cc_get_accounts(api, url_l);

          }

          if(decisionEndpoint == 2) {

            // Tem que fazer uma concatenação de qual conta ele quer pegar os checks e muito provavelmente vai ter que fazer paginação

            std::cin.ignore(); // Ignores \n or the previous input that was left 

            std::string url;

            printf("What is your URL: ");
            getline(std::cin, url);

            std::string url_c = url + std::string("/v1/checks?accountIds=FIYGqrqnr&filter%5Bcategories%5D=security&filter%5Bstatuses%5D=FAILURE"); // Will concatenate the variable url at the end with /v1/accounts 

            std::cout << url_c << std::endl;

            cc_all_accounts_checks(api, url_c);                

          }

          if(decisionEndpoint == 3) { // Vai ter que fazer paginação

            std::cin.ignore();

            std::string url;

            printf("What is your URL: "); 
            getline(std::cin, url);

            std::string url_e = url + std::string("/v1/events"); // Will concatenate the variable url at the end with

            std::cout << url_e << std::endl;

            cc_list_all_events(api, url_e);

          }

          if(decisionEndpoint == 4) {

            std::cin.ignore();

            std::string url;

            printf("What is your URL: ");
            getline(std::cin, url);

            std::string url_ds_c = url + std::string("/computers");

            std::cout << url_ds_c << std::endl;

            ds_computers(api, url_ds_c);

          }

          if(decisionEndpoint == 5) {

            std::cin.ignore();

            std::string url;

            std::string comp;

            printf("What is your URL: ");
            getline(std::cin, url);

            printf("From which computer do you want to check the IPS rules: ");
            getline(std::cin, comp);

            std::string url_ds_ipsr = url + std::string("/computers/") + comp + std::string("/intrusionprevention/rules");

            std::cout << url_ds_ipsr << std::endl;

            ds_list_ips_rules(api, url_ds_ipsr);

          }
  }

// -----------------------------======================================---------------------===========================---------------------

          else if(decision == 4) {

          char *api = getenv("api"); // Will get the api variable from the system

          if(api == NULL) {

            perror("ERROR: Variables not found!!");

          }

            std::cin.ignore();

            std::string url;

            printf("What is your URL: ");
            getline(std::cin, url);

            std::string account;

            printf("Which account wants to start the Conformity Bot: ");
            getline(std::cin, account);

            std::string url_s = url + std::string("/v1/accounts/") + account + std::string("/scan"); 

            std::cout << url_s << std::endl;

            cc_scan_account(api, url_s);  

            printf("\n");

          }

  else {

    exit(10); // Error 10: Means that the user choose a diferente option or didn't choose nothing at all in the decisionEndpoint variable
  }

    return 0;
}