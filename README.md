# Cloud-One-Security-Posture
A simple way to see your Cloud Security Posture while using Trend Micro Cloud One!

First thing to do is to <u>export</u> your <b>ApiKey</b> as an <i>Environment Variables</i>:

    - export api="Authorization: ApiKey your_api_key"


For example, if you have your <b>Cloud Conformity Account Hosted</b> in <b>us-west-2</b> and want to use the <b>Get Cloud Conformity Accounts function</b>: 
        
    - "https://us-west-2-api.cloudconformity.com"


<b>HOW TO USE:</b>

    - To compile the program:

        - make

    - To execute the program with no Arguments:

        - make execute
    
    - To delete the executable:

        - make delete
    
    - To debug the connection, first run:

        - make debug
        
        And then run the program with the argument that you want to use!

    - To see which Environment Variables exist in your session:

        - make env-var


<b>HOW TO USE: List of available functions for now: </b>

    If you want to LIST_ALL_CLOUD_CONFORMITY_ACCOUNTS:

        - Get Cloud Conformity Accounts

        Function Description: This function allows you to query all accounts that you have access to and see their Account ID.

        - make Get Cloud Conformity All Accounts Checks

        Function Description: This function will bring from all accounts that you have access to, checks that are only FAILURE AND SECURITY related.

        - make Get Cloud Conformity List All Events

        Function Description: This endpoint allows you to collect events that you have access to.


You can if you want, after the program run, unset the Environment Variables:

    - unset api

For more information about the API for <b>Trend Micro Cloud One Workload Security</b>, <b>Smart Check</b> and <b>Cloud Conformity</b>:

    - Cloud One Workload Security API: https://cloudone.trendmicro.com/docs/workload-security/api-reference/

    - Cloud Conformity API Documentation: https://cloudone.trendmicro.com/docs/conformity/api-reference/ 

    - Smart Check API Reference: https://cloudone.trendmicro.com/docs/container-security/sc-api/


<b>WARNING:</b>

        - This project/ files are only for DEMO purpose!!


<i>If you want to contribute, feel free to do so!</i>