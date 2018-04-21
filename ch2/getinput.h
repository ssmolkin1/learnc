/* Takes the first word (string separated by a single space, tab or newline character) from input and stores it in output array */
char get_word(char output[], int size_limit) {
    char c;
    int i;

    for (i = 0; i < size_limit && (c = getchar()) != EOF && c != ' ' && c!= '\n' && c!= '\t'; i++) {
       output[i] = c; 
    }

    output[i] = '\0';

    /* Progresses c to start of next word in case truncated due to size_limit */
    while (c != ' ' && c != '\n' && c != '\t' && c != EOF) {
        c = getchar();
    }
}

char get_line(char output[], int size_limit) {
    char c;
    int i;

    for (i = 0; i < size_limit && (c = getchar()) != EOF && c!= '\n'; i++) {
       output[i] = c; 
    }

    output[i] = '\0';

    /* Progresses c to start of next line in case truncated due to size_limit */
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}
