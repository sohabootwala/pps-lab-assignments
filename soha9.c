#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourceName[100], destName[100];
    char ch;

    printf("Enter the source filename to read from: ");
    scanf("%s", sourceName);

    // Open source file in read mode ("r")
    sourceFile = fopen(sourceName, "r");
    if (sourceFile == NULL) {
        printf("Error: Cannot open source file %s\n", sourceName);
        exit(1);
    }

    printf("Enter the destination filename to write into: ");
    scanf("%s", destName);

    // Open destination file in write mode ("w")
    destFile = fopen(destName, "w");
    if (destFile == NULL) {
        printf("Error: Cannot open destination file %s\n", destName);
        fclose(sourceFile);
        exit(1);
    }

    // Read character by character until End Of File (EOF) and write to destination
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("\nFile contents copied successfully from %s to %s!\n", sourceName, destName);

    // Close both files
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
