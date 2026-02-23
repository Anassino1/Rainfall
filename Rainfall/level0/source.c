#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    // Convert argv[1] (first argument) to integer
    int input = atoi(argv[1]);

    // Compare input with 423 (0x1a7)
    if (input != 423) {
        // Jump to failure path
        printf("No!\n");
        return 1;
    }

    // Success path
    // Duplicate a string located at memory 0x80c5348
    // In real C, it would be some constant string in .rodata
    char *secret_string = strdup("some_string_here");

    // Prepare values (likely for privilege escalation)
    gid_t egid = getegid(); // effective group ID
    uid_t euid = geteuid(); // effective user ID

    // Possibly preparing to call a function like setresuid/setresgid
    gid_t saved_gid = egid;
    // ...rest of code would use egid/euid in syscalls

    // At this point, execution continues
    printf("Success! Input was correct.\n");

    // Free allocated memory before exit
    free(secret_string);

    return 0;
}