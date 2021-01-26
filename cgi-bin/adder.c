/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "csapp.h"

int main(void) {
    char *buf, *p, *p1;
    char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
    int n1=0, n2=0;

    /* Extract the two arguments */
    if ((buf = getenv("QUERY_STRING")) != NULL) {
	p = strchr(buf, '&');
	*p = '\0';
	strcpy(arg1, buf);
	p1 = strchr(arg1, '=');
	strcpy(arg1, p1+1);
	strcpy(arg2, p+1);
	p1 = strchr(arg2, '=');
	strcpy(arg2, p1+1);
	printf("\n\n\n\narg1:%s\n\n\n\n", arg1);
	printf("\n\n\n\narg2:%s\n\n\n\n", arg2);
	n1 = atoi(arg1);
	n2 = atoi(arg2);
	
    }

    /* Make the response body */

    sprintf(content, "QUERY_STRING=%s", buf);
    sprintf(content, "%sWelcome to add.com: \n", content);
    sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
    sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>", 
	    content, n1, n2, n1 + n2);
  
    /* Generate the HTTP response */
    printf("Connection: close\r\n");
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);

    exit(0);
}
/* $end adder */
