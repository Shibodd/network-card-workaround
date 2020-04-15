#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>


int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: %s devcon_exe card_hwid", argv[0]);
        return -1;
    }



    

    // Length of the command string. (3 because of "" and \0)
    size_t len = strlen(argv[1]) + strlen(argv[2]) + strlen(" restart ") + 3;

    // Make the command string from the args
    char* cmd = malloc(len * sizeof(char));
    snprintf(cmd, len, "\"%s\" restart %s", argv[1], argv[2]);

    printf("Restart command: %s\n", cmd);

    for (int i = 0; i < 7; i++) {
        printf("\nTesting the connection...\n");
        // Find returns 0 if it has found the string TTL in the ping output.
        // ping outputs TTL if and only if the connection works.
        if (!system("ping 8.8.8.8 | find \"TTL\"")) {
            free(cmd);
            return 1;
        }
            

        printf("\nThe connection doesn't work. Restarting the network card...\n");
        system(cmd);
        printf("\nWaiting..\n");
        Sleep(10000);
    }

    printf("\nFailed to get the connection working.\n");
    free(cmd);
    return 0;
}