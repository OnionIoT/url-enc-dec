#include "curl/curl.h"

void printUsage (char *progName) {
        printf ("Functionality:\n");
        printf ("Decode URL encoded strings\n\n");
        printf ("Usage:\n");
        printf ("%s <URL encoded string>\n", progName);
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
                       output = curl_easy_unescape(curl, argv[1], 0, &len);
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
