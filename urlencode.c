#include "curl/curl.h"

void printUsage (char *progName) {
        printf ("Functionality:\n");
        printf ("URL encode a string\n\n");
        printf ("Usage:\n");
        printf ("%s <string to encode>\n", progName);
}

int main (int argc, char *argv[]) {
        CURL *curl;
        char *output;
        int len;
        
        if (argc != 2) {
                printUsage(argv[0]);
        } else {
                curl = curl_easy_init();
                if(curl) {
                       output = curl_easy_escape(curl, argv[1], 0);
                       if (output) {
                            printf("%s\n", output);
                       }
                }
                // clean-up
                curl_free(output);
                curl_easy_cleanup(curl);
        }
        
        return 0;
}
