# Cloud-One-Security-Posture
A simple way to see your Cloud Security Posture while using Trend Micro Cloud One!

First thing to do is to <u>export</u> your <b>ApiKey</b> as an <i>Environment Variables</i>:

    Cloud One Conformity:

    - export api="Authorization: ApiKey your_api_key_here"

    Cloud One Workload Security:

    - export api="api-secret-key: your_api_key_here"

If you have your <b>Cloud One Conformity Account Hosted</b> in <b>us-west-2</b> and want to use the <b>Cloud One Conformity Functions</b>: 
        
    - https://us-west-2-api.cloudconformity.com


If you want to use <b>Cloud One Workload Security and want use the <b>Cloud One Workload Security Functions</b>:

    - https://cloudone.trendmicro.com/api

<b>HOW TO USE:</b>

    - To compile the program:

        - make

    - To execute the program with no Arguments:

        - make execute
    
    - To delete the executable:

        - make delete
    
    - To debug the connection, first run:

        - make debug
        
        And then run the program!

    - To see which Environment Variables exist in your session:

        - make env-var


<b>HOW TO USE: List of available functions for now: </b>

        - Get Cloud Conformity Accounts

        Function Description: This function allows you to query all accounts that you have access to and see their Account ID.

        - Get Cloud Conformity All Accounts Checks

        Function Description: This function will bring from all accounts that you have access to, checks that are only FAILURE AND SECURITY related.

        - Get Cloud Conformity List All Events

        Function Description: This function allows you to collect events that you have access to.

        - Get All Cloud One Workload Security Computers

        Function Description: List all computers

        - Get The List of Intrusion Prevention Rules on a Computer

        Function Description: List the Intrusion Prevention Rules Applied on a Computer


You can if you want, after the program run, unset the Environment Variables:

    - unset api

For more information about the API for <b>Trend Micro Cloud One Workload Security</b>, <b>Smart Check</b> and <b>Cloud Conformity</b>:

    - Cloud One Workload Security API: https://cloudone.trendmicro.com/docs/workload-security/api-reference/

    - Cloud Conformity API Documentation: https://cloudone.trendmicro.com/docs/conformity/api-reference/ 

    - Smart Check API Reference: https://cloudone.trendmicro.com/docs/container-security/sc-api/


<b>WARNING:</b>

        - This project/ files are only for DEMO purpose!!


<i>If you want to contribute, feel free to do so!</i>