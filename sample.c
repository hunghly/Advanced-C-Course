#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *rm_cm = " && input keyevent";
    char hm_cmd[strlen("hello") + strlen("world") + strlen(rm_cm)];

    sprintf(hm_cmd, "%s%s%s", "hello", "world", rm_cm);

    printf("hm_cmd is %s\n", hm_cmd);
}