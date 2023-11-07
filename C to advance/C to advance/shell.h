// Created on 7/11/2023 9:53PM

void shell_main() {
    char enter[10];
    char input[1024];

    while (1) {
        system("cls");
        printf("[Shell made by LIM CUAN HEI]\n");

        printf(">> ");
        gets(input);
        rewind(stdin);

        if (strcmp(input, "exit") == 0) {
            printf("\n\n[Thank you for using my shell]\n");
            break;
        }

        system(input);
        printf("\n[Press ENTER to continue]");
        gets(enter);
    }

}