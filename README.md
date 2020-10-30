# Cloud-One-Security-Posture
A simple way to see your Cloud Security Posture  while using Trend Micro Cloud One!

First thing to do is to <u>export</u> your <b>ApiKey</b> and the <b>URL</b> as an <i>Environment Variables</i>:

    - export api="Authorization: ApiKey your_api_key"

    - export url="https://your-region-api.cloudconformity.com/v1/endpoint_that_you_want_to_use"


For example, if you have your <b>Cloud Conformity Account Hosted</b> in <b>us-west-2</b> and want to use the <b>list_accounts function</b>: 
        
    - export url="https://us-west-2-api.cloudconformity.com/v1/accounts"


<b>HOW TO USE:</b>

    - To compile the program:

        - make

    - To execute the program with no Arguments:

        - make execute
    
    - To delete the executable:

        - make delete
    
    - To debug the connection:

        - make debug

    - To see which Environment Variables existe in your session:

        - make env-var


<b>HOW TO USE: List of available functions for now: </b>

    If you want to LIST_ALL_CLOUD_CONFORMITY_ACCOUNTS:

        - make list_accounts

        Function Description: This function allows you to query all accounts that you have access to and see their Account ID.


You can if you want, after the program run, unset the Environment Variables:

    - unset api

    - unset url


For more information about the API for Cloud One Workload Security, Smart Check and Cloud Conformity:

    - Cloud One Workload Security API: https://cloudone.trendmicro.com/docs/workload-security/api-reference/

    - Cloud Conformity API Documentation: https://github.com/cloudconformity/documentation-api 

    - Smart Check API Reference: https://cloudone.trendmicro.com/docs/container-security/sc-api/


<b>WARNING:</b>

        - This project/ files are only for DEMO purpose!!


<i>If you want to contribute, feel free to do so!</i>