#ifndef _UTILS_H_
#pragma warning(disable: 4996)
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static char *getline(FILE *stream) {
	int c, i = 0, linebufsz = 0, growby = 80;
	char *linebuf = NULL;

	while (1) {
		c = fgetc(stream);
		if (c == EOF) break;
		while (i > linebufsz - 2)
			linebuf = (char*)realloc(linebuf, linebufsz += growby);
		linebuf[i++] = (char)c;
		if (c == '\n' || c == '\0') break;
	}
	if (i == 0) return NULL;
	linebuf[i] = 0;
	return linebuf;
}

static void chomp(char *str) {
	unsigned int len = strlen(str);
	if (str[len - 1] == '\n') str[len - 1] = '\0';
	return;
}

static int find_label(char *name, FILE *f) {

	//return find_label2(name, f);

	char *tok, *line;
	char *inst[3] = { 0, 0, 0 };
	int i = 0;
	int count = 0;
	double cnt = 0.0;

	while ((line = getline(f)) != NULL) {
		chomp(line);

		//printf("%s\n", line);

		if (line[0] == ';' || strlen(line) == 0) continue;

		tok = strtok(strdup(line), ":, ");

		while (tok != NULL) {
			if (i == 3) {
				//
				break;
			}
			inst[i] = tok;
			tok = strtok(NULL, ":, ");



			//printf("%d: %.1f  %s %s %s\n", i, cnt, inst[0], inst[1], inst[2]);

			//printf("c0: %d\n", count);

			count += (int)ceil(cnt / 2.0);
			//printf("c: %d\n", count);
			
			cnt = 0.0;
			i++;
		}
		
		if (inst[0] != 0) cnt++;
		if (inst[1] != 0) cnt++;
		if (inst[2] != 0) cnt++;
		
		if (strcmp(inst[0], name) == 0) break;

		inst[0] = 0;
		inst[1] = 0;
		inst[2] = 0;
		i = 0;
	}

	return count;
	//return (int)(ceil(count / 2));
}

#endif