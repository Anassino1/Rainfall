int main() {
    v();
    return 0;
}

void v() {
    char buffer[520];

    fgets(buffer, 512, stdin);

    printf(buffer);  // Vulnerable

    if (*(int*)0x804988c == 64) {
        write(1, secret_string, 12);
    }
}

void v() {
    char buffer[520];

    fgets(buffer, 512, stdin);
    printf(buffer);

    if (m == 64) {
        printf("Wait what?!\n");
        system("/bin/sh");
    }
}